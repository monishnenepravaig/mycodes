array=()
j=0
while [ $j -lt 20 ];
do
    read a    
    echo $a | sed -E 's/(\S+) (\S+) (\S+) (\S+)/\4 \3 \2 \1/'
    ((j++))
done
