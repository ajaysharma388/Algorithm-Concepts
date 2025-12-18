#define mp make_pair
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> Q;
        Q.push(mp(root, 0));
        int level = 0;
        while(!Q.empty())
        {
            vector<int> buffer;
            int sz = Q.size();
            for(int i = 0; i < sz; ++i)
            {
                TreeNode* cur = Q.front().first;
                int lvl = Q.front().second;
                Q.pop();
                buffer.push_back(cur->val);
                if(cur->left) Q.push(mp(cur->left, lvl+1));
                if(cur->right) Q.push(mp(cur->right, lvl+1));
            }
            if(level & 1) reverse(buffer.begin(), buffer.end());
            level += 1;
            ans.push_back(buffer);
        }
        return ans;
    }
};