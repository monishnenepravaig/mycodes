j=0
while read a ;
do   
    echo $a | awk '{if ($4 == "") print "Not all scores are available for",$1;}'
    ((j++))
done