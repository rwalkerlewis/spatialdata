# ----------------------------------------------------------------------
#
# Brad T. Aagaard, U.S. Geological Survey
#
# This code was developed as part of the Computational Infrastructure
# for Geodynamics (http://geodynamics.org).
#
# Copyright (c) 2010-2017 University of California, Davis
#
# See COPYING for license information.
#
# ----------------------------------------------------------------------
#

# @file spatialdata/spatialdb/TimeHistory.py
#
# @brief Python object for time history dependence with spatial databases.
#
# Factory: temporal_database

from pyre.components.Component import Component
from spatialdb import TimeHistory as ModuleTimeHistory


class TimeHistory(Component, ModuleTimeHistory):
    """
    Python object for time history dependence with spatial databases.

    Factory: temporal_database

    INVENTORY

    Properties
      - *label* Label for time history.
      - *filename* Name of file for time history.

    Facilities
      - None
    """

    import pyre.inventory

    label = pyre.inventory.str("label", default="temporal database")
    label.meta['tip'] = "Label for time history."

    filename = pyre.inventory.str("filename", default="timehistory.timedb")
    filename.meta['tip'] = "Name of file for time history."

    # PUBLIC METHODS /////////////////////////////////////////////////////

    def __init__(self, name="timehistory"):
        """
        Constructor.
        """
        Component.__init__(self, name, facility="temporal_database")
        self._createModuleObj()

    # PRIVATE METHODS ////////////////////////////////////////////////////

    def _configure(self):
        """
        Set attributes based on inventory.
        """
        Component._configure(self)
        ModuleTimeHistory.setLabel(self, self.label)
        ModuleTimeHistory.setFilename(self, self.filename)

    def _createModuleObj(self):
        """
        Create Python module object.
        """
        ModuleTimeHistory.__init__(self)


# FACTORIES ////////////////////////////////////////////////////////////

def temporal_database():
    """
    Factory associated with TimeHistory.
    """
    return TimeHistory()


# End of file
