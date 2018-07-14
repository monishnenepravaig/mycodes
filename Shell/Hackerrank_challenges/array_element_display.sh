array=()
while read a;
do
    array+=("$a")
done
echo ${array[@]:3:1}
