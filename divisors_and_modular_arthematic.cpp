int nod(int x) //number of divisors
{
    int j=1;
    int ans=0;
    while(j<sqrt(x))
    {
        if(x%j==0)
        ans=ans+2;
        j++;
    }
    if(x%j==0 && j*j==x)
    ans++;
    return ans;
}
