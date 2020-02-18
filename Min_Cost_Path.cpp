/*
Min Cost Path | DP-6
Geeks for Geeks
Input:
3 3
1 2 3
4 8 2
1 5 3
2 2
Output:
8
*/
#include<iostream>
using namespace std;
int R,C;
int min(int a,int b,int c){
    if(a>b){
        return b>c?c:b;
    }else{
        return a>c?c:a;
    }
}
int MCP(int **m,int x,int y,int **dp){
    dp[0][0]=m[0][0];
    for(int i=1;i<=x;i++){
        dp[i][0]=dp[i-1][0]+m[i][0];
    }
    for(int i=1;i<=y;i++){
        dp[0][i]=dp[0][i-1]+m[0][i];
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+m[i][j];
        }
    }
    return dp[x][y];
}
int main(){
    int **m,**dp,r,c;
    cin>>r>>c;
    m=(int **)malloc(sizeof(int*)*r);
    dp=(int **)malloc(sizeof(int*)*r);
    for(int i=0;i<r;i++){
        m[i]=(int *)calloc(sizeof(int),c);
        dp[i]=(int *)calloc(sizeof(int),c);
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }
    R=r;C=c;
    int x,y;cin>>x>>y;
    cout<<MCP(m,x,y,dp)<<endl;
}