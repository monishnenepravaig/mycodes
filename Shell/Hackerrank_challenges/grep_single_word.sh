array=()
j=0
while read a;
do
    array+=("$a")
done
while [ $j -lt ${#array[*]} ];
do
    echo ${array[j]} | grep -e ' the '
    ((j++))
done