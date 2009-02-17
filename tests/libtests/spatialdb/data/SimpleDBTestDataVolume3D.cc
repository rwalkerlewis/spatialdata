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

// DO NOT EDIT THIS FILE
// This file was generated from python application simpledbdatavolume3D.

#include "SimpleDBTestDataVolume3D.hh"

const int spatialdata::spatialdb::SimpleDBTestDataVolume3D::_numLocs = 8;

const int spatialdata::spatialdb::SimpleDBTestDataVolume3D::_spaceDim = 3;

const int spatialdata::spatialdb::SimpleDBTestDataVolume3D::_numVals = 2;

const int spatialdata::spatialdb::SimpleDBTestDataVolume3D::_dataDim = 3;

const int spatialdata::spatialdb::SimpleDBTestDataVolume3D::_numQueries = 5;

const double spatialdata::spatialdb::SimpleDBTestDataVolume3D::_dbCoords[] = {
  4.46656933e+00,  8.13917840e+00,  8.80292932e+00,
  2.67771495e+00,  8.13917840e+00,  7.90850213e+00,
  4.90300511e+00,  9.88492152e+00,  7.93005776e+00,
  3.11415073e+00,  9.88492152e+00,  7.03563057e+00,
  3.68584927e+00,  9.11507848e+00,  1.03643694e+01,
  1.89699489e+00,  9.11507848e+00,  9.46994224e+00,
  4.12228505e+00,  1.08608216e+01,  9.49149787e+00,
  2.33343067e+00,  1.08608216e+01,  8.59707068e+00,
};

const double spatialdata::spatialdb::SimpleDBTestDataVolume3D::_dbData[] = {
  1.00000000e-01,  1.10000000e+00,
  3.00000000e-01,  3.30000000e+00,
  2.00000000e-01,  2.20000000e+00,
  1.00000000e-01,  1.10000000e+00,
  4.00000000e-01,  4.60000000e+00,
  3.00000000e-01,  3.20000000e+00,
  7.00000000e-01,  5.20000000e+00,
  5.00000000e-01,  4.60000000e+00,
};

const char* spatialdata::spatialdb::SimpleDBTestDataVolume3D::_names[] = {
"One",
"Two",
};

const char* spatialdata::spatialdb::SimpleDBTestDataVolume3D::_units[] = {
"m",
"m",
};

const double spatialdata::spatialdb::SimpleDBTestDataVolume3D::_queryNearest[] = {
  4.38173419e+00,  8.36254772e+00,  8.74899281e+00,  1.00000000e-01,  1.10000000e+00,
  2.35495601e+00,  1.00264422e+01,  9.00123360e+00,  5.00000000e-01,  4.60000000e+00,
  3.91112675e+00,  1.07838373e+01,  9.69020768e+00,  7.00000000e-01,  5.20000000e+00,
  3.87701461e+00,  1.04910673e+01,  9.08761157e+00,  7.00000000e-01,  5.20000000e+00,
  3.01795532e+00,  8.84019490e+00,  8.79326896e+00,  3.00000000e-01,  3.30000000e+00,
};

const double spatialdata::spatialdb::SimpleDBTestDataVolume3D::_queryLinear[] = {
  4.38173419e+00,  8.36254772e+00,  8.74899281e+00,  1.35000000e-01,  1.49500000e+00,
  2.35495601e+00,  1.00264422e+01,  9.00123360e+00,  4.10000000e-01,  3.85500000e+00,
  3.91112675e+00,  1.07838373e+01,  9.69020768e+00,  0.00000000e+00,  0.00000000e+00,
  3.87701461e+00,  1.04910673e+01,  9.08761157e+00,  5.30000000e-01,  4.42000000e+00,
  3.01795532e+00,  8.84019490e+00,  8.79326896e+00,  2.00000000e-01,  2.15500000e+00,
};

const int spatialdata::spatialdb::SimpleDBTestDataVolume3D::_errFlags[] = {
 0, 0, 1, 0, 0,};

spatialdata::spatialdb::SimpleDBTestDataVolume3D::SimpleDBTestDataVolume3D(void)
{ // constructor
  numLocs = _numLocs;
  spaceDim = _spaceDim;
  numVals = _numVals;
  dataDim = _dataDim;
  numQueries = _numQueries;
  dbCoords = const_cast<double*>(_dbCoords);
  dbData = const_cast<double*>(_dbData);
  names = const_cast<char**>(_names);
  units = const_cast<char**>(_units);
  queryNearest = const_cast<double*>(_queryNearest);
  queryLinear = const_cast<double*>(_queryLinear);
  errFlags = const_cast<int*>(_errFlags);
} // constructor

spatialdata::spatialdb::SimpleDBTestDataVolume3D::~SimpleDBTestDataVolume3D(void)
{}


// End of file