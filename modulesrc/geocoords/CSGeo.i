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

/** @file modulesrc/geocoords/CSGeo.i
 *
 * @brief SWIG interface to C++ CSGeo object.
 */

namespace spatialdata {
  namespace geocoords {

    class CSGeo : public CoordSys {
      friend class TestCSGeo;

    public :
      // PUBLIC METHODS /////////////////////////////////////////////////

      /// Default constructor
      CSGeo(void);

      /// Default destructor
      virtual
      ~CSGeo(void);

      /** Clone coordinate system.
       *
       * @returns Pointer to copy
       */
      virtual
      CoordSys* clone(void) const;

      /** Set string specifying coordinate system.
       *
       * @param[in] value String specifying coordinate system (proj format, WKT, EPSG:XXXX).
       */
      void setString(const char* value);
      
      /** Get string specifying coordinate system.
       *
       * @returns String specifying coordinate system (proj format, WKT, EPSG:XXXX).
       */
      const char* getString(void) const;
      
      /** Set number of spatial dimensions in coordinate system.
       *
       * @param ndims Number of dimensions
       */
      virtual
      void setSpaceDim(const int ndims);
      
      /** Get radial outward direction.
       *
       * dir and coords
       *   size = numLocs * numDims
       *   index = iLoc*numDims + iDim
       *
       * @param dir Array of direction cosines for outward radial direction.
       * @param coords Array of coordinates for locations.
       * @param numLocs Number of locations.
       * @param numDims Number of dimensions in coordinates.
       * @param dx Length scale for approximate surface tangent.
       */
      void computeSurfaceNormal(double* dir,
				const double* coords,
				const size_t numLocs,
				const size_t numDims,
				const double dx=1000.0) const;

      /** Pickle coordinate system to ascii stream.
       *
       * @param s Output stream
       */
      void pickle(std::ostream& s) const;
      
      /** Unpickle coordinate system from ascii stream.
       *
       * @param s Input stream
       */
      void unpickle(std::istream& s);

    }; // class CSGeo

  } // geocoords
} // spatialdata


// End of file 
