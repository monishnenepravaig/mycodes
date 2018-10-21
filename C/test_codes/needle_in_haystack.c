#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define True 1
#define False 0
 
uint8_t search_str(uint8_t* haystack,uint8_t* needle)
{
	uint8_t i=0,j=0,match_counter=0,len=0,temp=0;
	len=strlen(needle);
	while(*(haystack+i)!=0)
	{
		if(*(haystack+i++)==*(needle+j++))
		{
			match_counter++;
			temp=i;
			if(match_counter==len)
			{
						return True;
			}
			while(*(needle+j)!=0)
			{
				if(*(haystack+i++)==*(needle+j++))
				{
					match_counter++;
					if(match_counter==len)
					{
						return True;
					}
				}
				else
				{
					i=temp;
					j=0;
					break;				
				}
			}
		}
		else
		{
				j=0;
				match_counter=0;	
		}
	}
	return False;
}

void main()
{
	uint8_t i=0,j=0,k=0;
	i=search_str("needle present in haystack","needle");
	j=search_str("haystack lol","needle");
	k=search_str("wwuwaaia","ai");
	printf("%d%d%d\n",i,j,k);
}
