j=0
array=''
while [ $j -lt 20 ]
do
    read a
    array=$(echo $array $a)
    ((j++))
done
array=$(echo $array $array $array) 
echo $array