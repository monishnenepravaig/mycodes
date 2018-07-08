j=0
while [ $j -lt 20 ]
do
    read a
    for ((i=0; i<${#a};i++));
    do
        if [ $i == 2 ]; 
        then
            echo "${a:$i:1}"
        fi
    done
    ((j++))
done