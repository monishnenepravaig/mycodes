array=()
while read a;
do
    if [[ "${a}" != *a* ]] &&  [[ "${a}" != *A* ]];
    then
        array+=("$a")
    fi
done
echo ${array[*]}
