j=0
array=''
filtered_array=''
while [ $j -lt 20 ]
do
    read a
    if [[ "${a}" == *a* ]];then
    array=$(echo $array $a)
    elif [[ "${a}" == *A* ]];then
    array=$(echo $array $a)
    else
    filtered_array=$(echo $filtered_array $a)
    ((j++))
    fi
done
echo $filtered_array