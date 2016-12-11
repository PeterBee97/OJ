#include<cstdio>
#include<cstring>
#define N 500
#define M 1000
float a[M][N],b[M],x[N],y[N],z[M],ata[N][N],atai[N][N],temp;
void Print(float x[][N],int m,int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++) printf(" %.5f",x[i][j]);
        printf("\n");
    }
}
void Printv(float x[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%.6f\n",x[i]);
    }
}
void InverseMatrix(float A[][N],int n)
{
 int i,j,k,m=n<<1;
 float mik,temp;
 float **a=new float*[n];

 for(i=0;i<n;i++)
  a[i]=new float[n<<1];

 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   if(i==j)
    atai[i][j]=1;
   else
    atai[i][j]=0;
  }
 }        //初始化B=E

 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   a[i][j]=A[i][j];  //复制A到a，避免改变A的值
 for(i=0;i<n;i++)
  for(j=n;j<m;j++)
   a[i][j]=atai[i][j-n];  //复制B到a，增广矩阵

 for(k=1;k<=n-1;k++)
 {
  for(i=k+1;i<=n;i++)
  {
   mik=a[i-1][k-1]/a[k-1][k-1];
   for(j=k+1;j<=m;j++)
   {
    a[i-1][j-1]-=mik*a[k-1][j-1];
   }
  }
 }        //顺序高斯消去法化左下角为零

 for(i=1;i<=n;i++)
 {
  temp=a[i-1][i-1];
  for(j=1;j<=m;j++)
  {
   a[i-1][j-1]/=temp;
  }
 }        //归一化

 for(k=n-1;k>=1;k--)
 {
  for(i=k;i>=1;i--)
  {
   mik=a[i-1][k];
   for(j=k+1;j<=m;j++)
   {
    a[i-1][j-1]-=mik*a[k][j-1];
   }
  }
 }        //逆序高斯消去法化增广矩阵左边为单位矩阵

 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
    atai[i][j]=a[i][j+n];
    //if(fabs(atai[i][j])<0.0001) atai[i][j]=0.0;
  }
 delete []a;
}

int main()
{
    int m,n,k;
    int i,j;
    scanf("%d %d %d",&m,&n,&k);
    for (int ti=0;ti<k;ti++)
    {
        scanf("%d %d %f",&i,&j,&temp);
        a[i-1][j-1]=temp;
    }
    for (int ti=0;ti<m;ti++)
    {
        scanf("%f",b+ti);
    }
    for (i=0;i<n;i++)
    {
        memset(ata[i],0,sizeof(ata[0][0])*n);
        for (j=0;j<n;j++)
            for (k=0;k<m;k++)
                ata[i][j]+=a[k][i]*a[k][j];
    }//c=a'*a
    //Printv(b,n);
    //Print(ata,n,n);
    InverseMatrix(ata,n);
    //Print(atai,n,n);
    memset(y,0,sizeof(y[0])*m);
    for (i=0;i<n;i++)        
        for (j=0;j<m;j++)
            y[i]+=a[j][i]*b[j];//x=a'*b
    //Printv(y,m);
    memset(x,0,sizeof(x[0])*n);
    for (i=0;i<n;i++)        
        for (j=0;j<n;j++)
            x[i]+=atai[i][j]*y[j];
    Printv(x,n);
    memset(z,0,sizeof(z[0])*n);
    temp=0;
    for (i=0;i<m;i++)   
    {     
        for (j=0;j<n;j++)
        {
            z[i]+=a[i][j]*x[j];
        }
        temp+=(z[i]-b[i])*(z[i]-b[i]);
    }
    printf("%.6f\n",temp);
}
