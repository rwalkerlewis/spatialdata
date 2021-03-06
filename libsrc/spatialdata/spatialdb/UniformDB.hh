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

/** @file libsrc/spatialdb/UniformDB.hh
 *
 * @brief C++ manager for simple spatial database.
 */

#if !defined(spatialdata_spatialdb_uniformdb_hh)
#define spatialdata_spatialdb_uniformdb_hh

#include "SpatialDB.hh"

#include <string> // HASA std::string

/// C++ manager for simple spatial database.
class spatialdata::spatialdb::UniformDB : public SpatialDB { // class UniformDB
    friend class TestUniformDB; // unit testing

public:

    // PUBLIC METHODS /////////////////////////////////////////////////////

    /// Default constructor.
    UniformDB(void);

    /** Constructor with label.
     *
     * @param label Label of database
     */
    UniformDB(const char* label);

    /// Default destructor.
    ~UniformDB(void);

    /** Set values in database.
     *
     * @param names Array of names of values in database.
     * @param units Array of units for values in database.
     * @param values Array of values in database.
     * @param numValues Number of values in database.
     */
    void setData(const char* const* names,
                 const char* const* units,
                 const double* values,
                 const size_t numValues);

    /// Open the database and prepare for querying.
    void open(void);

    /// Close the database.
    void close(void);

    /** Get names of values in spatial database.
     *
     * @param[out] valueNames Array of names of values.
     * @param[out] numValues Size of array.
     */
    void getNamesDBValues(const char*** valueNames,
                          size_t* numValues) const;

    /** Set values to be returned by queries.
     *
     * @pre Must call open() before setQueryValues()
     *
     * @param names Names of values to be returned in queries
     * @param numVals Number of values to be returned in queries
     */
    void setQueryValues(const char* const* names,
                        const size_t numVals);

    /** Query the database.
     *
     * @pre Must call open() before query()
     *
     * @param vals Array for computed values (output from query), vals
     *   must be allocated BEFORE calling query().
     * @param numVals Number of values expected (size of pVals array)
     * @param coords Coordinates of point for query
     * @param numDims Number of dimensions for coordinates
     * @param pCSQuery Coordinate system of coordinates
     *
     * @returns 0 on success, 1 on failure (i.e., could not interpolate
     *   so values set to 0)
     */
    int query(double* vals,
              const size_t numVals,
              const double* coords,
              const size_t numDims,
              const spatialdata::geocoords::CoordSys* pCSQuery);

private:

    // PRIVATE METHODS ////////////////////////////////////////////////////

    UniformDB(const UniformDB& data); ///< Not implemented
    const UniformDB& operator=(const UniformDB& data); ///< Not implemented

private:

    // PRIVATE MEMBERS /////////////////////////////////////////////////////

    std::string* _names; ///< Names of values in database
    double* _values; ///< Values in database
    size_t* _queryValues; ///< Indices of values to be returned in queries.
    size_t _numValues; ///< Number of values in database
    size_t _querySize; ///< Number of values requested to be returned in queries.
}; // class UniformDB

#include "UniformDB.icc"

#endif // spatialdata_spatialdb_uniformdb_hh

// End of file
