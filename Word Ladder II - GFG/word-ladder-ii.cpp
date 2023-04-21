//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        unordered_map<string, int> map;
        
        for(auto it: wordList){
            map[it]++;
        }
        
        queue<vector<string>> q;
        
        q.push({startWord});
        
        vector<string> usedSequence;
        vector<vector<string>> res;
        
        while(q.size()){
            int n = q.size();
            
            for(int i=0; i<n; i++){
                vector<string> v = q.front();
                q.pop();
                string word = v.back();
                
                if(word == targetWord) {
                    if(res.size() == 0){
                        res.push_back(v);
                    }
                    else if(res[0].size() == v.size()){
                        res.push_back(v);
                    }
                }
                
                for(int j=0; j<startWord.size(); j++){
                    for(int k=0; k<26; k++){
                        string s = word;
                        s[j] = 'a'+k;
                        if(map[s] == 1){
                            usedSequence.push_back(s);
                            v.push_back(s);
                            q.push(v);
                            v.pop_back();
                        }
                    }
                }
            }
            
            for(auto it: usedSequence){
                map[it] = 0;
                usedSequence.clear();
            }
            
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends