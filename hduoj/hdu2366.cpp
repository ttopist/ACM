#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

map< int , vector<int> > point;
int d;
long long int bingo()
{
    long long int ans=0;
    int td=0;
    map< int , vector<int> >::iterator i,nx;
    vector<int>::iterator j;
    for(i=point.begin();i!=point.end();++i)
        sort((i->second).begin(),(i->second).end());
    for(i=point.begin();i!=point.end();++i)
        for(td=1;td<d;td++)
            if((nx=point.find(i->first + td))!=point.end())
            {
                ans+=   (upper_bound(nx->second.begin(), nx->second.end(), int(sqrt(float(d*d-td*td)))) - nx->second.begin())
                        -(lower_bound(nx->second.begin(), nx->second.end(), int(sqrt(float(d*d-td*td)))) - nx->second.begin());
            }
    for(i=point.begin();i!=point.end();++i)
    {

    }

    return ans;
}

int main()
{
    int t,n,x,y;
    scanf("%d\n",&t);
    while(t--)
    {
        point.clear();
        scanf("%d %d\n",&n,&d);
        while(n--)
        {
            scanf("%d %d\n",&x,&y);
            point[x].push_back(y);
        }
        printf("%I64d\n",bingo());
    }
    return 0;
}
