//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_map<string, int> map;
        
        for(auto it: wordList){
            map[it]++;
        }
        
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        
        while(q.size()){
            string word = q.front().first; int l = q.front().second;
            if(word == targetWord) return l;
            map[word]--;
            q.pop();
            for(int i=0; i<targetWord.size(); i++){
                for(int j=0; j<26; j++){
                    string s = word;
                    s[i] = 'a' + j;
                    if(map[s] == 1){
                        q.push({s, l+1});
                    }
                }
            }            
            
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends