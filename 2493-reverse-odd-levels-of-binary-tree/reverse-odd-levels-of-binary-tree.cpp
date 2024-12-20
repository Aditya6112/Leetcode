class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        bool isOddLevel = false; 
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<TreeNode*> currentLevelNodes;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelNodes.push_back(node);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (isOddLevel) {
                int n = currentLevelNodes.size();
                for (int i = 0; i < n / 2; i++) {
                    swap(currentLevelNodes[i]->val, currentLevelNodes[n - i - 1]->val);
                }
            }
            isOddLevel = !isOddLevel;
        }
        
        return root;
    }
};
