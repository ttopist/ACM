/*
题意 输入n 及一个n的全排列，输出序号(从0开始)，再输出字典序的下一个全排列

perm2num 全排列转字典序,
每个数的左边找小于自己的数的个数，作k，ret+=k*(BIT-1)!,

num2perm 字典序转全排列(字符集为{0,1,2,3..n-1})
先找出各系数k,
从右到左，假如右边是一个{0,1,2..n-1}的全排列，左边一个数表示右边有多少个数小于自己,则右边所有小于等于左边的数加一

nextperm 求下一个全排列 （algorithm next_permutation）
      1）从排列的右端开始，找出第一个比右边字符小的字符的序号j（j从左端开始计算），即 j=max{i|pi<pi+1}
      2）在pj的右边的字符中，找出所有比pj大的字符中最小的字符pk，即
      k=max{i|pi>pj}（右边的字符从右至左是递增的，因此k是所有大于pj的字符中序号最大者）
      3）对换pj，pk
      4）再将pj+1......pk-1pkpk+1pn倒转得到排列p''=p1p2.....pj-1pjpn.....pk+1pkpk-1.....pj+1，这就是排列p的下一个下一个排列。
      例如839647521是数字1～9的一个排列。从它生成下一个排列的步骤如下：
      自右至左找出排列中第一个比右边数字小的数字4 839647521
      在该数字后的数字中找出比4大的数中最小的一个5 839647521
      将5与4交换 839657421
      将7421倒转 839651247
      所以839647521的下一个排列是839651247。
      839651247的下一个排列是839651274。
*/

#include <cstdio>
using namespace std;


int perm2num(int n,int *p){
	int i,j,ret=0,k=1;
	for (i=n-2;i>=0;k*=n-(i--))
		for (j=i+1;j<n;j++)
			if (p[j]<p[i])
				ret+=k;
	return ret;
}
/*
void num2perm(int n,int *p,int t){
	int i,j;
	for (i=n-1;i>=0;i--)
		p[i]=t%(n-i),t/=n-i;
	for (i=n-1;i;i--)
		for (j=i-1;j>=0;j--)
			if (p[j]<=p[i])
				p[i]++;
}
*/


void num2perm(int n,int *p,int t){
	int i,j;
	for (i=n-1;i>=0;i--)
		p[i]=t%(n-i),t/=n-i;
	for (i=n-1;i>=0;i--)
		for (j=i+1;j<n;j++)
			if (p[j]>=p[i])
				p[j]++;
}

void nextperm(int n, int *p)
{
    int posi,i,posj;
    for(posi=n-2;posi>=0;posi--)
        if(p[posi]<p[posi+1])
            break;
    if(posi<0) return;
    for(i=posi+1; i<n && p[posi]<p[i]; i++);
    posj=i-1;
    i=p[posi];p[posi]=p[posj];p[posj]=i;
    posi=posi+1;posj=n-1;
    while(posi<posj)
    {
        i=p[posi];p[posi]=p[posj];p[posj]=i;
        posi++;
        posj--;
    }
}

int main()
{
    int n;
    int num[15]={0};
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",num+i);
        int index=perm2num(n,num);
        printf("%d\n",index);
        //num2perm(n,num,index+1); //make +1 in print
        nextperm(n,num);
        for(int i=0;i<n;i++)
            printf("%d%s",num[i],i<n-1?" ":"\n");
    }
    return 0;
}
