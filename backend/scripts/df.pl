#!/usr/bin/perl

# initialize all variables
@documents = ();
@terms = ();

#### Main ####
# all the magic happens here
$string = "experimental investigation of the aerodynamics of a
wing in a slipstream .
  an experimental study of a wing in a propeller slipstream was
made in order to determine the spanwise distribution of the lift
increase due to slipstream at different angles of attack of the wing
and at different free stream to slipstream velocity ratios .  the
results were intended in part as an evaluation basis for different
theoretical treatments of this problem .
  the comparative span loading curves, together with
supporting evidence, showed that a substantial part of the lift increment
produced by the slipstream was due to a /destalling/ or
boundary-layer-control effect .  the integrated remaining lift
increment, after subtracting this destalling lift, was found to agree
well with a potential flow theory .
  an empirical evaluation of the destalling effects was made for
the specific configuration of the experiment ."

#### SUBS ####
#$->Variable , @->Array , %->Hash
sub indexing_of_documents_and_queries{
	foreach $doc in @documents { #/create inverted and non-inverted index 
		get @terms by tokenizing $doc;
		foreach $term in @terms {
			%invIndex{$term}{$doc} += 1 # increment frequency in inverted index
			%nonInvIndex{$doc}{$term} += 1 # increment frequency in non-inv index 
		}
	}
	foreach $query in @queries{ #create index of queries
		get @terms by tokenizing $query; 
		foreach $term in @terms {
			%queries{$query}{$term} += 1 # increment frequency 
		}
	}
}

sub calculate_all_idfs_and_document_normalizers{
	foreach $doc in %nonInvIndex{ 
		%dNorm{$doc} = 0;
		foreach $word in %nonInvIndex{$doc} {
			%idf{$word} = log ( (1 + totalNummerOfDocuments) / ( 1 + documentFrequency) ) 
			$a = %nonInvIndex{$doc}{$word} * %idf{$word}
			%dNorm{$doc} += $a * $a;
		}
	%dNorm {$doc} = Math.sqrt(%dNorm{$doc} 
	}
}

sub process_queries{
	foreach $query in %queryIndex { 
		$qNorm = 0
		create new %accu
		foreach $queryWord in %queryIndex{$query} { # process all query terms
			if(! %idf{$queryWord}){
				%idf{$queryWord} = log( 1 + totalNummerOfDocuments);
			}
			$b = %queries{$query}{$queryWord} * %idf{$queryWord}
			$qNorm += ($b * $b)
			if( %invIndex{$queryWord} is definded ) { # if query term occurs in collection
				foreach $document in @invindex{$queryWord} {
					# document scores are added up in accumulators. filename serves as document identifier
					$a = %invIndex{$queryWord}{$document} * $idf
					%accu{$document} += ( $a * $b ); 
				}
			}
		} 
		# zweiter Teil 2.2
		$qNorm = Math.sqrt( $qNorm )
		foreach $document in %accu { # normalize length of vectors
			%accu{$document} /= (%dNorm{$document}) * $qNorm )
		}

		set @results = sort %accu by values # sort and return 1000 best results
	
		foreach $result in @results{
			print "$queryid Q0 $document $rank $accuValue"
		}

	}
}
