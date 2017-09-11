#include <cstdio>
#include <set>
using namespace std;
typedef long long int LL;
const int maxn=100,minn=0;
int b[15];
LL a[13]={1};

LL getnum(const int &n)
{
    set<int> s;
    LL ans=0;
    int i;
    for(i=1;i<=n;i++)
        s.insert(i);
    for(int i=1;i<=n;i++)
    {
        ans+= ((s.lower_bound(b[i])-s.begin())-(s.upper_bound(minn)-s.begin()))*a[n-i];
        s.erase(b[i]);
    }
    return ans;
}

//void bnext()
//ans += (upper_bound(nx->second.begin(), nx->second.end(), *p + t) - nx->second.begin()) -  (lower_bound(nx->second.begin(), nx->second.end(), *p - t) - nx->second.begin());
int main()
{
    for(i=1;i<=13;i++)
        a[i]=a[i-1]*i;
    a[0]=0;
    int n;
    while(~scanf("%d",&n))
    {
        set<int> s;
        for(int i=1;i<=n;i++)
            scanf("%d",b+i);
        printf("%lld\n",getnum(n));
        /*
        bnext();
        printf("%d",b[1]);
        for(int i=2;i<=n;i++)
            printf(" %d",b[i]);
        printf("\n");
        */
    }
    return 0;
}
