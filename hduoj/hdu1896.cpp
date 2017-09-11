#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int site;
    int dist;
    bool operator < (const node &n) const
    {
        if(site!=n.site) return n.site<site;
        else return n.dist < dist;
    }
}now;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        priority_queue<node> q;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d",&(now.site),&(now.dist));
            q.push(now);
        }
        //while(!q.empty())
        //{now=q.top();q.pop();printf("%d %d\n",now.site,now.dist);}
        int i=1;
        while(!q.empty())
        {
            now=q.top();
            q.pop();
            //printf("now %d %d %d\n",now.site,now.dist,i);
            if(i)
            {
                now.site+=now.dist;
                q.push(now);
                //printf("pushnow %d %d %d\n",now.site,now.dist,i);
                i=0;
            }else i=1;
        }
        printf("%d\n",now.site);
    }
    return 0;
}
