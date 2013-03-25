#!/usr/bin/perl


# merne: expected output: 
#{
#    "queries": [
#        {
#            "queryID": "1"
#        },
#        {
#            "queryID": "2"
#        }
#    ]
#}
$dirtodocs='/Users/merne/dev/perl/docsearch/data/documents';
if (-d $dirtodocs) {
  opendir(DIR, $dirtodocs) or die $!;
  $first=1;
  print "{\"queries\": [ " ;
  while (my $file = readdir(DIR)) {
    # Use a regular expression to ignore files beginning with a period
    next if ($file =~ m/^\./);
    if ($first == 1) {
    	print "{  \"queryID\": \"$file\" } ";
    	$first=0;
    } else {
    	print ", {  \"queryID\": \"$file\" } ";
    }
  }
  print "]}";
  closedir(DIR);
}
