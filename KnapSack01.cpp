/*
0-1 Knapsack Problem | DP-10
Geeks for Geeks
Input:
3
60 10 
100 20 
120 30
50
Output:
220
*/
#include<iostream>
using namespace std;
int KnapSack(int *val,int *wt,int Weight,int n){
    int dp[n+1][Weight+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=Weight;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
            }
        }
    }
    return dp[n][Weight];
}
int main(){
    int n,*val,*wt;cin>>n;
    val=(int *)malloc(sizeof(int)*n);
    wt=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        cin>>val[i]>>wt[i];
    }
    int Weight;
    cin>>Weight;
    cout<<KnapSack(val,wt,Weight,n);
}