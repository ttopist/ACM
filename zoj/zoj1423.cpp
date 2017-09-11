#include <cstdio>
#include <stack>
using namespace std;
char x[260];
short howmangc(short i,short j)
{
    short ans=0;
    for(short t=i+1;t<j;t++) if(x[t]!=' ') ans++;
    return ans;
}

int main()
{

    stack<short> y;
    int n,i;
    bool isnav;
    //freopen("input.txt","r",stdin);
    scanf("%d\n",&n);
    while(n--)
    {
        fgets(x,256,stdin);
        isnav=0;
        for(i=0;x[i]!=0;i++)
        {
            switch(x[i])
            {
            case '-':
                isnav=1;break;
            case '(':
                if(!isnav)
                {
                    y.push(1);
                    x[i]=' ';
                }else y.push(0);
                isnav=0;break;
            case ')':
                if(y.top()) x[i]=' ';
                y.pop();
            default:
                isnav=0;
                break;
            case ' ':
                break;
            }
        }
        for(i=0;x[i]!=0;i++)
        {
            switch(x[i])
            {
            case '(':
                y.push(i);
                break;
            case ')':
                if(howmangc(y.top(),i)<=1) x[y.top()]=x[i]=' ';
                y.pop();
            default:
                break;
            }
        }
        for(i=0;x[i]!=0;i++) if(x[i]!=' ') printf("%c",x[i]);
    }
    return 0;
}
