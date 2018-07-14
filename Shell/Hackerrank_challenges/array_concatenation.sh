array=()
j=0
while [ $j -lt 20 ]
do
    read a
    array+=("$a")
    ((j++))
done
array_concatenated=$(echo ${array[*]} ${array[*]} ${array[*]})
echo ${array_concatenated[*]}
