array=()
j=0
i=0
while [ $i -lt 20 ];
do
    read a
    if [ -z $a];
    then
        ((i=50))    
    else
        array+=("$a")
    fi
    ((i++))
done
while [ $j -lt ${#array[*]} ];
do 
    echo  ${array[j]} | awk '{print $1,":", ($2<50||$3<50||$4<50) ? "Fail" : "Pass"}'
    ((j++))
done