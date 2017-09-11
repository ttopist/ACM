#include <cstdio>
#include <stack>
using namespace std;

struct martix //when row==column==0 it represent '('
{
    int row,column;
    martix(int r,int c):row(r),column(c) {}
    martix(){row=0;column=0;}
    bool operator==(const martix& t) const {return row==t.row && column==t.column;}
};
const martix leftk(0,0);
martix m[27];



int main()
{
    //freopen("input.txt","r",stdin);

    int n,i,rows,columns;
    char c;

    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c %d %d\n",&c,&rows,&columns);
        m[c-'A'].row=rows;
        m[c-'A'].column=columns;
    }

    int ans=0;bool err=0;martix tmp1,tmp2;
    stack<martix> s;
    s.push(leftk);
    while((c=getchar())!=EOF)
    {
        if(c=='\n')
        {
            if(!err) printf("%d\n",ans);
            else printf("error\n");
            ans=0;err=0;
            while(!s.empty()) s.pop();
            s.push(leftk);
        }
        else if(c=='(') s.push(leftk);
        else if(c==')')
        {
            if(s.top()==leftk) s.pop();
            else {
                tmp2=s.top();s.pop();
                s.pop();
                if(s.top()==leftk)
                    s.push(tmp2);
                else{
                    tmp1=s.top();s.pop();
                    if(tmp1.column==tmp2.row)
                    {
                        ans+=tmp1.row * tmp1.column * tmp2.column;
                        s.push(martix(tmp1.row,tmp2.column));
                    }
                    else err=1;
                }
            }
        }
        else if('A'<=c && c<='Z')
        {
            if(s.top()==leftk) s.push(m[c-'A']);
            else{
                tmp2=m[c-'A'];
                tmp1=s.top();s.pop();
                if(tmp1.column==tmp2.row)
                {
                    ans+=tmp1.row * tmp1.column * tmp2.column;
                    s.push(martix(tmp1.row,tmp2.column));
                }
                else err=1;
            }
        }
    }
    return 0;
}
