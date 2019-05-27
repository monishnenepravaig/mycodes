#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X 1028*5
#define Y 200

char* readline();
char** split_string(char*);

// Complete the whatFlavors function below.
void whatFlavors(int cost_count, int* cost, int money) 
{
    int i=0,j=0,key=0,remaining=0,found=0,temp=0;
    int hash_table[X][Y];
    for(i=0;i<X;i++)
    {
        hash_table[i][0]=1;
        for(j=1;j<Y;j++)
        {
            hash_table[i][j]=0;
        }           
    }
    for(i=0;i<cost_count;i++)
    {
        key=(*(cost+i)%(X-1))+1;
        hash_table[key][hash_table[key][0]++]=i;
    }
    for(i=0;i<cost_count;i++)
    {
        if(*(cost+i)>=money)
        {
            continue;
        }
        remaining=money-*(cost+i);
        key=(remaining%(X-1))+1;
        for(j=0;j<hash_table[key][0];j++)
        {
            if(money==*(cost+i)+*(cost+hash_table[key][j]))
            {
                temp=hash_table[key][j];
                if(i!=temp)
                {
                    j=temp;
                    found=1;
                    break;
                }
            }
        }
        if(found)
        {
            break;
        }
    }
    printf("%d %d\n",i+1,j+1);
}

int main()
{
    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* money_endptr;
        char* money_str = readline();
        int money = strtol(money_str, &money_endptr, 10);

        if (money_endptr == money_str || *money_endptr != '\0') { exit(EXIT_FAILURE); }

        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char** cost_temp = split_string(readline());

        int* cost = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            char* cost_item_endptr;
            char* cost_item_str = *(cost_temp + i);
            int cost_item = strtol(cost_item_str, &cost_item_endptr, 10);

            if (cost_item_endptr == cost_item_str || *cost_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(cost + i) = cost_item;
        }

        int cost_count = n;

        whatFlavors(cost_count, cost, money);
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
