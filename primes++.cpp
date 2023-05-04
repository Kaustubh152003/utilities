

// u can include this code in main instead. prime[p]=1 if p is prime
int prime[100000];
    int k=0;
    while(k<100000)
    {
        prime[k]=1;
        k++;
    }
    k=2;
    while(k<100000)
    {
        if(prime[k]==1)
        {
            int l=2;
            while(k*l<100000)
            {
                prime[k*l]=0;
                l++;
            }
        }
        k++;
    }

//

int* primegen(int n) //generates all primes less than n. end of array has -1. returns that array
{
    int j=2;
    int* arr=(int*)malloc(4*n);
    int mark[n+1];
    j=0;
    while(j<n+1)
    {
        mark[j]=0;
        j++;
    }
    int p=0;
    j=2;
    while(j<n+1)
    {
        if(mark[j]==0)
        {
            arr[p]=j;
            p++;
            int k=2;
            while(j*k<n+1)
            {
                mark[j*k]=1;
                k++;
            }
        }
        j++;
    }
    arr[p]=-1;
    return arr;
}
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
