#include <iostream>
using namespace std;
typedef long long int  LL;

LL F[100][100];

int main()
{
    short n,i,j,k,len,num[100];
    LL t,minx;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>num[i];
    for(len=3;len<=n;len++)
    {
        for(i=0;i<=n-len;i++)
        {
            j=i+len-1;
            minx=100000000000000000;
            for(k=i+1;k<j;k++)
            {
                t=F[i][k]+F[k][j]+num[i]*num[k]*num[j];
                if(t<minx) minx=t;
            }
            F[i][j]=minx;
        }
    }
    cout<<F[0][n-1]<<endl;
    return 0;
}
