//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int den[] = {0, 0, 0};
        int n = bills.size();
        for(int i=0; i<n; i++){
            if(bills[i] == 5) den[0]++;
            else if(bills[i] == 10){
                if(den[0] >= 1){ den[0]--; den[1]++;}
                else return false;
            }
            else{
                if(den[0] >= 1 && den[1] >= 1){
                    den[2]++;
                    den[0]--;
                    den[1]--;
                }
                else if(den[0] > 2){
                    den[0] -= 3;
                    den[2]++;
                }
                else return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends