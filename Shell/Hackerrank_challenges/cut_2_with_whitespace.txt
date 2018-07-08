j=0
while [ $j -lt 20 ]
do
    read a
    b=$(echo $a | cut -c2-2)
    if [[ $b =~ ^\ $ ]];
    then
        printf ' ' $b
    fi
    printf '%s' $b
    c=$(echo $a | cut -c7-7)
    printf '%s\n' $c
    #echo -e $b$c
    ((j++))
done