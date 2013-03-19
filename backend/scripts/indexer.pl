#!/usr/bin/perl

# initialize all variables
@documents = ();
@terms = ();
%accu = ();
%queries= ();
%dNorm = ();
%idf = ();
%invIndex = ();
%nonInvIndex = ();
@results = ();
$a = ();
$qNorm = 0;

#### Main ####
# all the magic happens here
# 1. index all files

# 2. calculate all the idfs and so on

# 3. run the queries against the documents

# 4. get the results displayed

# 5. End


#### SUBS ####
#$->Variable , @->Array , %->Hash

sub get_Document_count {
	$docCount = @documents;
}

sub indexing_of_documents_and_queries{
	foreach $doc (@documents) { #/create inverted and non-inverted index 
		#get @terms by tokenizing $doc;
		@terms = split("\s",$doc);

		foreach $term (@terms) {
			# increment frequency in inverted index
			$invIndex{$term}{$doc} += 1; 
			# increment frequency in non inverted index
			$nonInvIndex{$doc}{$term} += 1; 
		}
	}

	#create index of queries
	foreach $query (@queries){ 
		#get @terms by tokenizing $query; 
		@terms = split("\s",$query);

		foreach $term (@terms){
			# increment frequency
			$queries{$query}{$term} += 1;
		}
	}
}

sub calculate_all_idfs_and_document_normalizers{
	foreach $doc (keys  %nonInvIndex) { 
		$dNorm{$doc} = 0;
		foreach $word (keys %{$nonInvIndex{$doc}}) { # keys %{$array{Bob}}
			$idf{$word} = log ( (1 + $docCount) / ( 1 + documentFrequency) );
			$a = (($nonInvIndex{$doc}{$word}) * ($idf{$word}));
			$dNorm{$doc} += $a * $a;
		}
	$dNorm{$doc} = Math.sqrt($dNorm{$doc});
	}
}

sub process_queries{
	foreach $query (keys %queryIndex) { 
		$qNorm = 0;
		#create new %accu;
		%accu = ();
		foreach $queryWord (keys %{$queryIndex{$query}}) { # process all query terms
			if(! $idf{$queryWord}){
				$idf{$queryWord} = log( 1 + $docCount);
			}

			$b = $queries{$query}{$queryWord} * $idf{$queryWord};
			$qNorm += ($b * $b);
			if( defined $invIndex{$queryWord} ) { # if query term occurs in collection
				foreach $document (keys %{$invIndex{$queryWord}}) {
					# document scores are added up in accumulators. filename serves as document identifier
					$a = $invIndex{$queryWord}{$document} * $idf;
					$accu{$document} += ( $a * $b ); 
				}
			}
		} 

		# zweiter Teil 2.2
		$qNorm = Math.sqrt( $qNorm );
		foreach $document (keys %accu) { # normalize length of vectors
			# this used to be weird (%accu{$document} /= (%dNorm{$document}) * $qNorm )), so I removed the "/"
			$accu{$document} = (($dNorm{$document}) * $qNorm );
		}

		#set @results = sort %accu by values 
		##foreach (sort {$hash{$a} cmp $hash{$b}} (keys %hash);
		#foreach $key (sort { $ages {$a} <=> $ages {$b}} keys %ages )
		#{
		#	print STDOUT "$ages{$key}\n";
		#}

		# sort and return 1000 best results
	
		foreach $result (@results){
			print "$queryid Q0 $document $rank $accuValue";
		}

	}
}
