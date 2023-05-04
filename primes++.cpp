int* binary_search(int* arr, int n,int k) // returns the adress where the element is found. If not found, returns NULL
{
    if(n==0)
    return 0;
    else
    {
        if(arr[n/2]==k)
        return arr+n/2;
        else
        {
            if(k<arr[n/2])
            return binary_search(arr,n/2,k);
            else
            return binary_search(arr+n/2+1,n-n/2-1,k);
        }
    }
}

void prime_factorize(int x,int* table,int sp) //sets the prime factorization into the array "table". needs primes and table to be initialized
{
    int count=0;
        int j=0;
        while(primes[j]!=-1 && primes[j]<=sqrt(x) && x>1)
        {
            if(x%primes[j]==0)
            {
                table[j]++;
                x=x/primes[j];
                j--;
            }
            j++;
        }
        if(x>1)
        {
            int* ptr=binary_search(primes,sp,x);
            table[ptr-primes]++;
        }
}

//refer https://codeforces.com/contest/1823/submission/204409852
