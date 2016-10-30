#include<iostream>
using namespace std;
int a,b,c,d;
struct node
{
    int x,y;
    node *L,*R;
};
node* root=new node{0,0,NULL,NULL};

void Insert(node* p,int t)
{
    node *np;
    //cout<<"Insert ("<<a<<","<<b<<") in ("<<p->x<<","<<p->y<<")\n"; 
    if(!t&&p->x>a||t&&p->y>b)
    {
     if (p->L==NULL)
        {
            np=new node{a,b,NULL,NULL};
            p->L=np;
        }
        else Insert(p->L,1-t);
    }
    else
    {
        if (p->R==NULL)
        {
            np= new node{a,b,NULL,NULL};
            p->R=np;
        }
        else Insert(p->R,1-t);
    }
}

int Query(node* p,int t)
{
    int tp=0;
    if (!p) return 0;
    if (p->x>=a&&p->x<=b&&p->y>=c&&p->y<=d) tp=1;
    //if (p) cout<<"Query ("<<a<<","<<b<<") in ("<<p->x<<","<<p->y<<")\n"; 
    if((!t&&p->x==a||t&&p->y==c)&&p!=root) return Query(p->R,1-t)+tp;
    if(!t&&p->x<a||t&&p->y<c) return Query(p->R,1-t);
    if(!t&&p->x>b||t&&p->y>d) return Query(p->L,1-t);
    if (p!=root) return Query(p->L,1-t)+Query(p->R,1-t)+tp;
    else return Query(p->L,1-t)+Query(p->R,1-t);
}

int main()
{
    int m,n,t;
    cin>>m>>n;
    for (int i=0;i<m+n;i++)
    {
        cin>>t;
        if (!t) 
        {
            cin>>a>>b;
            Insert(root,0);
        }
        else{
            cin>>a>>b>>c>>d;
            cout<<Query(root,0)<<endl;
        }
    }
    return 0;
}
