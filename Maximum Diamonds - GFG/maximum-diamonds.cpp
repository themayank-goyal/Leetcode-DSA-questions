//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        priority_queue<int> pq;
        long long res = 0;
        for(int i=0; i<N; i++){
            pq.push(A[i]);
        }
        for(int i=0; i<K && pq.size(); i++){
            int top = pq.top();
            pq.pop();
            pq.push(top/2);
            res += top;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends