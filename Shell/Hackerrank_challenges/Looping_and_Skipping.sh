COUNTER=0
ODD=0
while [ $COUNTER -le 49 ]
do
    ODD=$((COUNTER*2+1))
    echo $ODD
    ((COUNTER++))
done