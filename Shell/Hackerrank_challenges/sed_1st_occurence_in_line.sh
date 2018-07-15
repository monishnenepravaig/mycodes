array=()
j=0
while read a;
do
    array+=("$a")
done
while [ $j -lt ${#array[*]} ];
do
    echo ${array[j]}  | sed 's/ the / this /1'
    ((j++))
done