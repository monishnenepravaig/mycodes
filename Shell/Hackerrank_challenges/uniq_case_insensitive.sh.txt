a=$(echo $( uniq -c -i))
j=0
e=e
while [ $j -lt 20 ]
do
    if [[ "${a}" == *e* ]];then
        b=$(echo $a | cut -f 1-3 -d' ')
        a=$(echo $a | cut -f 4- -d' ')
    else
        b=$(echo $a | cut -f 1-2 -d' ')
        a=$(echo $a | cut -f 3- -d' ')
    fi
    echo $b
    ((j++))
done