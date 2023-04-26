//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DisjointSet {
    vector<int> size, parent;
    public:
    
    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_v == ulp_u) return;
        
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_v];
        }
    }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        vector<vector<string>> ans;
        
        DisjointSet ds(accounts.size());
        
        unordered_map<string, int> eta;
        
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                if(eta.find(email) == eta.end()){
                    eta[email] = i;
                }
                else{
                    ds.unionBySize(eta[email], i);
                }
            }
        }
        
        unordered_map<int, set<string>> map;
        
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                int ulp_email = ds.findUPar(eta[email]);
                map[ulp_email].insert(email);
            }
        }
        
        for(auto it: map){
            vector<string> account;
            account.push_back(accounts[it.first][0]);
            set<string> v = it.second;
            for(auto s : v){
                account.push_back(s);
            }
            ans.push_back(account);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends