#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

int* rotLeft(int a_count, int* a, int d, int* result_count)
{
    int j=0;
    int temp[a_count];
    for(j=0;j<a_count;j++)
    {
        temp[j]=*(a+j);
    }
    d=d%a_count;
    for(j=0;j<a_count;j++)
    {

            if(a+j+d<a+a_count)
            {
                *(a+j)=*(temp+j+d);
            }
            else
            {
                *(a+j)=*(temp+(j+d-a_count));
            }
    }
    *result_count=a_count;
    return a;
}

int hourglassSum(int arr_rows, int arr_columns, int** arr)
{
    int sum=0,max_sum=0x80000001,row=0,column=0;
    for(row=0;row<arr_rows-2;row++)
    {
        for(column=0;column<arr_columns-2;column++)
        {
            sum=*(*(arr+row)+column)+*(*(arr+row)+column+1)+*(*(arr+row)+column+2)+*(*(arr+row+1)+column+1)+*(*(arr+row+2)+column)+*(*(arr+row+2)+column+1)+*(*(arr+row+2)+column+2);
            if(sum>max_sum)
            {
                max_sum=sum;
            }
        }
    }
    return max_sum;
}

// Complete the flippingBits function below.
long flippingBits(long n)
{
    long a=0xFFFFFFFF;
    n=a-n;
    printf("%ld",n);
    return n;
}

char* primality(int n)
{
    char* np= "Not prime";
    char* p="Prime";
    int i=2;
    if(n==1)
    {
        return np;
    }
    while(i*i<=n)
    {
        if(n%i==0)
        {
            return np;
        }
        i++;
    }
    return p;
}

void checkMagazine(int magazine_count, char** magazine, int note_count, char** note)
{
    int i=0,j=0,k=0,matched=0,not_matched=0,not_matched_flag=1,matched_flag=0,len=0;
    char* empty="";
    for(i=0;i<note_count;i++)
    {
        not_matched_flag=1;
        len=strlen(*(note+i));
        for(j=0;j<magazine_count;j++)
        {
            k=len;
            matched_flag=1;
            while((*(*(note+i)+k)!=0)||(*(*(magazine+j)+k)!=0)||(k>=0))
            {
                if((*(*(note+i)+k)!=*(*(magazine+j)+k)))
                {
                    matched_flag=0;
                    break;
                }
                k--;
            }
            if(matched_flag)
            {
                matched++;
                not_matched_flag=0;
                *(magazine+j)=empty;
                break;
            }
        }
        if(not_matched_flag)
        {
            not_matched++;
        }
        if((i+not_matched>magazine_count)||(not_matched>magazine_count-note_count))
        {
            break;
        }
    }
    if(matched==note_count)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}

char* twoStrings(char* s1, char* s2)
{
    char* yes="YES";
    char* no="NO";
    char ascii[256];
    uint16_t i=0;
    for(i=0;i<256;i++)
    {
        ascii[i]=0;
    }
    while(*s1!=0)
    {
        ascii[*s1++]=1;
        s1++;
    }
    while(*s2!=0)
    {
        if(ascii[*s2]==1)
        {
            return yes;
        }
        s2++;
    }
    return no;
}
