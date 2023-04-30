#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void swap(char* a,char* b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void reverse(char* str, int n)
{
    int j=0;
    int p=n-1;
    while(j<p)
    {
        swap(str+j,str+p);
        j++;
        p--;
    }
}
int isPalindrome(char *str)
{
    int j=0;
    while(str[j]!='\0')
    j++;
    int n=j;
    n--;
    j=0;
    while(j<n && str[j]==str[n])
    {
        j++;
        n--;
    }
    if(j>=n)
    return 1;
    else
    return 0;
    
}
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
int check(char* s1,int n,char* s2)
{
    int j=0;
    while(s1[j]!='\0' && s2[j]!='\0' && s1[j]==s2[j] && j<n)
    j++;
    if(j==n)
    return 1;
    else
    return 0;
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
long long get_int(char* str) 
{
        int j=0;
        long long num=0;
        long long sign=1;
        if(str[j]=='-')
        {
            sign=-1;
            j++;
        }
        while(str[j]!='\0')
        {
            if(str[j]<'0' || str[j]>'9')
            return -1;
            else
            {
                num=num*10+str[j]-'0';
                j++;
            }
        }
        return sign*num;
}
string from_charstar_to_string(char* str)
{
    int j=0;
    string s;
    while(str[j]!='\0')
    {
        s.push_back(str[j]);
        j++;
    }
    return s;
}
void copy_strtostr(char* str,char* c)
{
    int j=0;
    while(c[j]!='\0')
    {
        str[j]=c[j];
        j++;
    }
    str[j]='\0';

}
char* from_string_to_charstar(string s)
{
    int j=0;
    char* str=(char*)malloc(s.length()*sizeof(char));
    while(j<s.length())
    {
        str[j]=s[j];
        j++;
    }
    str[j]='\0';
    return str;
}
void concatinate(char* target,char* str)
{
    int j=0;
    while(target[j]!='\0')
    j++;
    int k=0;
    while(str[k]!='\0')
    {
        target[j]=str[k];
        k++;
        j++;
    }
    target[j]='\0';
}
