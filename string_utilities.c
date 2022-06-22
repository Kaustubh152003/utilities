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
