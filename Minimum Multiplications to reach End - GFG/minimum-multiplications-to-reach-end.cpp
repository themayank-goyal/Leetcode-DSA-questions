//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        vector<int> dist(100000, 1e9);
        
        queue<pair<int, int>> q;
        q.push({0, start});
        dist[start] = 0;
        
        while(q.size()){
            int steps = q.front().first, node = q.front().second;
            q.pop();
            
            for(auto it: arr){
                int newNode = (node*it)%100000;
                
                if(dist[node] + 1 < dist[newNode]){
                    if(newNode == end) return steps + 1;
                    dist[newNode] = dist[node] + 1;
                    q.push({dist[newNode], newNode});
                }                
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends