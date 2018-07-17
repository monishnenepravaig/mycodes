array='0'
i=0
read n
while [ $i -lt $n ];
do
    read a
    array=$( echo $array + $a )
    ((i++))
done
total=$(echo "scale = 4; $array " | bc)
result=$(echo "scale = 4; $total/$n " | bc)
printf "%.3f" "$result"