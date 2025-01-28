#include <bits/stdc++.h>
using namespace std;
int** multiply_matrix(int** mat1,int x1,int y1,int** mat2,int x2,int y2,int* x,int* y)
{
    if(y1==x2)
    {
        int** mat3=(int**)malloc(x1*sizeof(int*));
        int j=0;
        while(j<x1)
        {
            int k=0;
            int* arr=(int*)malloc(y2*sizeof(int));
            while(k<y2)
            {
                int sum=0;
                int x=0;
                int y=0;
                while(y<y1 && x<x2)
                {
                    sum=sum+mat1[j][y]*mat2[x][k];
                    x++;
                    y++;
                }
                arr[k]=sum;
                k++;
            }
            mat3[j]=arr;
            j++;
        }
        *x=x1;
        *y=y2;
        return mat3;
    }
    else
    {
        printf("Matrix multiplication not possible\n");
        return 0;
    }
}
int** convert_vm_to_am(vector<vector<int>> mat,int* x,int* y)
{
    int n=mat.size();
    int m=mat[0].size();
    int j=0;
    int** ans=(int**)malloc(n*sizeof(int*));
    while(j<n)
    {
        int k=0;
        int* ptr=(int*)malloc(sizeof(int)*m);
        while(k<m)
        {
            ptr[k]=mat[j][k];
            k++;
        }
        ans[j]=ptr;
        j++;
    }
    *x=n;
    *y=m;
    return ans;
    
}
int** give_identity(int x,int y)
{
    int** ans=(int**)malloc(x*sizeof(int*));
    int j=0;
    while(j<x)
    {
        int k=0;
        int* ptr=(int*)malloc(sizeof(int)*y);
        while(k<y)
        {
            if(k==j)
            ptr[k]=1;
            else
            ptr[k]=0;
            k++;
        }
        ans[j]=ptr;
        j++;
    }
    return ans;
    
}
int** matrix_power_n(int** mat,int x,int y,int n)
{
    if(n==0)
    return give_identity(x,y);
    else
    {
        int** p=matrix_power_n(mat,x,y,n/2);
        if(n%2==0)
        {
            int tx,ty;
            int** ans= multiply_matrix(p,x,y,p,x,y,&tx,&ty);
            free(p);
            return ans;
        }
        else
        {
            int tx,ty;
            int** ans= multiply_matrix(p,x,y,p,x,y,&tx,&ty);
            free(p);
            ans=multiply_matrix(ans,x,y,mat,x,y,&tx,&ty);
            return ans;
        }
    }
}
int FindNthTerm(long long int n) 
{
    int reqsize=2;
    int f0=1;
    int f1=1;
    int** mat=(int**)malloc(2*sizeof(int*));
    int a1[2]={1,1};
    int a2[2]={1,0};
    mat[0]=a1;
    mat[1]=a2;
    int** coe=matrix_power_n(mat,2,2,n-1);
    return coe[0][0]*f1+coe[0][1]*f0;
}
void print_matrix(int** mat,int n,int m)
{
    int j=0;
    while(j<n)
    {
        int k=0;
        while(k<m)
        {
            printf("%d ",mat[j][k]);
            k++;
        }
        printf("\n");
        j++;
    }
}
