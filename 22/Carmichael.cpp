#include<iostream>
#include<cmath>
int gcd(int m,int n){return m%n?gcd(n,m%n):n;}
int pow(int a,int p,int& n)
{
    long long t;
    if (p==1) return a%n;
    t=pow(a,p>>1,n)%n;
    t*=t;
    t%=n;
    if (p&1) return t*a%n;
    return t;
}
int isprime(int n)
{
    if (n==1) return 0;
    int t=floor(sqrt(n));
    for (int i=2;i<t;i++)
        if (n%i==0) return 0;
    return 1;
}
int main()
{
    int N,n,sum=0,ans[1000],a;
    std::cin>>N;
    for(int n=2;n<N;n++)
    {
        if (isprime(n)) continue;
        for (a=2;a<n;a++)
            if (gcd(a,n)==1 && !(pow(a,n-1,n)==1)) break;
        if(a==n)
        {
            a=0;
            while (a<sum&&ans[a]<n) a++;
            if (ans[a]!=n)
            {
                for (int j=a;j<sum;j++) ans[j+1]=ans[j];
                ans[a]=n;
                sum++;
           }
        }
    }
    std::cout<<sum<<'\n';
    for(int i=0;i<sum;i++) std::cout<<ans[i]<<',';
    return 0;
}
