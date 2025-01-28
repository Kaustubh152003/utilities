#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void initialize_random()
{
    srand(time(0));
}
int get_random_in_range(int a,int b) //return a random number between a and b
{
    if(a>b)
    b=a;
    int x = rand();
    x=x%(b-a+1);
    x=x+a;
    return x;
}
int* get_random_array_of_fixed_size(int n,int element_lower_limit,int element_upper_limit)
{
    int j=0;
    int* arr=(int*)malloc(sizeof(int)*n);
    while(j<n)
    {
        arr[j]=get_random_in_range(element_lower_limit,element_upper_limit);
        j++;
    }
    return arr;
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
int main() 
{
    initialize_random();
    int* arr=get_random_array_of_fixed_size(10,1,100);
    print_array(arr,10);

    return 0;
}
