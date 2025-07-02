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
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode*>    q;
    
            vector<vector<int>> ans;
            if (!root)
                return ans;
            q.push(root);
            while (!q.empty()) {
                int cnt = q.size();
                vector<int> level_values;
                for (int i = 0; i < cnt; i++) {
                    TreeNode* node = q.front(); q.pop();
                    level_values.push_back(node->val);
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                ans.push_back(level_values);
            }
            return ans;
        }
    };
