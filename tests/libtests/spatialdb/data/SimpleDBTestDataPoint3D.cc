// -*- C++ -*-
//
// ----------------------------------------------------------------------
//
// Brad T. Aagaard, U.S. Geological Survey
//
// This code was developed as part of the Computational Infrastructure
// for Geodynamics (http://geodynamics.org).
//
// Copyright (c) 2010 University of California, Davis
//
// See COPYING for license information.
//
// ----------------------------------------------------------------------
//

// DO NOT EDIT THIS FILE
// This file was generated from python application simpledbdatapoint.

#include "SimpleDBTestDataPoint3D.hh"

const int spatialdata::spatialdb::SimpleDBTestDataPoint3D::_numLocs = 1;

const int spatialdata::spatialdb::SimpleDBTestDataPoint3D::_spaceDim = 3;

const int spatialdata::spatialdb::SimpleDBTestDataPoint3D::_numVals = 2;

const int spatialdata::spatialdb::SimpleDBTestDataPoint3D::_dataDim = 0;

const int spatialdata::spatialdb::SimpleDBTestDataPoint3D::_numQueries = 3;

const double spatialdata::spatialdb::SimpleDBTestDataPoint3D::_dbCoords[] = {
  1.00000000e-01,  2.00000000e-01,  3.00000000e-01,
};

const double spatialdata::spatialdb::SimpleDBTestDataPoint3D::_dbData[] = {
  6.30000000e+00,  7.40000000e+00,
};

const char* spatialdata::spatialdb::SimpleDBTestDataPoint3D::_names[] = {
"One",
"Two",
};

const char* spatialdata::spatialdb::SimpleDBTestDataPoint3D::_units[] = {
"m",
"m",
};

const double spatialdata::spatialdb::SimpleDBTestDataPoint3D::_queryNearest[] = {
  4.50000000e+00,  2.30000000e+00,  4.00000000e+00,  6.30000000e+00,  7.40000000e+00,
  3.20000000e+00,  7.40000000e+00,  5.80000000e+00,  6.30000000e+00,  7.40000000e+00,
  4.00000000e+00,  9.80000000e+00,  5.70000000e+00,  6.30000000e+00,  7.40000000e+00,
};

const double spatialdata::spatialdb::SimpleDBTestDataPoint3D::_queryLinear[] = {
  2.90000000e+00,  3.40000000e+00,  8.70000000e+00,  6.30000000e+00,  7.40000000e+00,
  2.20000000e+00,  9.00000000e+00,  8.50000000e+00,  6.30000000e+00,  7.40000000e+00,
  2.00000000e-01,  5.80000000e+00,  6.60000000e+00,  6.30000000e+00,  7.40000000e+00,
};

const int spatialdata::spatialdb::SimpleDBTestDataPoint3D::_errFlags[] = {
 0, 0, 0,};

spatialdata::spatialdb::SimpleDBTestDataPoint3D::SimpleDBTestDataPoint3D(void)
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

spatialdata::spatialdb::SimpleDBTestDataPoint3D::~SimpleDBTestDataPoint3D(void)
{}


// End of file
