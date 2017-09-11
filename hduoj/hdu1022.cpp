#include <cstdio>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
    char inq[12],outq[12];
    int n,i,j;
    while(~scanf("%d%s%s",&n,inq,outq))
    {
        //printf("inq;%sEoutq%sE\n",inq,outq);
        queue<bool> q;
        stack<char> s;
        i=j=0;
        while(i<=n)
        {
            if(s.empty() ||s.top()!=outq[j])
            {
                s.push(inq[i]);
                if(i<n) q.push(1);
                i++;
            }
            else
            {
                s.pop();
                q.push(0);
                j++;
            }
        }
        //printf("j:%d\n",j);
        if(j<n) printf("No.\n");
        else
        {
            printf("Yes.\n");
            while(!q.empty())
                {printf("%s",q.front()?"in\n":"out\n");q.pop();}
        }
        printf("FINISH\n");
    }
    return 0;
}
