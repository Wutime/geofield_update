# geofield_update

Drupal 7 module to automatically run through existing nodes and update the Google mapping coordinates.

Google API rate limits requests; this module will allow the API requests to be made during your cron (scheduled) frequency.  

You can set the number of addresses to parse per cron run.

This helps when you've imported 1000's of addresses that require LNG/LAT coordinates from Google for the given address, but you've reached your API limit. 
