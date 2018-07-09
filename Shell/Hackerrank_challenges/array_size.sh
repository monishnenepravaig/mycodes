j=0
array=()
while [ $j -lt 20 ]
do
    read a
    if [[ "${a}" == *"N"* ]];then
    array+=("$a") 
    elif [[ "${a}" == *"A"* ]];then
    array+=("$a") 
    elif [[ "${a}" == *"G"* ]];then
    array+=("$a") 
    fi
    ((j++))
done
echo ${#array[*]}