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
