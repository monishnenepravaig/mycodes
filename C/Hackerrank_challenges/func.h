void plusMinus(int arr_count, int* arr) {
    int c1=0,c2=0,c3=0; 
    float r1=0,r2=0,r3=0;
    for(int i=0;i<arr_count;i++)
    {
        if(*(arr+i)>0){
            c1++;
        }
        else if (*(arr+i)<0){
            c2++;
        }
        else {
            c3++;
        }
    }
    r1=(float)c1/arr_count;
    r2=(float)c2/arr_count;
    r3=(float)c3/arr_count;
    printf("%f\n\r%f\n\r%f",r1,r2,r3);    
}
