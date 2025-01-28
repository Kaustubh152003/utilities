#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void scan_array(int* arr,int n)
{
    	int j=0;
	while(j<n)
	{
	    scanf("%d ",arr+j);
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
void initialize_array(int* arr,int n,int k)
{
    int j=0;
    while(j<n)
    {
        arr[j]=k;
        j++;
    }
}
int* duplicate_array(int* arr,int n)
{
    int* ans=(int*)malloc(sizeof(int)*n);
    int j=0;
    while(j<n)
    {
        ans[j]=arr[j];
        j++;
    }
    return ans;

}
void copy_array(int* arr,int n,int* target)
{
    int j=0;
    while(j<n)
    {
        target[j]=arr[j];
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
long long array_sum(int* arr,int n)
{
    int j=0;
    long long sum=0;
    while(j<n)
    {
        sum=sum+(long long)arr[j];
        j++;
    }
    return sum;
}
void print_string_from_intarray(int* arr,int n)
{
    int j=0;
    while(j<n)
    {
        printf("%c",arr[j]);
        j++;
    }
}
void concatinate(int* arr1,int n1,int* arr2,int n2,int* target)
{
        int j=0;
        while(j<n1)
        {
            target[j]=arr1[j];
            j++;
        }
        int p=0;
        while(p<n2)
        {
            target[j]=arr2[p];
            p++;
            j++;
        }
}
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
int* vector_to_array(vector<int> v,int* array_size)
{
		int n=v.size();
		int* arr=(int*)malloc(sizeof(int)*n);
		int j=0;
		while(j<n)
		{
				arr[j]=v[j];
				j++;
		}
		*array_size=n;
		return arr;
}
long long * prefix_sum(int* arr,int n)
{
    long long* ans=(long long*)malloc(n*sizeof(long long));
    ans[0]=arr[0];
    int j=1;
    while(j<n)
    {
        ans[j]=ans[j-1]+(long long)(arr[j]);
        j++;
    }
    return ans;
}