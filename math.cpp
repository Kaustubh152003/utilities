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

int get_catalan(int n,int* arr)
{
    if(n==0)
    return 1;
    else
    {
        if(arr[n]!=-1)
        return arr[n];
        else
        {
            int j=1;
            long long sum=0;
            long long m=pow(10,9)+7;
            while(j<=n)
            {
                long long p=(long long)(get_catalan(j-1,arr));
                p=p*(long long)(get_catalan(n-j,arr));
                p=p%m;
                sum=sum+p;
                sum=sum%m;
                j++;
            }
            arr[n]=sum;
            return sum;
        }
    }
}
int findCatalan(int n) 
{
    int arr[n+1];
    int j=0;
    while(j<n+1)
    {
        arr[j]=-1;
        j++;
    }
    get_catalan(n,arr);
}

int nod(int x) //number of divisors
{
    int j=1;
    int ans=0;
    int limit=sqrt(x);
    while(j<=sqrt(x))
    {
        if(x%j==0)
        ans=ans+2;
        j++;
    }
    j--;
    if(j*j==x)
    ans--;
    return ans;
}
