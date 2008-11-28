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

#include <portinfo>

#include "Nondimensional.hh" // implementation of class methods

#include <sstream> // USES std::ostringstream
#include <stdexcept> // USES std::runtime_error
#include <assert.h> // USES assert()

// ----------------------------------------------------------------------
// Default constructor
spatialdata::units::Nondimensional::Nondimensional(void) :
  _length(1.0),
  _pressure(1.0),
  _time(1.0),
  _density(1.0)
{ // constructor
} // constructor

// ----------------------------------------------------------------------
// Default destructor
spatialdata::units::Nondimensional::~Nondimensional(void)
{ // destructor
} // destructor

// ----------------------------------------------------------------------
// Copy constructor.
spatialdata::units::Nondimensional::Nondimensional(const Nondimensional& dim) :
  _length(dim._length),
  _pressure(dim._pressure),
  _time(dim._time),
  _density(dim._density)
{ // copy constructor
} // copy constructor

// ----------------------------------------------------------------------
// Assignment operator.
const spatialdata::units::Nondimensional& 
spatialdata::units::Nondimensional::operator=(const Nondimensional& dim)
{ // operator=
  if (this != &dim) {
    _length = dim._length;
    _pressure = dim._pressure;
    _time = dim._time;
    _density = dim._density;
  } // if

  return *this;
} // operator=

// ----------------------------------------------------------------------
// Set value to nondimensionalize length scale in meters (SI units).
void
spatialdata::units::Nondimensional::lengthScale(const double value)
{ // lengthScale
  if (value <= 0.0) {
    std::ostringstream msg;
    msg << "Length scale (" << value << ") must be positive.";
    throw std::runtime_error(msg.str());
  } // if
  _length = value;
} // lengthScale

// ----------------------------------------------------------------------
// Set value to nondimensionalize pressure scale in Pascals (SI units).
void
spatialdata::units::Nondimensional::pressureScale(const double value)
{ // pressureScale
  if (value <= 0.0) {
    std::ostringstream msg;
    msg << "Pressure scale (" << value << ") must be positive.";
    throw std::runtime_error(msg.str());
  } // if
  _pressure = value;
} // pressureScale

// ----------------------------------------------------------------------
// Set value to nondimensionalize time scale in seconds (SI units).
void
spatialdata::units::Nondimensional::timeScale(const double value)
{ // timeScale
  if (value <= 0.0) {
    std::ostringstream msg;
    msg << "Time scale (" << value << ") must be positive.";
    throw std::runtime_error(msg.str());
  } // if
  _time = value;
} // timeScale

// ----------------------------------------------------------------------
// Set value to nondimensionalize density scale in kg/m^3 (SI units).
void
spatialdata::units::Nondimensional::densityScale(const double value)
{ // densityScale
  if (value <= 0.0) {
    std::ostringstream msg;
    msg << "Density scale (" << value << ") must be positive.";
    throw std::runtime_error(msg.str());
  } // if
  _density = value;
} // densityScale

// ----------------------------------------------------------------------
// Make values dimensionless.
void
spatialdata::units::Nondimensional::nondimensionalize(double* const values,
						      const int nvalues,
						      const double scale) const
{ // nondimensionalize
  assert( (0 < nvalues && 0 != values) ||
	  (0 == nvalues && 0 == values) );

  for (int i=0; i < nvalues; ++i)
    values[i] /= scale;
} // nondimensionalize

// ----------------------------------------------------------------------
// Make value dimensionless.
void
spatialdata::units::Nondimensional::dimensionalize(double* const values,
						   const int nvalues,
						   const double scale) const
{ // dimensionalize
  assert( (0 < nvalues && 0 != values) ||
	  (0 == nvalues && 0 == values) );

  for (int i=0; i < nvalues; ++i)
    values[i] *= scale;
} // dimensionalize



// End of file 