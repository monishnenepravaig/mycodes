j=0
while [ $j -lt 20 ]
do
    read a
    echo $a | tr -d "a-z"
    ((j++))
done   