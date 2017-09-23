/*
 * Reverse.c
 *
 *  Created on: Sep 14, 2017
 *      Author: Monish
 */

char reverse(char* str,int length)
{
 char *temp;
 char a="\n",b="\0",c="\t"; 
 int i,j,k=0,n; for(j=0;j<length-1;j++)
{
 if(*(str+j)==a||*(str+j)==b||*(str+j)==c)
 {
 k=1;
 printf("k=1;");
 break;
 }
}

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
   return k;
}

int main()
{
int i,n=17,k;
char arr1[]="This is a string.";
printf("The original string is: %s \n",arr1);
k = reverse(&arr1,n);
printf("The reverse string is: %s \n",arr1);
n=18;
char arr2[]="some NUMmbers12345";
printf("The original string is: %s \n",arr2);
k = reverse(&arr2,n);
printf("The reverse string is: %s \n",arr2);
n=30;
char arr3[]="Does it reverse \n\0\t correctly?";
printf("The original string is: %s \n",arr3);
k = reverse(&arr3,n);
printf("The reverse string is: %s \n",arr3);
return k;
}
