COUNTER=1
while [ $COUNTER -le 50 ]
do
    echo $COUNTER
    ((COUNTER++))
done