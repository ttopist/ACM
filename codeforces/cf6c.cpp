#include <cstdio>

using namespace std;

int main()
{
    int *num=new int[100000+1];
    int n;
    scanf("%d",&n); //cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",num+i); //cin>>num[i];
    int a=0,b=0,i=0,j=n-1,x=0,y=0;
    while(i<=j)
    {
        if(a<=b)
        {
            a+=num[i];
            i++;
            x++;
        }else{
            b+=num[j];
            j--;
            y++;
        }
    }
    printf("%d %d\n",x,y); //cout<<x<<y;
    return 0;
}
