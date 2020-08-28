// https://www.spoj.com/problems/EDIST/

#include <bits/stdc++.h> 
using namespace std; 
 
int dp[5000][5000];
int func(string& a,string& b,int m,int n){
 
    if(m==0){
        return n;
    }
    if(n==0){
        return m;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(a[m-1]==b[n-1]){
        return dp[n][m]=func(a,b,m-1,n-1);
    }
    else{
        return dp[n][m]= 1+ min(func(a,b,m-1,n),min(func(a,b,m,n-1),func(a,b,m-1,n-1)));
    }
 
}
 
 
int main(){
 
    int t;
    cin>>t;
 
 
    while(t--){
       string a,b;
       cin>>a>>b;
 
       memset(dp,-1,sizeof(dp));
       int ans= func(a,b,a.size(),b.size());
       cout<<ans<<endl;
    }
    
} 
