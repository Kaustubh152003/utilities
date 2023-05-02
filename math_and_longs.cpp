long long longer(int k)
{
    long long x=k;
    return x;
}
int positive_modulo(long long int x,long long int y)
{
    long long z=((x%y)+y)%y;
    return z;
}
long long power(long long x,long long a,long long mod)
{
    if(a==0)
    return 1;
    else
    {
        long long p=power(x,a/2);
        p=p*p;
        p=p%mod;
        if(a%2==1)
        p=p*x;
        p=p%mod;
        return p;
    }
}

long long * prefix_sum(int* arr,int n)
{
    long long* ans=(long long*)malloc(n*sizeof(long long));
    ans[0]=arr[0];
    int j=1;
    while(j<n)
    {
        ans[j]=ans[j-1]+longer(arr[j]);
        j++;
    }
    return ans;
}

int conv(int a) //converts a boolean to int
{
    if(a==1)
    return 1;
    else
    return 0;
}
