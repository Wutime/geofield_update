# geofield_update

Drupal 7 module to automatically run through existing nodes and update the Google mapping coordinates.

Google Map API limits requests!  This module will allow your API requests to be spread out over time; updating each address during your scheduled cron frequency.  You can set the number of addresses to parse per cron run so you don't go over.  If you do go over your limit, the cron will pickup where it left off next run, until all nodes are complete.

Why is this needed? This helps when you've imported 1000's of addresses that require LNG/LAT coordinates from Google for the given address, but you've reached your API limit.  

Huge help if you're displaying Google Maps on your website for nodes that you've imported in bulk.
