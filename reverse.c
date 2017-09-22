/*
 * Reverse.c
 *
 *  Created on: Sep 14, 2017
 *      Author: Monish
 */

char reverse(char *str,int length)
{
   char *temp;
   int i,n;
   if(length%2==0)
    {

	n=length/2;
    }
   else
    {
	n=(length-1)/2;
    }
   for(i=0;i<n;i++)
    {
	 temp = *(str+i);
	 *(str+i) = *(str+length-i-1);
	 *(str+length-i-1) = temp;
    }
   return 0;
}

int main()
{

int i,n,k;
printf("Enter the number of chars in array \n");
scanf("%d",&n);
char arr[n];
printf("Enter the array \n");
scanf("%s",&arr);
printf("The original string is %s \n",arr);
k = reverse(&arr,n);
printf("The reverse string is: %s \n",arr);
return k;
}
