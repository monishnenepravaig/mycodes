read a
result=$(echo "scale = 4; $a" | bc)
printf "%.3f" "$result"
