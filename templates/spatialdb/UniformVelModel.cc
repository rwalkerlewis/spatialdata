// -*- C++ -*-
//
// ======================================================================
//
//                           Brad T. Aagaard
//                        U.S. Geological Survey
//
// {LicenseText}
//
// ======================================================================
//

#include <portinfo> // machine specific info generated by configure

#include "UniformVelModel.hh" // Implementation of class methods

#include "spatialdata/geocoords/CSGeoProj.hh" // USES CSGeoProj
#include "spatialdata/geocoords/Projector.hh" // USES Projector
#include "spatialdata/geocoords/Converter.hh" // USES Converter

#include <strings.h> // USES strcasecmp()
#include <cassert> // USES assert()
#include <sstream> // USES std::ostringstream
#include <stdexcept> // USES std::runtime_error, std::logic_error

// ----------------------------------------------------------------------
// Constructor
contrib::spatialdb::UniformVelModel::UniformVelModel(void) :
  spatialdata::spatialdb::SpatialDB("Velocity model with uniform properties"),
  _vp(0),
  _vs(0),
  _density(0),
  _cs(0),
  _queryVals(0),
  _querySize(0)
{ // constructor
} // constructor

// ----------------------------------------------------------------------
// Destructor
contrib::spatialdb::UniformVelModel::~UniformVelModel(void)
{ // destructor
  // Deallocate all data
  delete _cs; _cs = 0;

  delete[] _queryVals; _queryVals = 0;
  _querySize = 0;
} // destructor

// ----------------------------------------------------------------------
// Open the database and prepare for querying.
void
contrib::spatialdb::UniformVelModel::open(void)
{ // open
  // Setup the velocity model and do any necessary pre-query stuff.

  // Make sure the physical properties have been set.
  if (0 == _vs) {
    std::ostringstream msg;
    msg << "S wave speed has not been set for spatial database "
	<< label() << ".";
    throw std::runtime_error(msg.str());
  } // if
  if (0 == _vp) {
    std::ostringstream msg;
    msg << "P wave speed has not been set for spatial database "
	<< label() << ".";
    throw std::runtime_error(msg.str());
  } // if
  if (0 == _density) {
    std::ostringstream msg;
    msg << "Density has not been set for spatial database "
	<< label() << ".";
    throw std::runtime_error(msg.str());
  } // if

  // Set up geographic projected coordinate system. In this case we
  // use UTM coordinates is zone 10 with the NAD27 horizontal datum
  // and mean sea level for the vertical datum.
  spatialdata::geocoords::Projector proj;
  proj.projection("utm");
  proj.units("m");
  proj.projOptions("+zone=10");

  // Create a new coordinate system object (first deleting the old one
  // if it exists).
  delete _cs; _cs = new spatialdata::geocoords::CSGeoProj;

  // Set parameters for the coordinate system.
  _cs->datumHoriz("NAD27");
  _cs->datumVert("mean sea level");
  _cs->ellipsoid("clrk66");
  _cs->projector(proj);
  _cs->initialize();
} // open

// ----------------------------------------------------------------------
// Close the database.
void
contrib::spatialdb::UniformVelModel::close(void)
{ // close
  // Deallocate all data allocated in open() and query().

  // Deallocate coordinate system object and set to null so that
  // subsequent calls to delete won't try to dellocate memory that has
  // already been deallocated.
  delete _cs; _cs = 0;
} // close

// ----------------------------------------------------------------------
// Set values to be returned by queries.
void
contrib::spatialdb::UniformVelModel::queryVals(const char* const* names,
					       const int numVals)
{ // queryVals
  // Check function arguments.
  if (0 >= numVals) {
    std::ostringstream msg;
    msg << "Number of values for query in spatial database " << label()
	<< "\n must be positive.\n";
    throw std::runtime_error(msg.str());
  } // if
  assert(0 != names && 0 < numVals);
  
  // Store the query size.
  _querySize = numVals;

  // Allocate the array to store the flags for the queries (first
  // dellocating the array if necessary).
  delete[] _queryVals; _queryVals = (numVals > 0) ? new int[numVals] : 0;

  // Set the values in the array of values to include in queries.
  for (int iVal=0; iVal < numVals; ++iVal) {
    // Set the values to be returned in a query.
    if (0 == strcasecmp(names[iVal], "vp"))
      _queryVals[iVal] = QUERY_VP;
    else if (0 == strcasecmp(names[iVal], "vs"))
      _queryVals[iVal] = QUERY_VS;
    else if (0 == strcasecmp(names[iVal], "density"))
      _queryVals[iVal] = QUERY_DENSITY;
    else {
      std::ostringstream msg;
      msg << "Could not find value " << names[iVal] << " in spatial database\n"
	  << label() << ". Available values are:\n"
	  << "vp, vs, and density.";
      throw std::runtime_error(msg.str());
    } // else
  } // for
} // queryVals

// ----------------------------------------------------------------------
// Query the database.
int
contrib::spatialdb::UniformVelModel::query(double* vals,
					   const int numVals,
					   const double* coords,
					   const int numDims,
					   const spatialdata::geocoords::CoordSys* csQuery)
{ // query
  // Make sure we are setup to perform a query and check to make sure
  // that the number of values expected to be returned in the query
  // (as specified in the arguments) matches the size of queries
  // specified in the more recent call to queryVals().
  if (0 == _querySize) {
    std::ostringstream msg;
    msg << "Values to be returned by spatial database " << label() << "\n"
	<< "have not been set. Please call queryVals() before query().\n";
    throw std::runtime_error(msg.str());
  } // if
  if (numVals != _querySize) {
    std::ostringstream msg;
    msg << "Number of values to be returned by spatial database "
	<< label() << "\n"
	<< "(" << _querySize << ") does not match size of array provided ("
	<< numVals << ").\n";
    throw std::runtime_error(msg.str());
  } // if
  const int spaceDim = csQuery->spaceDim();
  if (2 != spaceDim || 3 != spaceDim) {
    std::ostringstream msg;
    msg << "Spatial dimension of coordinate system for query location must have "
	<< "2 or 3 spatial dimensions while querying uniform velocity model "
	<< "database " << label() << ".\n";
    throw std::runtime_error(msg.str());
  } // if
    
  // Convert coordinates to local coordinate system. Not useful for
  // this trivial seismic velocity model but will be necessary in most
  // cases.
  _xyz[0] = 0.0;
  _xyz[1] = 0.0;
  _xyz[2] = 0.0;
  for (int i=0; i < spaceDim; ++i)
    _xyz[i] = coords[i];
  spatialdata::geocoords::Converter::convert(_xyz, 1, spaceDim, _cs, csQuery);

  // Perform query operation
  int queryFlag = 0;
  for (int i=0; i < _querySize; ++i) {
    switch (_queryVals[i]) {
    case QUERY_VP:
      vals[i] = _vp;
      break;
    case QUERY_VS:
      vals[i] = _vs;
      break;
    case QUERY_DENSITY:
      vals[i] = _density;
      break;
    default :
      throw std::logic_error("Unknown query value.");
    } // switch
  } // for
  
  return queryFlag;
} // query

// ----------------------------------------------------------------------
// Set the P wave speed.
void
contrib::spatialdb::UniformVelModel::vp(const double value)
{ // vp
  if (value <= 0.0) {
    std::ostringstream msg;
    msg << "P wave speed must be positive for uniform velocity model "
	<< "database " << label() << ".\n";
    throw std::runtime_error(msg.str());
  } // if

  _vp = value;
} // vp

// ----------------------------------------------------------------------
// Set the S wave speed.
void
contrib::spatialdb::UniformVelModel::vs(const double value)
{ // vs
  if (value <= 0.0) {
    std::ostringstream msg;
    msg << "S wave speed must be positive for uniform velocity model "
	<< "database " << label() << ".\n";
    throw std::runtime_error(msg.str());
  } // if

  _vs = value;
} // vs

// ----------------------------------------------------------------------
// Set the density.
void
contrib::spatialdb::UniformVelModel::density(const double value)
{ // density
  if (value <= 0.0) {
    std::ostringstream msg;
    msg << "Densiy must be positive for uniform velocity model database "
	<< label() << ".\n";
    throw std::runtime_error(msg.str());
  } // if

  _density = value;
} // density
 

// End of file
