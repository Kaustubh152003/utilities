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
void scan_grid(int** table,int n,int m)
{
    int j=0;
    while(j<n)
    {
        int k=0;
        while(k<m)
        {
            int x;
            scanf("%d ",&x);
            table[j][k]=x;
            k++;
        }
        j++;
    }
}
void print_grid(int** table,int n,int m)
{
    int j=0;
    while(j<n)
    {
        int k=0;
        while(k<m)
        {
            printf("%d ",table[j][k]);
            k++;
        }
        printf("\n");
        j++;
    }
}
