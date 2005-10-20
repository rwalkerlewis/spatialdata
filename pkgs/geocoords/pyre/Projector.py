#!/usr/bin/env python
#
# ----------------------------------------------------------------------
#
#                           Brad T. Aagaard
#                        U.S. Geological Survey
#
# <LicenseText>
#
# ----------------------------------------------------------------------
#

## @file geocoords/pyre/Projector.py
## @brief Python manager for projector.

from pyre.components.Component import Component

# Projector class
class Projector(Component):
  """Python manager for projector."""

  # INVENTORY //////////////////////////////////////////////////////////

  class Inventory(Component.Inventory):
    """Python object for managing Projector facilities and properties."""

    ## @class Inventory
    ## Python object for managing Projector facilities and properties.
    ##
    ## \b Properties
    ## @li \b projection Name of projection
    ## @li \b units Name of units
    ##
    ## \b Facilities
    ## @li \b coord-sys Geographic coordinate system

    import pyre.inventory

    projection = pyre.inventory.str("projection", default="aea")
    projection.meta['tip'] = "Name of projection."

    units = pyre.inventory.str("units", default="m")
    units.meta['tip'] = "Units of coordinates."

    from CoordSysGeo import CoordSysGeo
    coordSys = pyre.inventory.facility("coord-sys", factory=CoordSysGeo)
    coordSys.meta['tip'] = "Geographic coordinate system."

  # PUBLIC METHODS /////////////////////////////////////////////////////

  def handle(self):
    """Get handle to C++ Projector."""
    return self._cppProjector


  def initialize(self):
    """Initialize projector."""
    
    import spatialdata.geocoords.geocoords as bindings
    self._cppProjector = bindings.CppProjector(self.coordSys.handle())
    bindings.CppProjector_projection(self._cppProjector, self.projection)
    bindings.CppProjector_units(self._cppProjector, self.units)
    bindings.CppProjector_initialize(self._cppProjector)
    return


  def project(self, lonlat):
    """Project geographic coordinates."""

    import spatialdata.geocoords.geocoords as bindings
    xy = bindings.CppProjector_project(self._cppProjector, lonlat)
    return xy
  

  def invproject(self, xy):
    """Project geographic coordinates."""

    import spatialdata.geocoords.geocoords as bindings
    lonlat = bindings.CppProjector_invproject(self._cppProjector, xy)
    return lonlat
  

  def __init__(self, name="projector"):
    """Constructor."""
    Component.__init__(self, name, facility="projector")
    self._cppProjector = None
    self.coordSys = None
    return


  # PRIVATE METHODS ////////////////////////////////////////////////////

  def _configure(self):
    """Setup members using inventory."""

    self.projection = self.inventory.projection
    self.units = self.inventory.units
    self.coordSys = self.inventory.coordSys
    return


# version
__id__ = "$Id$"

# End of file 