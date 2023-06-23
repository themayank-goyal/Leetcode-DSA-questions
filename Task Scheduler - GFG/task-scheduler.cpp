//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int k, vector<char> &tasks) {
        unordered_map<char, int> freq;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        for(auto it: tasks){
            freq[it]++;
        }
        for(auto it: freq){
            pq.push(it.second);
        }
        
        int time = 0;
        
        while(pq.size() || q.size()){
            time++;
            if(pq.size()){
                int top = pq.top();
                pq.pop();
                if(top > 1){
                    q.push({top-1, time+k});
                }
            }
            if(q.size()){
                auto it = q.front();
                if(it.second == time){
                    pq.push(it.first);
                    q.pop();
                }
            }
        }
        return time;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends