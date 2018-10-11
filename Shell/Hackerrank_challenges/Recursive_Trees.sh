read tree_size
size_counter=0
columns=100
reverse_column_counter=62
new_reverse_column_counter=62
rows=63
i=0
j=0
base_counter=0
split_counter_left=0
split_counter_right=0
new_branches=0
branches=1
matrix_row=0
matrix=()
base=()
base+=$(($columns/2))
tree_height=16
while [ $i -lt $rows ]
do
    j=1
    matrix+=("_")
    while [ $j -lt $columns ]
    do
       matrix[$i]=$(echo ${matrix[$i]}_)
        ((j++))
    done
    ((i++))
done
while [ $size_counter -lt $tree_size ]
do
    i=0
    while [ $i -lt $branches ]
    do
        j=0
        reverse_column_counter=$(echo $new_reverse_column_counter)
        while [ $j -lt $tree_height ]
        do
            matrix[$reverse_column_counter]=$(echo ${matrix[$reverse_column_counter]} | sed "s/./1/${base[$base_counter]}" )
            ((reverse_column_counter--))
            ((j++))
        done
        split_counter_left=$(echo ${base[$base_counter]})
        split_counter_right=$(echo ${base[$base_counter]})
        j=0
        while [ $j -lt $tree_height ]
        do
            ((split_counter_left--))
            ((split_counter_right++))
            matrix[$reverse_column_counter]=$(echo ${matrix[$reverse_column_counter]} | sed "s/./1/$split_counter_left" )
            matrix[$reverse_column_counter]=$(echo ${matrix[$reverse_column_counter]} | sed "s/./1/$split_counter_right" )
            ((reverse_column_counter--))
            ((j++))
        done
        base+=("$split_counter_left")
        ((new_branches++))
        base+=("$split_counter_right")
        ((new_branches++))
        ((i++)) 
        ((base_counter++))
    done
    new_reverse_column_counter=$(echo $reverse_column_counter)
    tree_height=$(($tree_height/2))
    ((size_counter++))
    branches=$(echo $new_branches)
    new_branches=$(echo 0)
done
i=0
while [ $i -lt $rows ]
do    
    echo ${matrix[i]}
    ((i++))
done
