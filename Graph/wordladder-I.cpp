//https://leetcode.com/problems/word-ladder/

class Solution {
public:
    
    
    void transform(string temp,queue<string>& q, unordered_map<string ,int>& mp,unordered_map<string ,int>& vis){
        for(int i=0;i<temp.size();i++){
            string s=temp;
            for(int j=0;j<26;j++){
                s[i]='a'+j;
                if(mp.find(s)!=mp.end() && vis.find(s)==vis.end()){
                     q.push(s);
                     vis[s]=1;
                }
            }
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int ans=0;
        if(beginWord==endWord){
            return 0;
        }
        
        unordered_map<string ,int> mp;
        for(auto x :wordList){
            mp[x]=1;
        }
        
        if(mp.find(endWord)==mp.end()){
              return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        unordered_map<string ,int> vis;
        vis[beginWord]=1;
        ans=1;
        while(!q.empty()){
            
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto temp=q.front();
                q.pop();
                if(temp==endWord){
                    return ans;
                }
                transform(temp,q,mp,vis);
            }
            ans++;
        }
        return 0;
    }
};
