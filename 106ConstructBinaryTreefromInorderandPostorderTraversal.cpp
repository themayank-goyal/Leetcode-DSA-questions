/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> map;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int s, int e, int& postIndex){
      if(s > e) return NULL;
      int inorderRootIndex = map[postorder[postIndex]];
      TreeNode* root = new TreeNode(postorder[postIndex]);
      postIndex--;
      root->right = helper(inorder, postorder, inorderRootIndex+1, e, postIndex);
      root->left = helper(inorder, postorder, s, inorderRootIndex-1, postIndex);
      return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      for(int i=0; i<inorder.size(); i++){
        map[inorder[i]] = i;
      }
      int postIndex = postorder.size()-1;
      return helper(inorder, postorder, 0, inorder.size()-1, postIndex);
    }
};