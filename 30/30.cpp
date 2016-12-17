#include<cstdio>
#define N 1000000
int n,a[N],sum_all=0;
class ans
{
public:
    int val,st,ed;
    ans(int value=0,int start=0,int end=0){this->val=value;this->st=start;this->ed=end;}
    void print(void){printf("%d %d %d\n",this->val,this->st,this->ed);}
    void update(ans& temp)
    {
        if (temp.val>this->val || temp.val==this->val && temp.ed-temp.st<this->ed-this->st)
        {
            this->val=temp.val;
            this->st=temp.st;
            this->ed=temp.ed;
        }
    }
    void update1(ans& temp)
    {
        if (temp.val<this->val || temp.val==this->val && temp.ed-temp.st>this->ed-this->st)
        {
            this->val=temp.val;
            this->st=temp.st;
            this->ed=temp.ed;
        }
    }
} temp,tpa[6];//answer temp

class ans2
{
public:
    int val,len,pos[4];
    void update(int value,int st1,int ed1,int st2,int ed2)
    {
        int tlen=(ed1-st1+ed2-st2+n)%n;
        if (value>this->val || value==this->val && tlen<this->len)
        {
            this->val=value;
            this->len=tlen;
            this->pos[0]=(st1+n)%n;this->pos[1]=(ed1+n)%n;this->pos[2]=(st2+n)%n;this->pos[3]=(ed2+n)%n;
        }
    }
    void print(void)
    {
        printf("%d\n",this->val);
        for (int i=0;i<4;i++)
            if (this->pos[(i+1)&3]<this->pos[i])
                printf("%d %d %d %d\n",this->pos[(i+1)&3],this->pos[(i+2)&3],this->pos[(i+3)&3],this->pos[i&3]);
    }
}final_answer;

void find(int start,int end,int ismin)
{
    int sum=0,tsp=start;  //temp start point
    temp.val=0;
    for (int i=start;i<end;i++)
    {
        sum+=a[i];
        if (ismin ^ sum>temp.val || sum==temp.val && ismin ^ i-tsp<temp.ed-temp.st)
        {
            temp.val=sum;
            temp.st=tsp;
            temp.ed=i;
        }
        if (ismin ^ sum<=0 || sum==0 && !ismin)
        {
            tsp=i+1;
            sum=0;
        }
    }
    //temp.print();
}

int main()
{
    int t1,t2;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {scanf("%d",a+i); sum_all+=a[i];}
    find(0,n,0);    tpa[0].update(temp);//maximum
    t1=temp.st; t2=temp.ed;
    find(0,t1-1,0); tpa[1].update(temp);
    find(t2+1,n,0); tpa[1].update(temp);//second max
    final_answer.update(tpa[0].val+tpa[1].val,tpa[0].st,tpa[0].ed,tpa[1].st,tpa[1].ed);
    find(t1,t2,1);  tpa[2].update1(temp);//minimum within
    final_answer.update(tpa[0].val-tpa[2].val,tpa[0].st,tpa[2].st-1,tpa[2].ed+1,tpa[0].ed);

    find(0,n,1);    tpa[3].update1(temp);//minimum
    t1=temp.st; t2=temp.ed;
    find(0,t1-1,1); tpa[4].update1(temp);
    find(t2+1,n,1); tpa[4].update1(temp);//second min
    final_answer.update(sum_all-tpa[3].val-tpa[4].val,tpa[3].ed+1,tpa[4].st-1,tpa[4].ed+1,tpa[3].st-1);
    find(t1,t2,0);  tpa[5].update(temp);//maximum within
    final_answer.update(sum_all-tpa[3].val+tpa[5].val,tpa[3].ed+1,tpa[3].st-1,tpa[5].st,tpa[5].ed);

    final_answer.print();
    return 0;
}