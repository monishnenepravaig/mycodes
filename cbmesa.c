#include <stdio.h>
int count=0;  //global variable count
int total=10; //total size of circular buffer

float circularbuffer(int a, int* base)	
{
int i;
float average,sum=0;
if(count==total-1)
{
	count=0; //reset counter at end of the circular buffer
}
else
{
	count++; 
}
*(base + count)=a;
for(i=0;i<10;i++)
{
sum = sum + *(base + i); //add all numbers in circular buffer
}
average=sum/total; //average of numbers in circular buffer
return average;
}

void main()
{
int cb[total],a; //declare circular buffer as an array with variable size
float average;
int* base=cb;
for(a=0;a<total;a++)//initialize circular buffer with 0 to avoid 
{
*(base+a)=0;
}	
while(1)
{
printf("\n Enter the next number \n");
scanf("%d",&a);
average=circularbuffer(a,base); //function call to circular buffer
0000.
printf("\n The new average = %f \n",average);
}	
}

