#include <stdio.h>
int count=0;
int total=10.0;


float circularbuffer(int a, int* base)	
{
int i;
float average,sum=0;
if(count==total-1)
{
	count=0;
}
else
{
	count++;
}
*(base + count)=a;
for(i=0;i<10;i++)
{
sum = sum + *(base + i);
}
average=sum/total;
return average;
}

void main()
{
int cb[total],a;
float average;
int* base=cb;
for(a=0;a<total;a++)
{
*(base+a)=0;
}	
while(1)
{
printf("\n Enter the next number \n");
scanf("%d",&a);
average=circularbuffer(a,base);
printf("\n The new average = %f \n",average);
}	
}	
	
