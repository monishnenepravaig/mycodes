#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOOKUP_SIZE 1000

char* readline();
char** split_string(char*);
uint8_t* table;
int table_filled=0;

void bzero(uint8_t* data,int length)
{
    int i=0;
    while(i<length)
    {
        *(data+i++)=0;
    }
}

uint8_t* itoa(int number,uint8_t* data)
{
    int i=0,total=0;
    // printf("number=%d, ",number);
    while(number!=0)
    {
        *(data+i++)=number%10+'0';
        number/=10;
    }
    // printf("str=%s, ",data);
    total=i;
    // printf("digits=%d, ",total);
    for(i=0;i<total/2;i++)
    {
        *(data+i)^=*(data+total-i-1);
        *(data+total-i-1)^=*(data+i);
        *(data+i)^=*(data+total-i-1);
    }
    // printf("reverse str=%s\n",data);
    return data;
}

// Complete the superDigit function below.
int superDigit(char* n, int k) 
{
    int sum=0,i=0,sum_rec=0,final=0;
    uint8_t* data=(uint8_t*)malloc(10);
    while(*(n+i)!=0)
    {
        sum+=*(n+i++)-'0';
    }
    for(;table_filled<sum;table_filled++)
    { 
        bzero(data,10);
        superDigit(itoa(table_filled,data),1);
    }
    if(*(table+sum)!=0)
    {
        sum_rec=*(table+sum);
        printf("case:Data found in table for %d = %d\n",sum,sum_rec);
    }
    else if(sum>9)
    {
        bzero(data,10);
        sum_rec=superDigit(itoa(sum,data),1);
        printf("case:recursive sum done for %d = %d\n",sum,sum_rec);
        *(table+sum)=sum_rec;
    }
    else
    {
        printf("case:lower than 9 for %d\n",sum);
        sum_rec=sum;
        *(table+sum)=sum;
    }
    if(k>1)
    {
        bzero(data,10);
        final=superDigit(itoa(sum_rec*k,data),1);
        printf("k=%d, sum=%d, final=%d\n",k,sum_rec,final);
    }
    else
    {
        final=sum_rec;
    }
    return final;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    table=(uint8_t*)calloc(LOOKUP_SIZE,1);
    char** nk = split_string(readline());

    char* n = nk[0];

    char* k_endptr;
    char* k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    int result = superDigit(n, k);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

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
