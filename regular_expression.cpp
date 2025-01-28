#include <bits/stdc++.h>
using namespace std;
int** make_grid(int n,int m) //makes and returns a grid of size n x m
{
    int** table=(int**)malloc(sizeof(int*)*n);
    int j=0;
    while(j<n)
    {
        int* ptr=(int*)malloc(sizeof(int)*m);
        table[j]=ptr;
        j++;
    }
    return table;
}
void initialize_grid(int** table,int n,int m,int val)
{
    int j=0;
    while(j<n)
    {
        int k=0;
        while(k<m)
        {
            table[j][k]=val;
            k++;
        }
        j++;
    }
}
int func(char* pattern,int x,int n,char* str,int y,int m,int** table)
{
    if(x<n && y<m)
    {
        if(table[x][y]==-1)
        {
            if(pattern[x]=='*')
            {
                int j=y;
                int z=0;
                while(j<=m && z==0)
                {
                    z=func(pattern,x+1,n,str,j,m,table);
                    j++;
                }
                table[x][y]=z;
                return z;
            }
            else
            {
                if(pattern[x]==str[y] || pattern[x]=='?')
                table[x][y]=func(pattern,x+1,n,str,y+1,m,table);
                else
                table[x][y]=0;
            }
        }
        return table[x][y];
    }
    else
    {
        // printf("ola : ");
        // printf("%d %d\n",x,y);
        if(x==n && y==m)
        return 1;
        else
        {
            if(x<n)
            {
                while(pattern[x]=='*' && x<n)
                x++;
                if(x==n)
                return 1;
                else
                return 0;
            }
            else
            return 0;
        }
    }
}
char* string_to_charr(string s)
{
    int j=0;
    char* str=(char*)malloc((s.length()+1)*sizeof(char));
    while(j<s.length())
    {
        str[j]=s[j];
        j++;
    }
    str[j]='\0';
    return str;
}
int regular_expression_check(string pattern, string str) 
{
    int m=str.length();
    int n=pattern.length();
    char* p=string_to_charr(pattern);
    char* s=string_to_charr(str);
    int** table=make_grid(n,m);
    initialize_grid(table,n,m,-1);
    // print_grid(table,n,m);
    return func(p,0,n,s,0,m,table);
}
