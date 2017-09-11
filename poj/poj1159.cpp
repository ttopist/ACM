#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
/*
char str[5001];
int n;

int getnum(int i);
{
    int l,r;
    l=i-1;r=i+1;
    while(i>=1 && r<=n && )
}

int main()
{
    int maxs=1,t,lefti.righti,leftend,righten;
    scanf("%d\n",&n);
    scanf("%s",str+1);
    righti=n/2+1;
    lefti=righti-1;
    leftend=2;
    rightend=n-1;
    while(lefti>=leftend ||right<=rightend)
    {
        if(lefti>=leftend)
        {
            t=getnum(lefti);
            leftend:
        }
        if(right<=rightend)
        {
            t=getnum(righti);
        }
    }
    printf("%d\n",n-maxs);
    return 0;
}
*/

int find(char in[], int len)
{
    int i=0, j=0, cnt = 0, maxLen = 1;
    for(i = 0; i < len; i++)
    {//遍历每个元素，作为左起点
        for(j = 0; j < len-1-i; j++)
        {//从最右元素左遍历
            if(in[i] == in[len-1-j])
            {//回文的两端如果相等，则进一步进行循环比较
                for(cnt = 1; cnt <= (len-i-j)/2; cnt++)
                {//比较左起点和右起点之间的长度len-i-j的一半就可以了
                    if(in[i+cnt] != in[len-1-j-cnt]) //内缩比较
                        break;
                }
                if(cnt >= (len-j-i)/2)
                {//判断上面的内缩比较是否过半，过半则必定回文
                    cnt = (len-j-i);//cnt在这里作为本次长度使用
                    if(cnt > maxLen)//比原来的大才更新
                    {
                        maxLen = cnt;
                    }
                    break;
                }
            }
        }
    }
    return maxLen;
}

int main()
{
    int n;
    char str[5001];
    while(~scanf("%d\n",&n))
    {
    scanf("%s",str);
    printf("%d\n",n-find(str,n));
    }
    return 0;
}
