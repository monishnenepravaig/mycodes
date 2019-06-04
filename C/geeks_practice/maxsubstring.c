#define MAXSIZE 26
#define SAVEDSIZE 10

int max_unique_substring(uint8_t* str)
{
  int i=0,j=0,k=0,max=0,start=0,found=0,saved_counter=0,current=0;
  uint8_t* saved[SAVEDSIZE];
  uint8_t* letters=(uint8_t*)calloc(26,1);
  for(j=0;j<SAVEDSIZE;j++)
  {
    saved[j]=(uint8_t*)calloc(MAXSIZE,1);
    if(saved[j]==NULL)
    {
      printf("NULL\n");
    }  
  }
  while(*(str+i)!=0)
  {
    found=0;
    current=0;
    for(j=0;j<26;j++)
    {
      *(letters+j)=0;
    }
    while((*(str+i)!=0)&&!found)
    {
      if(letters[*(str+i)-'a'])
      {
        found=1;
      }
      else
      {
        letters[*(str+i)-'a']++;
        current++;
      }
      i++;
    }
    j=start;
    start++;
    i=start;
    //printf("current=%d,max=%d\n",current,max);
    if(current==max)
    {
      //printf("start:%d",start);
      saved_counter++;
      for(k=0;k<max;k++)
      {
        //printf("k:%d\n",k);
        *((saved[saved_counter])+k)=*(str+j++);
      }
    }
    else if(current>max)
    {
      max=current;
      saved_counter=0;
      for(k=0;k<max;k++)
      {
        //printf("k:%d\n",k);
        *((saved[saved_counter])+k)=*(str+j++);
      }
    }
  }
  printf("\nMax substring size: %d\tsaved:%d\tsubstrings:\t",max,saved_counter+1);
  for(j=0;j<=saved_counter;j++)
  {
    k=0;
    printf("%s\t",saved[j]);
  }
  printf("\n");
  for(j=0;j<SAVEDSIZE;j++)
  {
    free(saved[j]);
  }  
  return max;
}

int main() 
{  
  int max=0;
  uint8_t a[]="aabccbb";
  uint8_t b[]="abbbb";
  uint8_t c[]="abccde";
  uint8_t d[]="abcdecdefg";
  uint8_t e[]="abcdecdefgijk";
  uint8_t f[]="lmnlmnlmn";
  max=max_unique_substring(a);
  max=max_unique_substring(b);
  max=max_unique_substring(c);
  max=max_unique_substring(d);
  max=max_unique_substring(e);
  max=max_unique_substring(f);
  return 0;
}
