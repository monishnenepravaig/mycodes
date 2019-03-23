#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//138511468548
char* readline();
char** split_string(char*);


char* readline();
uint8_t Yes[]="YES";
uint8_t No[]="NO";

// Complete the minimumSwaps function below.
int minimumSwaps(int arr_count, int* arr) 
{
    int i=0,counter=0,index=0,saved=0,value=0,prev_index=0;
    for(i=0;i<arr_count;i++)
    {   
        if(*(arr+i)!=i+1)
        {
            saved=i+1;
            printf("saved=%d\n",saved);
            index=i;
            while(*(arr+index)!=saved)
            {
                value=index+1;
                prev_index=index;
                index=*(arr+prev_index)-1;
                *(arr+prev_index)=value;
                counter++;
                printf("value=%d, prev_index=%d, index=%d, counter=%d\n",value,prev_index,index,counter);
            }
            *(arr+index)=index+1;
        }
    }
    return counter;
}

char* isBalanced(char* s) 
{
    uint8_t stack[STACK_SIZE];
    uint8_t temp=0;
    int head=0,i=0;
    while(*(s+i)!=0)
    {
        temp=*(s+i++);
        switch(temp)
        {
            case '{':
            {
                *(stack+head++)=temp;
                break;
            }
            case '(':
            {
                *(stack+head++)=temp;
                break;
            }
            case '[':
            {
                *(stack+head++)=temp;
                break;
            }
            case '}':
            {
                if(*(stack+(--head))!='{')
                {
                    printf("case 1\n");
                    return No;
                }
                break;
            }
            case ']':
            {
                if(*(stack+(--head))!='[')
                {
                    printf("case 2\n");
                    return No;
                }
                break;
            }
            case ')':
            {
                if(*(stack+(--head))!='(')
                {
                    printf("case 3\n");
                    return No;
                }
                break;
            }
        }
        if(head<0)
        {
            printf("case 5\n");
            return No;
        }
    }
    if(head>1)
    {
        printf("case 6\n");
        return No;
    }
    return Yes;
}

uint8_t check_palindrome(uint8_t* str,int size)
{
    int i=0;
    uint8_t x=*str;
    for(i=0;i<size;i++)
    {
        printf("%c",*(str+i));
    }
    printf("\n");
    for(i=0;i<size/2;i++)
    {
        if((x!=*(str+i))||(x!=*(str+size-i-1)))
        {
            return 0;
        }
    }
    return 1;
}


// Complete the maxMin function below.
int maxMin(int k, int arr_count, int* arr) 
{
    int min_unfairness=0x7FFFFFFF;
    int i=0,j=0,temp=0;
    merge_sort(arr_count,arr);
    for(i=0;i<arr_count-k+1;i++)
    {
        temp=*(arr+i+k-1)-*(arr+i);
        if(temp<min_unfairness)
        {
            min_unfairness=temp;
        }
    }
    return min_unfairness;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = readline();
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* arr_item_endptr;
        char* arr_item_str = readline();
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int arr_count = n;

    int result = maxMin(k, arr_count, arr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

long sum_factorial(int number)
{
    long sum=0;
    int i=0;
    for(i=0;i<number+1;i++)
    {
        sum+=i;
    }
    return sum;
}

// Complete the substrCount function below.
long substrCount(int n, char* s) 
{
    int start=0,end=0,size=0,check=0,i=0;
    uint8_t x=0;
    long count=0;
    for(start=0;start<n;start++)
    {
        x=*(s+start);
        size=0;
        check=0;
        while(*(s+start+(++size))==x);
        printf("size=%d\n",size);
        count+=sum_factorial(size);
        printf("n:count=%d\n",count);
        for(i=0;i<size;i++)
        {
            check=check_palindrome(s+start+i,(size-i)*2+1);
            if(check==1)
            {
                count+=1;
                printf("p:count=%d\n",count);
            }
        }
        start+=size-1;
    }
    return count;
}

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

// Complete the repeatedString function below.
long repeatedString(char* s, long n)
{
    long total=0,quo=0;
    int count=0,len=strlen(s),i=0,a[len],rem=0;
    for(i=0;i<len;i++)
    {
        if(*(s+i)=='a')
        {
            count++;
        }
        a[i]=count;
    }
    quo=n/len;
    rem=n%len;
    if(count==0)
    {
        return count;
    }
    if(rem>0)
    {
        total=count*quo+a[rem-1];
    }
    else
    {
        total=count*quo;
    }
    return total;
}

int fibonacci(int n)
{
    if(memory[n]>=0)
    {
        return memory[n];
    }
    memory[n]=fibonacci(n-1)+fibonacci(n-2);
    return memory[n];
}

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(int c_count, int* c)
{
    int jumps=0,i=0;
    for(i=0;i<c_count;i++)
    {
        if(*(c+i+2)==0)
        {
            i++;
        }
        jumps++;
    }
    jumps--;
    return jumps;
}

// Complete the countingValleys function below.
int countingValleys(int n, char* s)
{
    int valleys=0,level=0,min_level=0;
    while(*s!=0)
    {
        if(*s=='U')
        {
            level++;
        }
        else if(*s=='D')
        {
            level--;
        }
        if(min_level>level)
        {
            min_level=level;
        }
        if((level>min_level)&&(level==0))
        {
            min_level=level;
            valleys++;
        }
        s++;
    }
    return valleys;
}

// Complete the sockMerchant function below.
int sockMerchant(int n, int ar_count, int* ar)
{
    int pairs=0,prev=0;
    merge_sort(ar_count,ar);
    while(*ar!=0)
    {
        if(prev==*ar)
        {
            pairs++;
            prev=0;
        }
        else
        {
            prev=*ar;
        }
        ar++;
    }
    return pairs;
}

// Complete the alternatingCharacters function below.
int alternatingCharacters(char* s)
{
    int deletions=0;
    uint8_t prev=0;
    while(*s!=0)
    {
        if(prev==*s)
        {
            deletions++;
        }
        else
        {
            prev=*s;
        }
        s++;
    }
    return deletions;
}

// Complete the makeAnagram function below.
int makeAnagram(char* a, char* b)
{
    int i=0,j=0,deletions=0;
    int len_a=strlen(a);
    int len_b=strlen(b);
    merge_sort(len_a,a);
    merge_sort(len_b,b);
    while((*(a+i)!=0)&&(*(b+j)!=0))
    {
        if(*(a+i)==*(b+j))
        {
            i++;
            j++;
        }
        else if(*(a+i)<*(b+j))
        {
            i++;
            deletions++;
        }
        else if(*(a+i)>*(b+j))
        {
            j++;
            deletions++;
        }
    }
    deletions+=(len_a-i)+(len_b-j);
    return deletions;
}

void countSwaps(int a_count, int* a)
{
    int count=0,i=0,j=0,temp=0;
    for(i=0;i<a_count;i++)
    {
        for(j=i;j<a_count;j++)
        {
            if(*(a+i)>*(a+j))
            {
                temp=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
                count++;
            }
        }
    }
    printf("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d",count,*(a),*(a+a_count-1));
}

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

// Complete the flippingBits function below.
long flippingBits(long n)
{
    long a=0xFFFFFFFF;
    n=a-n;
    printf("%ld",n);
    return n;
}

char* primality(int n)
{
    char* np= "Not prime";
    char* p="Prime";
    int i=2;
    if(n==1)
    {
        return np;
    }
    while(i*i<=n)
    {
        if(n%i==0)
        {
            return np;
        }
        i++;
    }
    return p;
}

// Complete the luckBalance function below.
int luckBalance(int k, int contests_rows, int contests_columns, int** contests)
{
    int i=0,luck=0,lost=0,count=0;
    int lowest[contests_rows];
    for(i=0;i<contests_rows;i++)
    {
        lowest[i]=-1;
    }
    for(i=0;i<contests_rows;i++)
    {
        if(*(*(contests+i)+1)==0)
        {
            luck+=*(*(contests+i));
        }
        else if ((*(*(contests+i)+1)==1))
        {
            lowest[count++]=*(*(contests+i));
        }
    }
    merge_sort(count,lowest);
    for(i=0;i<count;i++)
    {
        if(i<k)
        {
            luck+=lowest[i];
        }
        else
        {
            luck-=lowest[i];
        }
    }
    return luck;
}

void checkMagazine(int magazine_count, char** magazine, int note_count, char** note)
{
    int i=0,j=0,k=0,matched=0,not_matched=0,not_matched_flag=1,matched_flag=0,len=0;
    char* empty="";
    for(i=0;i<note_count;i++)
    {
        not_matched_flag=1;
        len=strlen(*(note+i));
        for(j=0;j<magazine_count;j++)
        {
            k=len;
            matched_flag=1;
            while((*(*(note+i)+k)!=0)||(*(*(magazine+j)+k)!=0)||(k>=0))
            {
                if((*(*(note+i)+k)!=*(*(magazine+j)+k)))
                {
                    matched_flag=0;
                    break;
                }
                k--;
            }
            if(matched_flag)
            {
                matched++;
                not_matched_flag=0;
                *(magazine+j)=empty;
                break;
            }
        }
        if(not_matched_flag)
        {
            not_matched++;
        }
        if((i+not_matched>magazine_count)||(not_matched>magazine_count-note_count))
        {
            break;
        }
    }
    if(matched==note_count)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}

char* twoStrings(char* s1, char* s2)
{
    char* yes="YES";
    char* no="NO";
    char ascii[256];
    uint16_t i=0;
    for(i=0;i<256;i++)
    {
        ascii[i]=0;
    }
    while(*s1!=0)
    {
        ascii[*s1++]=1;
        s1++;
    }
    while(*s2!=0)
    {
        if(ascii[*s2]==1)
        {
            return yes;
        }
        s2++;
    }
    return no;
}

void merge_sort(int32_t count,int32_t* data)
{
    int32_t temp=0,middle=count/2,i=0,j=0,temp_counter=0;
    int32_t* temp_ptr = (int32_t*)malloc(count*4);
    if((count==1)||(count==0))
    {
        return;
    }
    if(count==2)
    {
        if(*(data) > *(data+1))
        {
            temp=*(data);
            *(data)=*(data+1);
            *(data+1)=temp;
        }
        return;
    }
    merge_sort(middle,data);
    merge_sort(count-middle,data+middle);
    j=middle;
    while(temp_counter<count)
    {
    if(j>=count)
    {
        *(temp_ptr+temp_counter++)=*(data+i);
        i++;
    }
    else if(i>=middle)
    {
        *(temp_ptr+temp_counter++)=*(data+j);
        j++;
    }
    else if((*(data+i)<*(data+j)))
    {
        *(temp_ptr+temp_counter++)=*(data+i);
        i++;
    }
    else
    {
        *(temp_ptr+temp_counter++)=*(data+j);
        j++;
    }
    }
    temp_counter=0;
    while(temp_counter<count)
    {
    *(data+temp_counter)=*(temp_ptr+temp_counter);
        temp_counter++;
    }
    free(temp_ptr);
    return;
}

// Complete the maximumToys function below.
int maximumToys(int prices_count, int* prices, int k)
{
    int i=0,sum=0;
    merge_sort(prices_count,prices);
    for(i=0;i<prices_count;i++)
    {
        sum+=*(prices+i);
        if(sum>k)
        {
            break;
        }
    }
    return i;
}

int getHeight(struct node* root)
{
    int rh=0,lh=0;
    if((root->right==NULL)&&(root->left==NULL))
    {
        return 0;
    }
    else if(root->right==NULL)
    {
        return 1+getHeight(root->left);
    }
    else if(root->left==NULL)
    {
        return 1+getHeight(root->right);
    }
    rh=1+getHeight(root->right);
    lh=1+getHeight(root->left);
    if(rh>lh)
    {
        return rh;
    }
    else
    {
        return lh;
    }
}

struct node *lca( struct node *root, int v1, int v2 )
{
    if(((v1<root->data)&&(v2>root->data))||((v1>root->data)&&(v2<root->data)))
    {
        return root;
    }
    else if(v1<root->data)
    {
        return lca(root->left,v1,v2);
    }
    else if(v1>root->data)
    {
        return lca(root->right,v1,v2);
    }
    return root;
}

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data)
{
    DoublyLinkedListNode* head_ptr=head;
    DoublyLinkedListNode* temp_ptr;
    DoublyLinkedListNode* New_node=(DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    while(data>head->data)
    {
        if(head->next!=NULL)
        {
            head=head->next;
        }
        else
        {
            head->next=New_node;
            New_node->prev=head;
            New_node->next=NULL;
            New_node->data=data;
            return head_ptr;
        }
    }
    if(head->prev!=NULL)
    {
        head->prev->next=New_node;
        New_node->prev=head->prev;
    }
    else
    {
        head_ptr=New_node;
        New_node->prev=NULL;
    }
    head->prev=New_node;
    New_node->next=head;
    New_node->data=data;
    return head_ptr;
}

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head)
{
    DoublyLinkedListNode* current_ptr=head;
    DoublyLinkedListNode* next_ptr;
    while(current_ptr->next!=NULL)
    {
        next_ptr=current_ptr->next;
        current_ptr->next=current_ptr->prev;
        current_ptr->prev=next_ptr;
        current_ptr=next_ptr;
    }
    next_ptr=current_ptr->next;
    current_ptr->next=current_ptr->prev;
    current_ptr->prev=next_ptr;
    return current_ptr;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    int found=0;
    SinglyLinkedListNode* checker=head1;
    while(head2!=NULL)
    {
        while(checker!=NULL)
        {
            if(head2==checker)
            {
                return checker->data;
            }
            checker=checker->next;
        }
        checker=head1;
        head2=head2->next;
    }
    return checker->data;
}

bool has_cycle(Node* head)
{
    int count=0;
    while(head!=NULL)
    {
        if(count>101)
        {
            return 1;
        }
        count++;
        head=head->next;
    }
    return 0;
}

bool checkBST(Node* root)
    {
        Node* temp;
		if((root->right==NULL)&&(root->left==NULL))
        {
            return 1;
        }
        else if(checkBST(root->right)&&checkBST(root->left))
        {
            temp=root->left;
            while(temp!=NULL)
            {
                if(temp->data>=root->data)
                {
                    return 0;
                }
                temp=temp->right;
            }
            temp=root->right;
            while(temp!=NULL)
            {
                if(temp->data<=root->data)
                {
                    return 0;
                }
                temp=temp->left;
            }
            return 1;
        }
        else
        {
            return 0;
        }
	}


void decode_huff(node * root, string s)
{
    const uint8_t* str = reinterpret_cast<const uint8_t*>(s.c_str());
    uint8_t final[100],condition=0,i=0,error=0;
    uint8_t* final_ptr=final;
    node* temp = root;
    for(i=0;i<100;i++)
    {
        final[i]=0;
    }
    while((*str!=0)&&!(error))
    {
        temp = root;
        condition=1;
        while(condition)
        {
            if(*str=='1')
            {
                temp=temp->right;
            }
            else if(*str=='0')
            {
                temp=temp->left;
            }
            else
            {
                condition=0;
                error=1;
                printf("Error");
            }
            if(temp->right==NULL)
            {
                *final_ptr=temp->data;
                condition=0;
                final_ptr++;
            }
            str++;
        }
    }
    printf("%s",final);
}

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)
    {
        if(a.score>b.score)
        {
            return 1;
        }
        else if(a.score<b.score)
        {
            return -1;
        }
        else
        {
            if(a.name<b.name)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
};

// Complete the getMinimumCost function below.
int getMinimumCost(int k, int c_count, int* c)
{
    int flower_counter=0,person_counter=0,i=0,price=0,prev=0;
    merge_sort(c_count,c);
    while(flower_counter<c_count)
    {
        person_counter=0;
        while((person_counter<k)&&flower_counter<c_count)
        {
            price+=*(c+i++)*(1+prev);
            flower_counter++;
            person_counter++;
        }
        prev++;
    }
    return price;
}

// Complete the stepPerms function below.
int stepPerms(int n)
{
    int steps=0,i=0,dummy=0;
    static int steps_mem[]={0,1,2,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    if(n<1)
    {
        return 0;
    }
    else if(steps_mem[n]!=0)
    {
        steps=steps_mem[n];
    }
    else
    {
        for(i=5;i<n;i++)
        {
            if(steps_mem[i]==0)
            {
                dummy=stepPerms(i);
            }
        }
        steps=stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3);
    }
    steps_mem[n]=steps;
    return steps;
}
