https://www.interviewbit.com/problems/water-flow/

void dfs(int i,int j,int n,int m,vector<vector<int> > &A,vector<vector<int> > &vis ){
    
    
    if(i<0 || i>=n || j<0 || j>=m){
        return;
    }
    
    vis[i][j]=1;
    
    if(i+1<n && A[i][j]<=A[i+1][j] && vis[i+1][j]==0){
        dfs(i+1,j,n,m,A,vis);
    }
     
    if(j+1<m && A[i][j]<=A[i][j+1] && vis[i][j+1]==0){
        dfs(i,j+1,n,m,A,vis);
    }
     
    if(i-1>=0 && A[i][j]<=A[i-1][j] && vis[i-1][j]==0){
        dfs(i-1,j,n,m,A,vis);
    }
     
    if(j-1>=0 && A[i][j]<=A[i][j-1] && vis[i][j-1]==0){
        dfs(i,j-1,n,m,A,vis);
    }
}




int Solution::solve(vector<vector<int> > &A) {
    
    
    int n=(int)A.size();
    if(n==0){
        return 0;
    }
    int m=(int)A[0].size();
    
    
    vector<vector<int>> blue(n,vector<int>(m,0));
    vector<vector<int>> red(n,vector<int>(m,0));
    
    
    //blue side dfs
    for(int i=0;i<n;i++){
        dfs(i,0,n,m,A,blue);
    }
    for(int i=0;i<m;i++){
        dfs(0,i,n,m,A,blue);
    }
    
    //red side dfs
    for(int i=0;i<n;i++){
        dfs(i,m-1,n,m,A,red);
    }
    for(int i=0;i<m;i++){
        dfs(n-1,i,n,m,A,red);
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blue[i][j] && red[i][j]){
                ans++;
            }
        }
    }
    return ans;
    
}
