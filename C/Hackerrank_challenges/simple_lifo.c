#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100000

int queue[SIZE];
int head=0,tail=0;

void push(int number)
{
    *(queue+head)=number;
    head=(head<SIZE-1)?head+1:0;
}

int pop()
{
    int temp = *(queue+tail);
    tail=(tail<SIZE-1)?tail+1:0;
    return temp;
}

void peek()
{
    printf("%d\n",*(queue+tail));
}

int main() 
{
    int queries=0,i=0;
    int type=0,number=0;
    scanf("%d",&queries);
    //printf("queries = %d\n",queries);
    for(i=0;i<queries;i++)
    {
        number=0;
        scanf("%d",&type);
        //printf("type: %d\n",type);
        switch(type)
        {
            case 1:
                {
                    scanf("%d",&number);
                    push(number);
                    break;
                }

            case 2:
                {
                    number=pop();
                    break;
                }

            case 3:
                {
                    peek();
                    break;
                }
        }
    }
    return 0;
}
