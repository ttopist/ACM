#include <cstdio>
#include <set>
using namespace std;

int main()
{
    int n,i,x,l,t;
    bool yes;
    set<int> s;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&x);
        while(x)
        {
            yes=1;
            s.clear();
            s.insert(x);
            l=x;
            i=n-1;
            while(i--)
            {
                scanf("%d",&x);
                if(x>l)
                {
                    s.insert(x);
                    l=x;
                }else{
                    t=l-1;
                    while(s.find(t)!=s.end()) t--;
                    if(x!=t)
                    {
                        while(i--)
                            scanf("%d",&x);
                         yes=0;
                        break;
                    }else{
                        l=x;
                        s.insert(x);
                    }
                }
            }
            if(yes) printf("Yes\n");
            else printf("No\n");
            scanf("%d",&x);
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
