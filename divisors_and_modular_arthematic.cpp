int number_of_divisors(int x) //number of divisors
{
    int j=1;
    int ans=0;
    int limit=sqrt(x);
    while(j<=limit)
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
#define A 1000000007
long long int sum_of_divisors(long long int x) //sum of divisors
{
    int j=1;
    long long sum=0;
    long long int limit=sqrt(x);
    while(j<=limit)
    {
        if(x%j==0)
        {
            sum=sum+j;
            sum=sum%A;
            sum=sum+x/j;
            sum=sum%A;
        }
        j++;
    }
    j--;
    if(j*j==x)
    {
        sum=sum-j;
        sum=sum%A;
    }
    sum=(sum+A)%A;
    return sum;
}
