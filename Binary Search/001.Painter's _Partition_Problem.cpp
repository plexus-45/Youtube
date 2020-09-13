#define mod 10000003
#define ll long long 


int no_painters(ll mid,vector<int> &C){

    int painters=1;
    ll sum=0;
    for(int i=0;i<C.size();i++){
        if(sum+C[i]> mid){
            painters++;
            sum=C[i];
            if(C[i]>mid){
                return INT_MAX;
            }
        }
        else{
            sum+=C[i];
        }
    }
    return painters;

}



int Solution::paint(int A, int B, vector<int> &C){

   ll low=LONG_MIN;
   ll high=0;
   for(int i=0;i<C.size();i++){
      low=max(low,(long long int)C[i]);
      high+=C[i];
   }

   //binary search 
   ll ans,mid;
   while(low<=high){
       mid=low+(high-low)/2;
       if(no_painters(mid,C)<=A){
          ans=mid;
          high=mid-1;
       }
       else{
          low=mid+1;
       }
   }
   return (ans*B)%mod;
}
