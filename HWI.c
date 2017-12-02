#include <stdio.h>
#include <stdint.h>
#define state_1B 0
#define state_1R 1
#define state_1W 2
#define state_2B 3
#define state_2R 4
#define state_2W 5
#define state_3B 6
#define state_3R 7
#define state_3W 8
	
void flip(uint8_t* value)
{
	if(*value == 0)
	{
		*value=1;
	}
	else
	{
		*value=0;
	}
	return;
}

void main()
{
	uint8_t a=0,b=0,c=0,x=0,y=0,z=0,state=0,input=0,y_time=0,x_time=0;
	uint8_t* a_ptr=&a;
	uint8_t* b_ptr=&b;
	uint8_t* c_ptr=&c;
	uint8_t* x_ptr=&x;
	uint8_t* y_ptr=&y;
	uint8_t* z_ptr=&z;
	state = state_1R;	
	while(1)
	{	
		flip(z_ptr);
		if(y_time==2)
		{
			flip(y_ptr);
			y_time=0;
		}
		if(x_time==4)
		{
			flip(x_ptr);
			x_time=0;
		}
		printf("\n\r a=%d, b=%d, c=%d, x=%d, y=%d, z=%d",a,b,c,x,y,z);
		printf("\n\r Enter next input");
		while(1)		
		{				
			input=getchar();
			if((input=='a')||(input=='b')||(input=='c'))
			{
				break;			
			}
		}
		if(input=='a')
		{
			flip(a_ptr);
			printf("\n\rvalue of a = %d",a);
		}
		else if(input=='b')
		{
			flip(b_ptr);
			printf("\n\rvalue of b = %d",b);
		}
		else if(input=='c')
		{
			flip(c_ptr);
			printf("\n\rvalue of c = %d",c);
		}
		else if(input=='x')
		{
			flip(x_ptr);
			printf("\n\rvalue of x = %d",x);
		}
		else if(input=='y')
		{
			flip(y_ptr);
			printf("\n\rvalue of y = %d",y);
		}
		else if(input=='z')
		{
			flip(z_ptr);
			printf("\n\rvalue of z = %d",z);
		}
		switch(state)
		{

			/*case state_1B:
			{
			printf("\n\rcurrent state is 1B");
			if(a==0)
			{
				state=state_2R;
				printf("\n\rnext state is 2R");
			}
			else
			{
				state=state_1R;
				printf("\n\rnext state is 1R");
			}	
			break;
			}

			case state_1R:
			printf("\n\rCurrent state is 1R");
			{
			if(a==0)
			{
				state=state_1B;
				printf("\n\rnext state is 1B");
			}
			else if (x==1)
			{
				state=state_1W;
				printf("\n\rnext state is 1W");
			}	
			break;
			}

			case state_1W:
			printf("\n\rCurrent state is 1W");
			{
			if(x==0)
			{
				state=state_1R;
				printf("\n\rnext state is 1R");
			}
			else
			{
				state=state_2R;
				printf("\n\rnext state is 2R");
			}	
			break;
			}

			case state_2B:
			printf("\n\rCurrent state is 2B");
			{
			if(a==1)
			{
				state=state_1B;
				printf("\n\rnext state is 1B");
			}
			else
			{
				if(b==1)
				{
					state=state_2R;
					printf("\n\rnext state is 2R");
				}
				else
				{
					state=state_3R;
					printf("\n\rnext state is 3R");
				}
			}	
			break;
			}

			case state_2R:
			printf("\n\rCurrent state is 2R");
			{
			if((a==1)&&(x==0))
			{
				state=state_1R;
				printf("\n\rnext state is 1R");
			}
			else if (x==0)
			{
				state=state_1W;
				printf("\n\rnext state is 1W");
			}
			else if (a==1)
			{
				state=state_1B;
				printf("\n\rnext state is 1B");
			}	
			else if (b==0)
			{
				state=state_2B;
				printf("\n\rnext state is 2B");
			}
			else if (y==1)
			{
				state=state_2W;
				printf("\n\rnext state is 2W");
			}
			break;
			}

			case state_2W:
			printf("\n\rCurrent state is 2W");
			{
			if(x==0)
			{
				state=state_1W;
				printf("\n\rnext state is 1W");
			}
			else
			{
				if(y==0)
				{	
					state=state_2R;
					printf("\n\rnext state is 2R");
				}
				else
				{
					state=state_3R;
					printf("\n\rnext state is 3R");					
				}
			}	
			break;
			}

			case state_3B:
			printf("\n\rCurrent state is 3B");
			{
			if(a==1)
			{
				state=state_1B;
				printf("\n\rnext state is 1B");
			}
			else if(b==1)
			{
				state=state_2B;
				printf("\n\rnext state is 2B");
			}	
			else if(c==1)
			{
				state=state_3R;
				printf("\n\rnext state is 3R");
			}	
			break;
			}

			case state_3R:
			printf("\n\rCurrent state is 3R");
			{
			if((b==1)&&(y==0))
			{
				state=state_2R;
				printf("\n\rnext state is 2R");
			}
			else if (y==0)
			{
				state=state_2W;
				printf("\n\rnext state is 2W");
			}
			else if (b==1)
			{
				state=state_2B;
				printf("\n\rnext state is 2B");
			}	
			else if (c==0)
			{
				state=state_3B;
				printf("\n\rnext state is 3B");
			}
			else if (z==1)
			{
				state=state_3W;
				printf("\n\rnext state is 3W");
			}
			break;
			}
			
			case state_3W:
			printf("\n\rCurrent state is 3W");
			{
			if(x==0)
			{
				state=state_1W;
				printf("\n\rnext state is 1W");
			}
			else if(y==0)
			{
				state=state_2W;
				printf("\n\rnext state is 2W");
			}	
			else if(z==0)
			{
				state=state_3R;
				printf("\n\rnext state is 3R");
			}	
			break;
			}*/

			
			case state_3R:			
			{
				printf("\n\rCurrent state is 3R");
				if((z==1)||(c==0))
				{
					state=state_1R;
					printf("\n\rnext state is 1R");
				}
				break;
			}
			
			case state_2R:
			{
				printf("\n\rCurrent state is 2R");
				state=state_3R;
				printf("\n\rnext state is 3R");
				break;
			}

			case state_1R:
			{
				printf("\n\rCurrent state is 1R");
				if((a==0)||(x==1))
				{
					state=state_2R;
					printf("\n\rnext state is 2R");
				}	
				break;
			}

		}
		y_time++;
		x_time++;
	}
}
