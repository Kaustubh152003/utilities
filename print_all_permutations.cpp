#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
void print_array(int* arr,int n)
{
    int j=0;
    while(j<n)
    {
        printf("%d ",arr[j]);
        j++;
    }
}
int* duplicate_array(int* arr,int n,int* target)
{
    int j=0;
    while(j<n)
    {
        target[j]=arr[j];
        j++;
    }
    return arr;
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
void permfunc(int* rem,int n,int* perm,int p)
{
    if(n==0)
    {
        print_array(perm,p);
        printf("\n");
    }
    else
    {
        int j=0;
        while(j<n)
        {
            int x=rem[j];
            int* newrem;
            if(n>1)
            newrem=(int*)malloc(sizeof(int)*(n-1));
            else
            newrem=0;
            int k=0;
            int l=0;
            while(k<n)
            {
                if(k!=j)
                {
                    newrem[l]=rem[k];
                    k++;
                    l++;
                }
                else
                k++;
            }
            int* newperm=(int*)malloc(sizeof(int)*(p+1));
            k=0;
            while(k<p)
            {
                newperm[k]=perm[k];
                k++;
            }
            newperm[k]=x;
            permfunc(newrem,n-1,newperm,p+1);
            j++;
        }
    }
}
void print_permutations(int* arr,int n)
{
    permfunc(arr,n,0,0);
}
void uniquepermfunc(int* rem,int n,int* perm,int p)
{
    if(n==0)
    {
        print_array(perm,p);
        printf("\n");
    }
    else
    {
        int j=0;
        while(j<n)
        {
            int x=rem[j];
            int* newrem;
            if(n>1)
            newrem=(int*)malloc(sizeof(int)*(n-1));
            else
            newrem=0;
            int k=0;
            int l=0;
            while(k<n)
            {
                if(k!=j)
                {
                    newrem[l]=rem[k];
                    k++;
                    l++;
                }
                else
                k++;
            }
            int* newperm=(int*)malloc(sizeof(int)*(p+1));
            k=0;
            while(k<p)
            {
                newperm[k]=perm[k];
                k++;
            }
            newperm[k]=x;
            uniquepermfunc(newrem,n-1,newperm,p+1);
            while(j<n && rem[j]==x)
            j++;
        }
    }
}
void print_unique_permutations(int* arr,int n)
{
    sort(arr,arr+n);
    uniquepermfunc(arr,n,0,0);
}
int main() 
{
    int n;
    scanf("%d ",&n);
    int arr[n];
    scan_array(arr,n);
    print_unique_permutations(arr,n);
    return 0;
}
