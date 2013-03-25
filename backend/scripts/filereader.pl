#!/usr/bin/perl
use strict;
use warnings;

my @arr=readfile('/Users/merne/dev/perl/docsearch/data/documents/1');
print "-->\n@arr\n<--\n";

sub readfile() {
  my $file= $_[0];
  my @result;
  open(FILE, $file) or die $!;
  while (<FILE>) {
    my $line = lc($_);
    $line=~ s/(\.|\,|\-|\+|\/|\\)/ /g;
    $line=~ s/(\s+)/ /g;
    my @test=split(' ',$line);
    push (@result , @test);
  }
  close (FILE);
  return @result;
}
