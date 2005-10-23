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

/** @file pkgs/geocoords/lib/Projector.h
 *
 * @brief C++ Projector object
 *
 * C++ object for projecting to/from geographic projections.
 */

#if !defined(spatialdata_geocoords_projector_h)
#define spatialdata_geocoords_projector_h

#include <string> // HASA std::string
#include "proj4fwd.h" // Proj4 forward declaration

namespace spatialdata {
  namespace geocoords {
    class Projector;
    class CSGeo;
  } // geocoords
} // spatialdata

/// C++ object for projecting to/from geographic projections
class spatialdata::geocoords::Projector
{ // class Projector

 public :
  // PUBLIC METHODS /////////////////////////////////////////////////////

  /// Default constructor
  Projector(void);

  /// Default destructor
  ~Projector(void);

  /// Copy constructor
  Projector(const Projector& p);

  /** Set projection.
   *
   * @param projection Name of projection
   */
  void projection(const char* name);

  /** Get projection.
   *
   * @returns Name of projection
   */
  const char* projection(void) const;

  /** Set false easting.
   *
   * @param easting False easting
   */
  void falseEasting(const double easting);

  /** Get false easting.
   *
   * @returns False easting
   */
  double falseEasting(void) const;

  /** Set false northing.
   *
   * @param northing False northing
   */
  void falseNorthing(const double northing);

  /** Get false northing.
   *
   * @returns False northing
   */
  double falseNorthing(void) const;

  /** Set projection scale factor (along central meridian).
   *
   * @param value Value for scale factor
   */
  void scaleFactor(const double value);

  /** Get projection scale factor (along central meridian).
   *
   * @returns Scale factor
   */
  double scaleFactor(void) const;

  /** Set units of projection.
   *
   * @param name Name of units
   */
  void units(const char* name);

  /** Get units of projection.
   *
   * @returns Name of units
   */
  const char* units(void) const;

  /** Initialize projector.
   *
   * @param csGeo Geographic coordinate system
   */
  void initialize(const CSGeo& csGeo);

  /** Project geographic coordinates.
   *
   * @param pX Pointer to x coordinate of location (output)
   * @param pY Pointer to y coordinate of location (output)
   * @param lon Longitude of location
   * @param lat Latitude of location
   */
  void project(double* pX,
	       double* pY,
	       const double lon,
	       const double lat);

  /** Get geographic coordinates of projected location.
   *
   * @param pLon Pointer to longitude of location (output)
   * @param pLat Pointer to latitude of location (output)
   * @param x X coordinate of location
   * @param y Y coordinate of location
   */
  void invproject(double* pLon,
		  double* pLat,
		  const double x,
		  const double y);

private :
 // PRIVATE MEMBERS ////////////////////////////////////////////////////

  double _falseEasting; ///< Longitude of origin
  double _falseNorthing; ///< Latitude of origin
  double _scaleFactor; ///< Scale factor
  std::string _projection; ///< Name of projection
  std::string _units; ///< Name of units in projection
  
  projPJ _pProj; ///< Pointer to projection
  
}; // class Projector

#include "Projector.icc" // inline methods

#endif // spatialdata_geocoords_projector_h

// version
// $Id: Projector.h,v 1.1 2005/05/25 17:28:11 baagaard Exp $

// End of file 
