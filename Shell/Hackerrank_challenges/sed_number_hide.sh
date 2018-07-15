array=()
j=0
while [ $j -lt 20 ];
do
    read a    
    a=$(echo $a | rev)
    echo $a   | sed -r 's/[0-9]/*/g5' | rev
    ((j++))
done