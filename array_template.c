void reverse_array(int* arr,int n)
{
    int j=0;
    int p=n-1;
    while(j<p)
    {
        int temp=arr[p];
        arr[p]=arr[j];
        arr[j]=temp;
        p--;
        j++;
    }
}
void print_array(int* arr,int n)
{
    int j=0;
    while(j<n)
    {
        printf("%d ",arr[j]);
        j++;
    }
}
void scan_array(int* arr,int n)
{
    int j=0;
	    while(j<n)
	    {
	        scanf("%d ",arr+j);
	        j++;
	    }
}
int min_array(int* arr,int n)
{
    int j=0;
    int min=arr[0];
    while(j<n)
    {
        if(arr[j]<min)
        min=arr[j];
        j++;
    }
    return min;
}
int max_array(int* arr,int n)
{
    int j=0;
    int max=arr[0];
    while(j<n)
    {
        if(arr[j]>max)
        max=arr[j];
        j++;
    }
    return max;
}
