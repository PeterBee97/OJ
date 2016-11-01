#include<cstdio>
#include<cstring>
int main()
{
    unsigned int i,j,k,t,n,e,d[400][400],num[400][400],ans[400]={0},ansi[400];
    scanf("%d %d",&n,&e);
    for (i=0;i<n;i++)
    {
        memset(d[i],0xFF,sizeof(d[i]));
        ansi[i]=i;
        d[i][i]=0;
    }
    for (k=0;k<e;k++)
    {
        scanf("%d %d %d",&i,&j,&t);
        if (t<d[i][j]) d[j][i]=d[i][j]=t;
        num[i][j]=num[j][i]=1;
    }
    memset(&t,0xFF,sizeof(t));
    for (k=0;k<n;k++)
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if (i!=k && j!=k && d[i][k]<t && d[k][j]<t && d[i][k]+d[k][j]<=d[i][j])
                {
                    if(d[i][k]+d[k][j]==d[i][j])
                        num[i][j]+=num[i][k]*num[k][j];
                    else num[i][j]=num[i][k]*num[k][j];
                    d[i][j]=d[i][k]+d[k][j];//Floyd once
                }
   for (k=0;k<n;k++)
        for (i=0;i<n;i++)
            for (j=i+1;j<n;j++)
                if (i!=k && j!=k && d[i][k]+d[k][j]==d[i][j])
                    ans[k]+=num[i][k]*num[k][j];//Floyd twice
    for (i=1;i<n;i++)
        for (j=i;j>0;j--)
            if (ans[j]>ans[j-1])
            {
                ans[j]^=ans[j-1];ansi[j]^=ansi[j-1];
                ans[j-1]^=ans[j];ansi[j-1]^=ansi[j];
                ans[j]^=ans[j-1];ansi[j]^=ansi[j-1];
            }
    for (i=0;i<n;i++)
        printf("%d %d\n",ansi[i],ans[i]);
}

