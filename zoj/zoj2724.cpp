#include <cstdio>
#include <queue>
using namespace std;
struct node
{
    char name[100];
    int parameter;
    int priority ;
    bool operator < (const node &n) const
    { return priority>n.priority;}
}tmp;


int main()
{
    //freopen("input.txt","r",stdin);

    char inc[25];
    priority_queue<node> q;
    while(scanf("%s",inc)!=EOF)
    {
        if(inc[0]=='G')
        {
            if(q.empty())
                printf("EMPTY QUEUE!\n");
            else
            {
                tmp=q.top();
                printf("%s %d\n",tmp.name,tmp.parameter);
                q.pop();
            }
        }else{
            scanf("%s %d %d",tmp.name,&tmp.parameter,&tmp.priority);
            q.push(tmp);
        }
    }
    return 0;
}
