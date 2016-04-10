This module is useful if you currently use the geofield module and have added thousands of nodes.

The geofield API only allows 1,000 lookups per day.  If you add 5,000 nodes in one day, the last 4,000 added will NOT have any GPS points associated to them because you've exhausted your 1,000 lookups in a day.  Unfortunately, the geofield module does not retroactively review each node to update the GPS coordinates.   Without the geofield_update module you will need to revisit, load and save each node manually in order to get the GPS coordinates set for any node in which you have associated a geofield.

This module, geofield_update will allow you to specify which content types you have geofield's and it will automatically load and save each node that is missing a geofield GPS entry.   You can specify the number of nodes to be processed per cron run.  
