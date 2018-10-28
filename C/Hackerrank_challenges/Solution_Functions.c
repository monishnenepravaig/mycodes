#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//138511468548
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

// Complete the repeatedString function below.
long repeatedString(char* s, long n)
{
    long total=0,quo=0;
    int count=0,len=strlen(s),i=0,a[len],rem=0;
    for(i=0;i<len;i++)
    {
        if(*(s+i)=='a')
        {
            count++;
        }
        a[i]=count;
    }
    quo=n/len;
    rem=n%len;
    if(count==0)
    {
        return count;
    }
    if(rem>0)
    {
        total=count*quo+a[rem-1];
    }
    else
    {
        total=count*quo;
    }
    return total;
}

int fibonacci(int n)
{
    if(memory[n]>=0)
    {
        return memory[n];
    }
    memory[n]=fibonacci(n-1)+fibonacci(n-2);
    return memory[n];
}

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(int c_count, int* c)
{
    int jumps=0,i=0;
    for(i=0;i<c_count;i++)
    {
        if(*(c+i+2)==0)
        {
            i++;
        }
        jumps++;
    }
    jumps--;
    return jumps;
}

// Complete the countingValleys function below.
int countingValleys(int n, char* s)
{
    int valleys=0,level=0,min_level=0;
    while(*s!=0)
    {
        if(*s=='U')
        {
            level++;
        }
        else if(*s=='D')
        {
            level--;
        }
        if(min_level>level)
        {
            min_level=level;
        }
        if((level>min_level)&&(level==0))
        {
            min_level=level;
            valleys++;
        }
        s++;
    }
    return valleys;
}

// Complete the sockMerchant function below.
int sockMerchant(int n, int ar_count, int* ar)
{
    int pairs=0,prev=0;
    merge_sort(ar_count,ar);
    while(*ar!=0)
    {
        if(prev==*ar)
        {
            pairs++;
            prev=0;
        }
        else
        {
            prev=*ar;
        }
        ar++;
    }
    return pairs;
}

// Complete the alternatingCharacters function below.
int alternatingCharacters(char* s)
{
    int deletions=0;
    uint8_t prev=0;
    while(*s!=0)
    {
        if(prev==*s)
        {
            deletions++;
        }
        else
        {
            prev=*s;
        }
        s++;
    }
    return deletions;
}

// Complete the makeAnagram function below.
int makeAnagram(char* a, char* b)
{
    int i=0,j=0,deletions=0;
    int len_a=strlen(a);
    int len_b=strlen(b);
    merge_sort(len_a,a);
    merge_sort(len_b,b);
    while((*(a+i)!=0)&&(*(b+j)!=0))
    {
        if(*(a+i)==*(b+j))
        {
            i++;
            j++;
        }
        else if(*(a+i)<*(b+j))
        {
            i++;
            deletions++;
        }
        else if(*(a+i)>*(b+j))
        {
            j++;
            deletions++;
        }
    }
    deletions+=(len_a-i)+(len_b-j);
    return deletions;
}

void countSwaps(int a_count, int* a)
{
    int count=0,i=0,j=0,temp=0;
    for(i=0;i<a_count;i++)
    {
        for(j=i;j<a_count;j++)
        {
            if(*(a+i)>*(a+j))
            {
                temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
                count++;
            }
        }
    }
    printf("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d",count,*(a),*(a+a_count-1));
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

// Complete the luckBalance function below.
int luckBalance(int k, int contests_rows, int contests_columns, int** contests)
{
    int i=0,luck=0,lost=0,count=0;
    int lowest[contests_rows];
    for(i=0;i<contests_rows;i++)
    {
        lowest[i]=-1;
    }
    for(i=0;i<contests_rows;i++)
    {
        if(*(*(contests+i)+1)==0)
        {
            luck+=*(*(contests+i));
        }
        else if ((*(*(contests+i)+1)==1))
        {
            lowest[count++]=*(*(contests+i));
        }
    }
    merge_sort(count,lowest);
    for(i=0;i<count;i++)
    {
        if(i<k)
        {
            luck+=lowest[i];
        }
        else
        {
            luck-=lowest[i];
        }
    }
    return luck;
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

void merge_sort(int32_t count,int32_t* data)
{
    int32_t temp=0,middle=count/2,i=0,j=0,temp_counter=0;
    int32_t* temp_ptr = (int32_t*)malloc(count*4);
    if((count==1)||(count==0))
    {
        return;
    }
    if(count==2)
    {
        if(*(data) > *(data+1))
        {
            temp=*(data);
            *(data)=*(data+1);
            *(data+1)=temp;
        }
        return;
    }
    merge_sort(middle,data);
    merge_sort(count-middle,data+middle);
    j=middle;
    while(temp_counter<count)
    {
    if(j>=count)
    {
        *(temp_ptr+temp_counter++)=*(data+i);
        i++;
    }
    else if(i>=middle)
    {
        *(temp_ptr+temp_counter++)=*(data+j);
        j++;
    }
    else if((*(data+i)<*(data+j)))
    {
        *(temp_ptr+temp_counter++)=*(data+i);
        i++;
    }
    else
    {
        *(temp_ptr+temp_counter++)=*(data+j);
        j++;
    }
    }
    temp_counter=0;
    while(temp_counter<count)
    {
    *(data+temp_counter)=*(temp_ptr+temp_counter);
        temp_counter++;
    }
    free(temp_ptr);
    return;
}

// Complete the maximumToys function below.
int maximumToys(int prices_count, int* prices, int k)
{
    int i=0,sum=0;
    merge_sort(prices_count,prices);
    for(i=0;i<prices_count;i++)
    {
        sum+=*(prices+i);
        if(sum>k)
        {
            break;
        }
    }
    return i;
}

