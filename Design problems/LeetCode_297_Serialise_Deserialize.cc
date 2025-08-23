class Codec {
    int idx;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N|";
        string cur = to_string(root->val)+"|";
        string left = serialize(root->left);
        string right = serialize(root->right);
        cur.append(left);
        cur.append(right);
        return cur;
    }

    TreeNode* helper(vector<string> &data)
    {
        if(data[idx] == "N")
        {
            idx++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(data[idx]));
        idx++;
        root->left = helper(data);
        root->right = helper(data);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return nullptr;
        vector<string> buf;
        string cur = "";
        for(char ch: data)
        {
            if(ch == 'N') buf.emplace_back("N");
            else if(ch != '|') cur.push_back(ch);
            else if(ch == '|' and cur != "") 
            {
                buf.emplace_back(cur);
                cur = "";
            }
        }
        idx = 0;
        return helper(buf);
    }
};