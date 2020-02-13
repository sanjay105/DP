#include <iostream>
#include <limits.h>
using namespace std;
int MCM(int s[],int n){
  int m[n][n];
  for(int i=0;i<n;i++){
    m[i][i]=0;
  }
  int l;
  for(l=2;l<n;l++){
    for(int i=1;i<n-l+1;i++){
      int j=i+l-1;
      m[i][j]=INT_MAX;
      for(int k=i;k<=j-1;k++){
        int c=m[i][k]+m[k+1][j]+(s[i-1]*s[k]*s[j]);
        if(c<m[i][j]){
          m[i][j]=c;
        }
      }
    }
  }
  return m[1][n-1];
}
int main() {
  int s[5]={4,2,3,1,3};
  cout<<MCM(s,5);
}