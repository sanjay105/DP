/*
Subset Sum Problem | DP-25
Geeks for Geeks
Input:
6
3 34 4 12 5 2
9
Output:
TRUE
*/
#include<iostream>
using namespace std;
bool SSP(int *a,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int j=1;j<=sum;j++){
        dp[0][j]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<a[i-1]){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int *a,n,sum;
    cin>>n;
    a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>sum;
    cout<<SSP(a,n,sum);
}