#include <stdio.h>

void main()
{
	char* pNumbers="0123456789";
	char* pTemp;
	int num1,num2,num3,num4,num5;
	char letter1, letter2;
	pTemp = pNumbers;
	num1=(int)pTemp;
	num2=(int)pTemp[0];
	printf("%d",num2);
}
