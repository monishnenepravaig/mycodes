j=0
array=''
while [ $j -lt 20 ]
do
    read a
    array=$(echo $array $a)
    ((j++))
done
b=$(echo $array | tr "N" ".")
b=$(echo $b | tr "A" ".")
b=$(echo $b | tr "G" ".")
echo $b