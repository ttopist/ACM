#include <cstdio>
#include <list>
using namespace std;

struct BigInt{
    list<int> num;
    bool negative;

    BigInt(int n=0){
        if(n<0) negative=1,n=-n;
        else    negative=0;
        if(0==n)    num.push_back(0);
        while(n!=0){
            num.push_front(n%10);
            n=n/10;}
    }

    BigInt(char* s){
        negative=(s[0]=='-'?1:0);
        int i=0;
        while('0'>=s[i] || s[i]>'9') i++;
        while('0'<=s[i] && s[i]<='9') num.push_back(s[i++]-'0');
    }

    void print(){
        if(negative) printf("-");
        for(list<int>::iterator it=num.begin();it!=num.end();++it)
            printf("%d",*it);
    }
};

int CmpAbsBigInt(BigInt &a, BigInt &b){
    if(a.num.size()>b.num.size()) return 1;
    if(a.num.size()<b.num.size()) return -1;
    list<int>::iterator ia=a.num.begin(),ib=b.num.begin();
    while(ia!=a.num.end() && *ia==*ib) ++ia,++ib;
    if(ia==a.num.end()) return 0;
    return *ia>*ib?1:-1;
}

BigInt operator + (BigInt a, BigInt b){
    BigInt sum;sum.num.clear();
    if(a.negative==b.negative){
        sum.negative=a.negative;
        list<int>::iterator ia=--a.num.end(),ib=--b.num.end();
        int carry=0;bool fa=1,fb=1;
        while(carry || fa || fb){
            int temp=(fa?*ia:0)+(fb?*ib:0)+carry;
            sum.num.push_front(temp%10);
            carry=temp/10;
            if(ia==a.num.begin()) fa=0; else --ia;
            if(ib==b.num.begin()) fb=0; else --ib;}
    }else{
        list<int> *big,*small;
        switch(CmpAbsBigInt(a,b)){
            case 0: return BigInt(0);
            case 1: sum.negative=a.negative;big=&(a.num);small=&(b.num);break;
            case -1: sum.negative=b.negative;big=&(b.num);small=&(a.num);}
        sum.num.insert(sum.num.begin(),big->begin(),big->end());
        list<int>::iterator ib=--sum.num.end(),is=--(small->end());
        int borrow=0;bool fs=1;
        while(borrow || fs){
            *ib-=(fs?*is:0)+borrow;
            if(*ib>=0) borrow=0;
            else *ib+=10,borrow=1;
            if(is==small->begin()) fs=0; else --is;
            --ib;}
        while(sum.num.front()==0) sum.num.pop_front();
    }
    return sum;
}

BigInt operator - (BigInt a, BigInt b){
    b.negative=!b.negative;
    return a+b;
}

BigInt operator * (BigInt a, BigInt b){
    list<int>::iterator ib=--b.num.end();
    bool fb=1;
    while(fb){
        if(ib==b.num.begin()) fb=0; else --ib;
    }
}

int main()
{
    char str1[1000];
    char str2[1000];
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%s %s",str1,str2);
        BigInt a1=BigInt(str1);
        BigInt a2=BigInt(str2);
        BigInt ans=a1+a2;
        ans.print();
        printf("\n");
    }
    return 0;
}
