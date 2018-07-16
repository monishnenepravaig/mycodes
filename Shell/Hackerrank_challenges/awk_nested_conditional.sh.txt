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
    echo  ${array[j]} | awk '{avg=($2+$3+$4)/3; print $0, ":", (avg<50)?"FAIL":(avg<80)?"B":"A"}'
    ((j++))
done