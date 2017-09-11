#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int num;
    int period;
    int time;
    bool operator < (const node &n) const
    {
        if(time==n.time) return num > n.num;
        else return time > n.time;
    }
}tmp;

int main()
{
    priority_queue<node> q;
    char x[10];
    int n;

    //freopen("input.txt","r",stdin);

    scanf("%s",x);
    while( x[0]!='#' )
    {
        scanf("%d%d",&tmp.num,&tmp.period);
        tmp.time=tmp.period;
        q.push(tmp);
        scanf("%s",x);
    }
    scanf("%d",&n);
    while(n--)
    {
        tmp=q.top();
        q.pop();
        printf("%d\n",tmp.num);
        tmp.time+=tmp.period;
        q.push(tmp);
    }
    return 0;
}
