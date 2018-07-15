array=()
j=0
while read a;
do
    array+=("$a")
done
while [ $j -lt ${#array[*]} ];
do
    echo ${array[j]}  | sed -r 's/(thy)/{\1}/Ig'
    ((j++))
done
