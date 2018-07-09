j=0
array=''
while [ $j -lt 20 ]
do
    read a
    array=$(echo $array $a)
    ((j++))
done
echo $array|  cut -f 4 -d' '