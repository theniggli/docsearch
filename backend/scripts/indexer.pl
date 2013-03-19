#!/usr/bin/perl


#$->Variable , @->Array , %->Hash
indexing of documents and queries{
	foreach $doc in @documents { #/create inverted and non-inverted index get @terms by tokenizing $doc;
		foreach $term in @terms {
			%invIndex{$term}{$doc} += 1 # increment frequency in inverted index
			%nonInvIndex{$doc}{$term} += 1 # increment frequency in non-inv index }
		}
		foreach $query in @queries{ #create index of queries
			get @terms by tokenizing $query; foreach $term in @terms {
			%queries{$query}{$term} += 1 # increment frequency }
		}
}

calculate all idfs and document normalizers{
	foreach $doc in %nonInvIndex{ %dNorm{$doc} = 0;
		foreach $word in %nonInvIndex{$doc} {
			%idf{$word} = log ( (1 + totalNummerOfDocuments) / ( 1 + documentFrequency) ) 
			$a = %nonInvIndex{$doc}{$word} * %idf{$word}
			%dNorm{$doc} += $a * $a;
		}
	%dNorm {$doc} = Math.sqrt(%dNorm{$doc} 
	}
}

process queries{
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
