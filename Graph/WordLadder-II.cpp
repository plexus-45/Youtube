
//https://www.interviewbit.com/problems/word-ladder-ii/

void dfs(string start, string &end, unordered_map<string, vector<string> > & parents, vector<string> &current, vector<vector<string> > &answer) {
            if (start == end) {
                answer.push_back(current);
                return;
            }
            for (int i = 0; i < parents[start].size(); i++) {
                current.push_back(parents[start][i]);
                dfs(parents[start][i], end, parents, current, answer);
                current.pop_back();
            }
            return;
        }

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dictv) {
   
    
            unordered_set<string> dict(dictv.begin(), dictv.end());
            vector<vector<string> > answer; 
            unordered_map<string, int> distance; 
            queue<string> q; 
            unordered_map<string, vector<string> > parents;
            swap(start, end);
            
            //bfs
            distance[start] = 1;
            q.push(start);
            while (!q.empty()) {
                string word = q.front(); 
                q.pop();
                if (word == end) break;
                for (int i = 0; i < word.size(); i++) {
                    for (int j = 0; j < 26; j++) {
                        string newWord = word;
                        newWord[i] = 'a' + j;
                        if (dict.find(newWord) != dict.end()) {
                            if (distance.find(newWord) == distance.end()) { // seen for the first time
                                distance[newWord] = distance[word] + 1;
                                q.push(newWord);
                                parents[newWord].push_back(word);
                            } else if (distance[newWord] == distance[word] + 1) {
                                parents[newWord].push_back(word);
                            }
                        }
                    }
                }
            }
            if (distance.find(end) == distance.end()){
                return answer;
            } 
            
            vector<string> current;
            current.push_back(end);
            dfs(end, start, parents, current, answer);
            return answer; 
}
