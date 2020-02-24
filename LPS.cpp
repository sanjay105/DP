#include <bits/stdc++.h>
using namespace std;
void printmatrix(int **a, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void reconstruct(int **dp,string s,int n,int resc){
	int start=0,end=n-1,cstart=0,cend=resc-1;
	char *res=(char *)malloc(sizeof(char)*resc);
	while(start!=end){
		if(s[start]==s[end]){
			res[cstart++]=s[start++];res[cend--]=s[end--];
		}else{
			if(dp[start+1][end]>=dp[start][end-1]){
				start++;
			}else{
				end--;
			}
		}
	}
	if(start==end){
	    res[cstart]=s[end];
	}
	cout<<res<<endl;
}
int lps(string s){
	int n=s.length();
	int **dp=(int **)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++){
		dp[i]=(int*)calloc(sizeof(int),n);
		dp[i][i]=1;
	}
	for (int l=2;l<=n;l++){
		for(int i=0;i<n-l+1;i++){
			int j=l+i-1;
			if(s[i]!=s[j]){
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}else if(j==i+1){
				dp[i][j]=2;
			}else{
				dp[i][j]=dp[i+1][j-1]+2;
			}
		}
	}
	printmatrix(dp,n);
	int resc=dp[0][n-1];
	reconstruct(dp,s,n,resc);
	return resc;
}
int main() {
	string s;
	cin>>s;
	int resc=lps(s);
	return 0;
}