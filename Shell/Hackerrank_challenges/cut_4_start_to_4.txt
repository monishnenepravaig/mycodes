j=0
while [ $j -lt 100 ]
do
    read a
    echo $a | cut -c1-4
    ((j++))
done