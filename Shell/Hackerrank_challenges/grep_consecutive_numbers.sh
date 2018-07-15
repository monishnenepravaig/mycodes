array=()
j=0
while [ $j -lt 20 ];
do
    read a    
    echo $a | grep -P '([0-9]) ?\1'
    ((j++))
done
#* : 0 or many
#+ : 1 or many
#? : 0 or 1 