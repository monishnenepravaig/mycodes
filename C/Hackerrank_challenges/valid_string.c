#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LETTERS 26
#define SIZE 100

char* readline();
static char yes_str[]="YES";
static char no_str[]="NO";
char* isValid(char* s) 
{
    char* result;
    bool valid=1;
    int* hash=(int*)calloc(LETTERS,4);
    int* freq_hash=(int*)calloc(SIZE,4);
    int* freq_value_hash=(int*)calloc(SIZE,4);
    int i=0,min=1000000,max=0,freq=0,max_counter=0,min_counter=0;
    while(*(s+i))
    {
        hash[*(s+i)-'a']++;
        i++;
    }
    for(i=0;i<LETTERS;i++)
    {
        if(hash[i])
        {
            freq_hash[hash[i]%SIZE]++;
            freq_value_hash[hash[i]%SIZE]=hash[i];
            if(hash[i]>=max)
            {
                max_counter=hash[i]==max?max_counter+1:1;
                max=hash[i];
            }
            if(hash[i]<=min)
            {
                min_counter=hash[i]==min?min_counter+1:1;
                min=hash[i];
            }
            printf("%c:%d\t",i+'a',hash[i]);
        }
    }
    for(i=0;i<SIZE;i++)
    {
        if(freq_hash[i]>freq)
        {
            freq=freq_value_hash[i];
        }
    }
    //printf("\nmax:%d\tmax_counter:%d\tmin:%d\tmin_counter:%d\tfreq:%d",max,max_counter,min,min_counter,freq);
    if((max!=freq)&&(min!=freq))
    {
        valid=0;
    }
    if(max!=freq)
    {
        valid=max_counter>1?0:valid;
        valid=max>freq+1?0:valid;
    }
    if(min!=freq)
    {
        valid=min_counter>1?0:valid;
        valid=min>1?0:valid;
    }
    result=valid?yes_str:no_str;
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = isValid(s);

    fprintf(fptr, "%s\n", result);

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

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
