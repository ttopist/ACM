#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int n,i,a,b;
    vector<int> num[100000+2];
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        num[a].push_back(b);
        num[b].push_back(a);
    }

    printf("%d\n",n-1);

    queue<int> que,que2;
    int id=0,father=1,x;
    que.push(1);
    while(!que.empty())
    {
        x=que.front();que.pop();
        for(i=0;i<num[x].size();i++)
        {
            printf("%d %d\n",x,num[x][i]);
            que2.push(id);
            id++;
            que.push(num[x][i]);
        }
    }

    return 0;
}
