#include<iostream>
#include<cmath>
#define MaxN 500000
#define Pointer int
Pointer top_pointer;
class node
{
public:
    Pointer left,right,addr;
    void setProperties(int addr,int left,int right)
    {
        this->addr=addr;
        this->left=left;
        this->right=right;
    }
    void leftInsert(node &p);
    void rightInsert(node &p);
    void stepOut();
}memory[MaxN];
void node::leftInsert(node &p)
    {
//       std::cout<<"insert "<<p.addr<< " to the left of " <<this->addr<<'\n';
        p.left=this->left;
        p.right=this->addr;
        memory[this->left].right=p.addr;
        this->left=p.addr;
    }
void node::rightInsert(node &p)
    {
//        std::cout<<"insert "<<p.addr<< " to the right of " <<this->addr<<'\n';
        p.right=this->right;
        p.left=this->addr;
        memory[this->right].left=p.addr;
        this->right=p.addr;
    }
void node::stepOut()
{
//    std::cout<<this->addr<< " stepOut "<<'\n';
    memory[this->left].right=this->right;
    memory[this->right].left=this->left;
}
void dubug(int q)
{
    Pointer p=q;
    while (1)
    {
        std::cout<<p<</*memory[p].left<<memory[p].right<*/ ' ';
        p=memory[p].left;
        if (p==q) break;
    }
    std::cout<<'\n';
}
int main()
{
    Pointer p=0;
    int N,M,k,i,j,ans=0;
    std::cin>>N>>M>>k;
    memory[0].left=1;
    for (i=1;i<=M;i++) memory[i].setProperties(i,M-i?i+1:1,i-1?i-1:M);
    for (i=1;i<=N-M;i++)
    {
        for (j=0;j<k;j++) p=memory[p].left;
        memory[M+i].addr=M+i;
        p&1 ? memory[p].rightInsert(memory[M+i]):memory[p].leftInsert(memory[M+i]);
//        dubug(1);
    }
    for (i=1;i<=N-M;i++)
    {
        for (j=0;j<k;j++) p=memory[p].left;
        memory[p].stepOut();
 //       dubug(memory[p].left);
    }
    p=memory[p].left;
    for (i=1;i<=M;i++)
    {
        if (p<=M) ans++;
        p=memory[p].left;
    }
    std::cout<<ans;
    return 0;
}
