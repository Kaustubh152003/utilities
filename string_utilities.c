#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int size_of_str(char* str)
{
    int j=0;
    while(str[j]!='\0')
    j++;
    return j;
}
void print_till_x(char* str,int x) // prints the string only till the xth character
{
    int j=0;
    while(str[j]!='\0' && j<x)
    {
        printf("%c",str[j]);
        j++;
    }
}
int srsl(char* str) //return the size of smallest repeating string which forms thr string str (basically [str,str+p) is the smallest repeating string)
{
    int j=0;
    while(str[j]!='\0')
    j++;
    int n=j;
    int p=1;
    j=1;
    int flag=0;
    while(str[j]!='\0' && flag==0)
    {
        
        if(n%p==0)
        {
            int k=p;
            while(k<n && check(str,p,str+k)==1)
            k=k+p;
            if(k==n)
            {
                flag=1;
                break;
            }
            else
            p++;
        }
        else
        p++;
    }
    return p;
}
