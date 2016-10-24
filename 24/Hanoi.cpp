#include<iostream>
using namespace std;
int main()
{
    int a[15000],m,n,f[15000][2];
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (i==1)
        {
            f[i][0]=a[i];   //h[a[i]][0]=a[i]
            f[i][1]=2*a[i]-1;
        }
        else
        {
            f[i][0]=2*f[i-1][0]+a[i];
            if (a[i]==1) f[i][1]=f[i][0];
            else f[i][1]=2*f[i-1][0]+2*a[i]+f[i-1][1];
        }
        f[i][0]%=m;
        f[i][1]%=m;
    }
    cout<<f[n][1];
}
