#include <stdlib.h>
#include <stdio.h>
#define M 1000000007
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
                long long int sum=0;
                int x=0;
                int y=0;
                while(y<y1 && x<x2)
                {
                    long long temp=mat1[j][y];
                    temp=temp*(long long)(mat2[x][k]);
                    temp=temp%M;
                    sum=sum+temp;
                    sum=sum%M;
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
    long long x=(long long)(coe[0][0]*f1);
    long long y=(long long)(coe[0][1]*f0);
    x=x+y;
    x=x%M;
    return x;
}
