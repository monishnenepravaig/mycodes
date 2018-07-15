array=()
j=0
while [ $j -lt 50 ];
do
    read a    
    echo $a | grep -v -e 'that ' -i 
    ((j++))
done