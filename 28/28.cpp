#include<cstdio>
#include<cmath>
int main()
{
    int m,n,i,j;
    double ans,ans1,ans2,t,part_ans=0,temp=0;
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        ans=0;ans1=0;ans2=0;
        scanf("%d",&n);
        if (n<100000)
        { 
            for (j=1;j<=n;j++)
            {
                ans1+=(sqrt(1.0*j*j+1)+sqrt(1.0*j*j-1))/2;
                ans2+=2/(sqrt(1.0*j*j+1)+sqrt(1.0*j*j-1));
            }
            ans=ans1+ans2;
        }
        else
        {
            for (j=1;j<=100000;j++)
            {
                ans1+=(sqrt(1.0*j*j+1)+sqrt(1.0*j*j-1))/2;
                ans2+=2/(sqrt(1.0*j*j+1)+sqrt(1.0*j*j-1));
            }
            ans=ans1+ans2+log(n)-log(100000);
        }
        printf("%.12e\n",ans);
    }    
}
