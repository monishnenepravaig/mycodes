j=0
while [ $j -lt 100 ]
do
    read a
    echo $a | cut -c3-3
    ((j++))
done