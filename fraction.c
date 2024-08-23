struct Fraction
{
    long long int num;
    long long int den;
};
long long int gcd(long long a,long long b)
{
    a=abs(a);
    b=abs(b);
    if(a>b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    if(a==0)
    return b;
    else
    return gcd(b%a,a);

}
struct Fraction add_Fraction(struct Fraction a,struct Fraction b)
{
    long long int x=a.num * b.den + b.num * a.den;
    long long int y=a.den * b.den;
    int g=gcd(x,y);
    struct Fraction ans;
    ans.num=x/g;
    ans.den=y/g;
    return ans;
}
struct Fraction subtract_Fraction(struct Fraction a,struct Fraction b)
{
    long long int x=a.num * b.den - b.num * a.den;
    long long int y=a.den * b.den;
    int g=gcd(x,y);
    struct Fraction ans;
    ans.num=x/g;
    ans.den=y/g;
    return ans;
}
char* num_to_string(int x)
{

    int nflag=0;
    if(x<0)
    {
        x=-x;
        nflag=1;
    }
    int j=0;
    int temp[10];
    while(x>0)
    {
        temp[j]=x%10+'0';
        x=x/10;
        j++;
    }
    int n=j;

    char* ans=(char*)malloc(sizeof(char)*20);
    int p=0;
    if(nflag==1)
    {
        ans[p]='-';
        p++;
    }
    
    j--;
    while(j>=0)
    {
        ans[p]=temp[j];
        p++;
        j--;
    }
    if(p==0)
    {
        ans[p]='0';
        p++;
    }
    ans[p]='\0';
    return ans;
}
void concatinate(char* target,char* str)
{
    int j=0;
    while(target[j]!='\0')
    j++;
    int k=0;
    while(str[k]!='\0')
    {
        target[j]=str[k];
        k++;
        j++;
    }
    target[j]='\0';
}
char* Fraction_to_string(struct Fraction a)
{
    char* ans=(char*)malloc(sizeof(char)*20);
    ans[0]='\0';
    char* ax=num_to_string(a.num);
    char* b="/";
    char* c=num_to_string(a.den);
    concatinate(ans,ax);
    concatinate(ans,b);
    concatinate(ans,c);
    return ans;
}
