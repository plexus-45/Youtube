vector<int> func(vector<int>& A,int l,int r){
    
    vector<int> v(2,0);
    if(l==r){
        v[0]=v[1]=A[l];
        return v;
    }
    
    if(l+1==r){
        v[0]=min(A[l],A[r]);
        v[1]=max(A[l],A[r]);
        return v;
    }
    
    int mid=l+(r-l)/2;
    vector<int> left= func(A,l,mid-1);
    vector<int> right= func(A,mid,r);
    v[0]=min(left[0],right[0]);
    v[1]=max(left[1],right[1]);
    return v;
}


int Solution::solve(vector<int> &A) {
    
  vector<int> v;
  v=func( A,0,A.size()-1);
  return v[0]+v[1];
    
}
