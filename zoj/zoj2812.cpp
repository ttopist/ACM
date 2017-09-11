#include <cstdio>

using namespace std;

int main()
{
    char c;
    int i=1;
    long long int sum=0;
    while(~scanf("%c",&c))
    {
        if(c=='#') break;
        else if(c=='\n')
        {
            printf("%lld\n",sum);
            sum=0;
            i=1;
        }else if(c==' ') i++;
        else{
            sum+=i*(c-'A'+1);
            i++;
        }
    }
    return 0;
}
