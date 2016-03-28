/*
���� ����n ��һ��n��ȫ���У�������(��0��ʼ)��������ֵ������һ��ȫ����

perm2num ȫ����ת�ֵ���,
ÿ�����������С���Լ������ĸ�������k��ret+=k*(BIT-1)!,

num2perm �ֵ���תȫ����(�ַ���Ϊ{0,1,2,3..n-1})
���ҳ���ϵ��k,
���ҵ��󣬼����ұ���һ��{0,1,2..n-1}��ȫ���У����һ������ʾ�ұ��ж��ٸ���С���Լ�,���ұ�����С�ڵ�����ߵ�����һ

nextperm ����һ��ȫ���� ��algorithm next_permutation��
      1�������е��Ҷ˿�ʼ���ҳ���һ�����ұ��ַ�С���ַ������j��j����˿�ʼ���㣩���� j=max{i|pi<pi+1}
      2����pj���ұߵ��ַ��У��ҳ����б�pj����ַ�����С���ַ�pk����
      k=max{i|pi>pj}���ұߵ��ַ����������ǵ����ģ����k�����д���pj���ַ����������ߣ�
      3���Ի�pj��pk
      4���ٽ�pj+1......pk-1pkpk+1pn��ת�õ�����p''=p1p2.....pj-1pjpn.....pk+1pkpk-1.....pj+1�����������p����һ����һ�����С�
      ����839647521������1��9��һ�����С�����������һ�����еĲ������£�
      ���������ҳ������е�һ�����ұ�����С������4 839647521
      �ڸ����ֺ���������ҳ���4���������С��һ��5 839647521
      ��5��4���� 839657421
      ��7421��ת 839651247
      ����839647521����һ��������839651247��
      839651247����һ��������839651274��
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
