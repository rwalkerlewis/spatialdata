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

## @file pyre/SimpleDB.py
## @brief Python manager for simple spatial database.

from SpatialDB import SpatialDB

import spatialdb as bindings

# SimpleDB class
class SimpleDB(SpatialDB):
  """Python manager for simple spatial database."""

  # INVENTORY //////////////////////////////////////////////////////////

  class Inventory(SpatialDB.Inventory):
    """Python object for managing SimpleDB facilities and properties."""

    ## @class Inventory
    ## Python object for managing SimpleDB facilities and properties.
    ##
    ## \b Properties
    ## @li query_type Type of query to perform
    ##
    ## \b Facilities
    ## @li \b iohandler I/O handler for database

    import pyre.inventory

    queryType = pyre.inventory.str("query_type", default="Nearest")
    queryType.validator = pyre.inventory.choice(["Nearest", "Linear"])

    from SimpleIOAscii import SimpleIOAscii
    iohandler = pyre.inventory.facility("iohandler", factory=SimpleIOAscii)

  # PUBLIC METHODS /////////////////////////////////////////////////////

  def initialize(self):
    """Initialize database."""

    iohandler = self.inventory.iohandler
    iohandler.initialize()

    SpatialDB.initialize(self)
    bindings.CppSimpleDB_IOHandler(self._cppSpatialDB,
                                   iohandler.handle())
    return
  
  def open(self):
    """Open database and prepare for querying."""
    SpatialDB.open(self)
    bindings.CppSimpleDB_QueryType(self._cppSpatialDB,
                                   self.inventory.queryType)
    return

  def __init__(self, name="simpledb"):
    """Constructor."""
    SpatialDB.__init__(self, name)
    self._cppSpatialDB = bindings.CppSimpleDB()
    return

# version
__id__ = "$Id: SimpleDB.py,v 1.1 2005/05/25 18:43:00 baagaard Exp $"

# End of file 