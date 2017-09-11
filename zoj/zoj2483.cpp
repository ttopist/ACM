#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

queue<char> postfix;
char getans()
{
    stack<bool> ans;
    bool t,q;
    while(!postfix.empty())
    {
        switch(postfix.front())
        {
        case 'V':
            ans.push(1);break;
        case 'F':
            ans.push(0);break;
        case '!':
            t=!ans.top();ans.pop();ans.push(t);break;
        case '&':
            t=ans.top();ans.pop();q=ans.top();ans.pop();ans.push(t && q);break;
        case '|':
            t=ans.top();ans.pop();q=ans.top();ans.pop();ans.push(t || q);break;
        //default:;
        }
        postfix.pop();
    }
    return ans.top()?'V':'F';
}

int main()
{
    //freopen("input.txt","r",stdin);
    stack<char> opts;
    char x;
    int i=1;
    while(scanf("%c",&x)!=EOF)
    {
        if(x=='\n'){
            while(!opts.empty()) {postfix.push(opts.top());opts.pop();}
            printf("Expression %d: %c\n",i++,getans());
            }
        else if(x=='V' || x=='F')
            postfix.push(x);
        else if( x=='&' || x=='|'){
            while(!opts.empty() && opts.top()<=x && opts.top()!='(')
                {postfix.push(opts.top());opts.pop();}
            opts.push(x);}
        else if(x=='!')
            opts.push(x);
/*      else if(x=='!'|| x=='&' || x=='|'){
            if(!postfix.empty())
                while(!opts.empty() && opts.top()<=x && opts.top()!='(')
                    {postfix.push(opts.top());opts.pop();}
        opts.push(x);}*/
        else if(x=='(')
            opts.push(x);
        else if(x==')'){
            while(opts.top()!='(')
                {postfix.push(opts.top());opts.pop();}
            opts.pop();}
    }
    return 0;
}
//Segmentation fault if '!' is at the first.
//get wrong answer use code form line 52 to 56
