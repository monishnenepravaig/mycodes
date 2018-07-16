array=()
j=0
i=0
while [ $i -lt 20 ];
do
    read a
    read b
    if [ -z $a ];
    then
        ((i=50))    
    else
        printf "%s;%s\n" "$a" "$b"
    fi
    ((i++))
done