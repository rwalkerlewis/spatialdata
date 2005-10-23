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

/** @file pkgs/geocoords/lib/CSGeoProj.h
 *
 * @brief C++ CSGeoProj object
 *
 * C++ object for defining a projected geographic coordinate system.
 */

#if !defined(spatialdata_geocoords_csgeoproj_h)
#define spatialdata_geocoords_csgeoproj_h

namespace spatialdata {
  namespace geocoords {
    class CSGeoProj;
    class Projector; // HOLDSA projector
    class TestCSGeoproj; // forward declaration
  } // geocoords
} // spatialdata

/// C++ object for defining a local cartesian coordinate system
class spatialdata::geocoords::CSGeoProj : public CSGeo
{ // class CSGeoProj
  friend class TestCSGeoProj;

 public :
  // PUBLIC METHODS /////////////////////////////////////////////////////

  /** Default constructor
   *
   * @param cs Source coordinate system
   */
  CSGeoProj(void);

  /// Default destructor
  ~CSGeoProj(void);

  /// Initialize the coordinate system.
  void initialize(void);

  /** Set projector.
   *
   * @param projector Geographic coordinate projector
   */
  void projector(const Projector& projector);

  /** Convert coordinates to PROJ4 useable form.
   *
   * @param ppCoords Pointer to array of coordinates [#locs*3]
   * @param numLocs Number of locations
   * @param is2D True if coordinates are 2D, false if 3D
   */
  void toProjForm(double** ppCoords,
		  const int numLocs,
		  bool is2D =false) const;
  
  /** Convert coordinates from PROJ4 form to form associated w/coordsys.
   *
   * @param ppCoords Pointer to array of coordinates [#locs*3]
   * @param numLocs Number of locations
   * @param is2D True if coordinates are 2D, false if 3D
   */
  void fromProjForm(double** ppCoords,
		    const int numLocs,
		    bool is2D =false) const;
  
private :
 // PRIVATE MEMBERS ////////////////////////////////////////////////////

  Projector* _pProjector; ///< Pointer to Projector

}; // class CSGeoProj

#endif // spatialdata_geocoords_csgeoproj_h

// version
// $Id$

// End of file 
