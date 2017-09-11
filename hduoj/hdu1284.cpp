 #include<stdio.h>
int dp[35000];
int main(){
    int i,j;
    dp[0]=1;
    for(i=1;i<=3;i++)
        for(j=i;j<=35000;j++)
            dp[j]+=dp[j-i];
    int n;

    return 0;
}
