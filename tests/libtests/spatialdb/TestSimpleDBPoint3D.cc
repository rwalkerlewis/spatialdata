// -*- C++ -*-
//
// ----------------------------------------------------------------------
//
//                           Brad T. Aagaard
//                        U.S. Geological Survey
//
// {LicenseText}
//
// ----------------------------------------------------------------------
//

#include <portinfo>

#include "TestSimpleDBPoint3D.hh" // Implementation of class methods

#include "data/SimpleDBDataPoint3D.hh"

// ----------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( spatialdata::spatialdb::TestSimpleDBPoint3D );

// ----------------------------------------------------------------------
// Test queryLinear()
void
spatialdata::spatialdb::TestSimpleDBPoint3D::testQueryLinear(void)
{ // testQueryLinear
  SimpleDBDataPoint3D data;

  _testQueryLinear(data);
} // testQueryLinear

// ----------------------------------------------------------------------
// Test queryNearest()
void
spatialdata::spatialdb::TestSimpleDBPoint3D::testQueryNearest(void)
{ // testQueryNearest
  SimpleDBDataPoint3D data;

  _testQueryNearest(data);
} // testQueryNearest


// End of file 