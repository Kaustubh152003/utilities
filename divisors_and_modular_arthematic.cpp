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
