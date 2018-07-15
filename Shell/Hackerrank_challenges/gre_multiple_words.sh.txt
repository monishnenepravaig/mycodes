array=()
j=0
while read a;
do
    array+=("$a")
done
while [ $j -lt ${#array[*]} ];
do
    echo ${array[j]} | grep -e 'the ' -e 'that ' -e 'then ' -e 'those ' -i
    ((j++))
done