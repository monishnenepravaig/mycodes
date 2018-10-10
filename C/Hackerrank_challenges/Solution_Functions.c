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

/***********************************************************************
 * rotLeft()
 * Author: Monish Nene
 * Date: 09/28/2018
 * @brief Rotating an array n number of times
 * @param a_count size of array
 * @param a array pointer
 * @param d number of rotations
 * @param result_count pointer to return size of result array
 * @return maximum sum of hourglass shape in the given matrix
***********************************************************************/
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

/***********************************************************************
 * hourglassSum()
 * Author: Monish Nene
 * Date: 09/26/2018
 * @brief Finding the maximum sum of hourglass shape in the given matrix
 * @param arr_rows no. of rows
 * @param arr_columns no. of columns
 * @param arr data pointer
 * @return maximum sum of hourglass shape in the given matrix
***********************************************************************/
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
