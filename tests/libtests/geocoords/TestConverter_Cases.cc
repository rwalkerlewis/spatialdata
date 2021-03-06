// -*- C++ -*-
//
// ----------------------------------------------------------------------
//
// Brad T. Aagaard, U.S. Geological Survey
//
// This code was developed as part of the Computational Infrastructure
// for Geodynamics (http://geodynamics.org).
//
// Copyright (c) 2010-2017 University of California, Davis
//
// See COPYING for license information.
//
// ----------------------------------------------------------------------
//

#include <portinfo>

#include "TestConverter.hh" // Implementation of class methods

#include "spatialdata/geocoords/CSCart.hh" // USES CSCart
#include "spatialdata/geocoords/CSGeo.hh" // USES CSGeo

namespace spatialdata {
    namespace geocoords {
        class TestConverter_NAD27ToWGS84;
        class TestConverter_WGS84ToNAD27;
        class TestConverter_WGS84ToECEF;
        class TestConverter_XYZToXYZ;
        class TestConverter_units;
    } // geocoords
} // spatialdata

// ---------------------------------------------------------------------------------------------------------------------
class spatialdata::geocoords::TestConverter_NAD27ToWGS84 : public spatialdata::geocoords::TestConverter {
    CPPUNIT_TEST_SUB_SUITE(TestConverter_NAD27ToWGS84, TestConverter);
    CPPUNIT_TEST_SUITE_END();

    void setUp(void) {
        TestConverter::setUp();

        CPPUNIT_ASSERT(_data);
        _data->numPoints = 6;
        _data->spaceDim = 3;

        static CSGeo csNAD27;
        csNAD27.setString("+proj=longlat +datum=NAD27");
        csNAD27.setSpaceDim(_data->spaceDim);
        _data->csSrc = &csNAD27;

        static CSGeo csWGS84;
        csWGS84.setString("+proj=longlat +datum=WGS84");
        csWGS84.setSpaceDim(_data->spaceDim);
        _data->csDest = &csWGS84;

        static const double coordsLonLatNAD27[6*3] = {
            -1.150000000000e+02,  3.900000000000e+01,  1.200000000000e+01,
            -1.203425320000e+02,  4.323423000000e+01,  1.010000000000e+01,
            -1.213425320000e+02,  4.523423000000e+01,  3.600000000000e+00,
            -1.153425320000e+02,  3.623423000000e+01,  7.200000000000e+00,
            -1.103425320000e+02,  3.923423000000e+01,  1.233000000000e+02,
            -1.073425320000e+02,  3.323423000000e+01,  3.460000000000e+01,
        };
        _data->coordsSrc = coordsLonLatNAD27;

        static const double coordsLonLatWGS84[6*3] = {
            -1.150008507633e+02,  3.899994227695e+01,  1.200000018017e+01,
            -1.203436181122e+02,  4.323409740913e+01,  1.010000021373e+01,
            -1.213437106276e+02,  4.523406963911e+01,  3.600000226768e+00,
            -1.153433730158e+02,  3.623419630177e+01,  7.200000158508e+00,
            -1.103432442395e+02,  3.923419970866e+01,  1.233000001811e+02,
            -1.073431211987e+02,  3.323430190358e+01,  3.460000013495e+01,
        };
        _data->coordsDest = coordsLonLatWGS84;

    } // setUp

}; // TestConverter_NAD27ToWGS84
CPPUNIT_TEST_SUITE_REGISTRATION(spatialdata::geocoords::TestConverter_NAD27ToWGS84);

// ---------------------------------------------------------------------------------------------------------------------
class spatialdata::geocoords::TestConverter_WGS84ToNAD27 : public spatialdata::geocoords::TestConverter {
    CPPUNIT_TEST_SUB_SUITE(TestConverter_WGS84ToNAD27, TestConverter);
    CPPUNIT_TEST_SUITE_END();

    void setUp(void) {
        TestConverter::setUp();

        CPPUNIT_ASSERT(_data);
        _data->numPoints = 6;
        _data->spaceDim = 3;

        static CSGeo csWGS84;
        csWGS84.setString("+proj=longlat +datum=WGS84");
        csWGS84.setSpaceDim(_data->spaceDim);
        _data->csSrc = &csWGS84;

        static CSGeo csNAD27;
        csNAD27.setString("EPSG:4267"); // NAD27, latitude/longitude
        csNAD27.setSpaceDim(_data->spaceDim);
        _data->csDest = &csNAD27;

        static const double coordsLonLatWGS84[6*3] = {
            -1.150008507633e+02,  3.899994227695e+01,  1.200000018017e+01,
            -1.203436181122e+02,  4.323409740913e+01,  1.010000021373e+01,
            -1.213437106276e+02,  4.523406963911e+01,  3.600000226768e+00,
            -1.153433730158e+02,  3.623419630177e+01,  7.200000158508e+00,
            -1.103432442395e+02,  3.923419970866e+01,  1.233000001811e+02,
            -1.073431211987e+02,  3.323430190358e+01,  3.460000013495e+01,
        };
        _data->coordsSrc = coordsLonLatWGS84;

        static const double coordsLatLonNAD27[6*3] = {
            3.900000000000e+01,  -1.150000000000e+02,  1.200000000000e+01,
            4.323423000000e+01,  -1.203425320000e+02,  1.010000000000e+01,
            4.523423000000e+01,  -1.213425320000e+02,  3.600000000000e+00,
            3.623423000000e+01,  -1.153425320000e+02,  7.200000000000e+00,
            3.923423000000e+01,  -1.103425320000e+02,  1.233000000000e+02,
            3.323423000000e+01,  -1.073425320000e+02,  3.460000000000e+01,
        };
        _data->coordsDest = coordsLatLonNAD27;

    } // setUp

}; // TestConverter_WGS84ToNAD27
CPPUNIT_TEST_SUITE_REGISTRATION(spatialdata::geocoords::TestConverter_WGS84ToNAD27);

// ---------------------------------------------------------------------------------------------------------------------
class spatialdata::geocoords::TestConverter_WGS84ToECEF : public spatialdata::geocoords::TestConverter {
    CPPUNIT_TEST_SUB_SUITE(TestConverter_WGS84ToECEF, TestConverter);
    CPPUNIT_TEST_SUITE_END();

    void setUp(void) {
        TestConverter::setUp();

        CPPUNIT_ASSERT(_data);
        _data->numPoints = 6;
        _data->spaceDim = 3;

        static CSGeo csWGS84;
        csWGS84.setString("EPSG:4326"); // WGS84, latitude/longitude
        csWGS84.setSpaceDim(_data->spaceDim);
        _data->csSrc = &csWGS84;

        static CSGeo csECEF;
        csECEF.setString("+proj=geocent +datum=WGS84");
        csECEF.setSpaceDim(_data->spaceDim);
        _data->csDest = &csECEF;

        static const double coordsLatLonWGS84[6*3] = {
            3.899994227695e+01, -1.150008507633e+02,  -8.950827822595e+00,
            4.323409740913e+01, -1.203436181122e+02,  -9.225051786848e+00,
            4.523406963911e+01, -1.213437106276e+02,  -1.651562577217e+01,
            3.623419630177e+01, -1.153433730158e+02,  -2.018008883950e+01,
            3.923419970866e+01, -1.103432442395e+02,   1.046766831825e+02,
            3.323430190358e+01, -1.073431211987e+02,   1.087924313666e+01,
        };
        _data->coordsSrc = coordsLatLonWGS84;

        static const double coordsECEF[6*3] = {
            -2.097658330155e+06, -4.498268420315e+06,  3.992306409748e+06,
            -2.351216279957e+06, -4.016601774689e+06,  4.346479509353e+06,
            -2.340325349141e+06, -3.842552160654e+06,  4.505693105857e+06,
            -2.204701624283e+06, -4.654958696636e+06,  3.749172150551e+06,
            -1.719793652503e+06, -4.638444207813e+06,  4.012555773384e+06,
            -1.591903914839e+06, -5.097499656067e+06,  3.475728975021e+06,
        };
        _data->coordsDest = coordsECEF;

    } // setUp

}; // TestConverter_WGS84ToECEF
CPPUNIT_TEST_SUITE_REGISTRATION(spatialdata::geocoords::TestConverter_WGS84ToECEF);

// ---------------------------------------------------------------------------------------------------------------------
class spatialdata::geocoords::TestConverter_units : public spatialdata::geocoords::TestConverter {
    CPPUNIT_TEST_SUB_SUITE(TestConverter_units, TestConverter);
    CPPUNIT_TEST_SUITE_END();

    void setUp(void) {
        TestConverter::setUp();

        CPPUNIT_ASSERT(_data);
        _data->numPoints = 3;
        _data->spaceDim = 3;

        static CSGeo csMeter;
        csMeter.setString("+proj=tmerc +datum=WGS84 +lon_0=-122.6765 +lat_0=45.5231 +k=0.9996 +units=m +vunits=m");
        csMeter.setSpaceDim(_data->spaceDim);
        _data->csSrc = &csMeter;

        static CSGeo csKilometer;
        csKilometer.setString("+proj=tmerc +datum=WGS84 +lon_0=-122.6765 +lat_0=45.5231 +k=0.9996 +units=km +vunits=km");
        csKilometer.setSpaceDim(_data->spaceDim);
        _data->csDest = &csKilometer;

        static const double coordsMeter[3*3] = {
            1.0e+2, -5.0e+2, 1.0e+1,
            4.0e+3, -1.5e+3, 1.0e+2,
            -5.0e+4, +2.0e+4, 2.5e+3,
        };
        _data->coordsSrc = coordsMeter;

        static const double coordsKilometer[3*3] = {
            1.0e-1, -5.0e-1, 1.0e-2,
            4.0e+0, -1.5e+0, 1.0e-1,
            -5.0e+1, +2.0e+1, 2.5e+0,
        };
        _data->coordsDest = coordsKilometer;

    } // setUp

}; // TestConverter_units
CPPUNIT_TEST_SUITE_REGISTRATION(spatialdata::geocoords::TestConverter_units);

// ---------------------------------------------------------------------------------------------------------------------
class spatialdata::geocoords::TestConverter_XYZToXYZ : public spatialdata::geocoords::TestConverter {
    CPPUNIT_TEST_SUB_SUITE(TestConverter_XYZToXYZ, TestConverter);
    CPPUNIT_TEST_SUITE_END();

    void setUp(void) {
        TestConverter::setUp();

        CPPUNIT_ASSERT(_data);
        _data->numPoints = 6;
        _data->spaceDim = 3;

        static CSCart csMeter;
        csMeter.setToMeters(1.0);
        csMeter.setSpaceDim(_data->spaceDim);
        _data->csSrc = &csMeter;

        static CSCart csKilometer;
        csKilometer.setToMeters(1.0e+3);
        csKilometer.setSpaceDim(_data->spaceDim);
        _data->csDest = &csKilometer;

        static const double coordsMeter[6*3] = {
            -1.284640402306e+06,  1.064304544651e+05, -1.314223695069e+05,
            -1.617989794608e+06,  6.524818197004e+05, -2.429529262194e+05,
            -1.637488936912e+06,  8.852730256936e+05, -2.774331769932e+05,
            -1.362847273019e+06, -1.913287267184e+05, -1.500646038350e+05,
            -8.881745594215e+05,  7.658679840913e+04, -6.239198222893e+04,
            -6.825105930858e+05, -6.111332576090e+05, -6.615476230714e+04,
        };
        _data->coordsSrc = coordsMeter;

        static const double coordsKilometer[6*3] = {
            -1.284640402306e+03,  1.064304544651e+02, -1.314223695069e+02,
            -1.617989794608e+03,  6.524818197004e+02, -2.429529262194e+02,
            -1.637488936912e+03,  8.852730256936e+02, -2.774331769932e+02,
            -1.362847273019e+03, -1.913287267184e+02, -1.500646038350e+02,
            -8.881745594215e+02,  7.658679840913e+01, -6.239198222893e+01,
            -6.825105930858e+02, -6.111332576090e+02, -6.615476230714e+01,
        };
        _data->coordsDest = coordsKilometer;

    } // setUp

}; // TestConverter_XYZToXYZ
CPPUNIT_TEST_SUITE_REGISTRATION(spatialdata::geocoords::TestConverter_XYZToXYZ);

// End of file
