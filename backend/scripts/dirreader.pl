#!/usr/bin/perl
$dirtodocs='/home/john/docsearch/data/documents';
if (-d $dirtodocs) {
  opendir(DIR, $dirtodocs) or die $!;
  while (my $file = readdir(DIR)) {
    # Use a regular expression to ignore files beginning with a period
    next if ($file =~ m/^\./);
    print "-> $file \n";
  }
  closedir(DIR);
}
