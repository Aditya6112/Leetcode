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
    int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int swaps=0;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second==i) continue;
	        else {
	            swaps++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return swaps;
	}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int no_of_swaps=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>nodes;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                int num=temp->val;
                nodes.push_back(num);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            no_of_swaps+=minSwaps(nodes);
        }
        return no_of_swaps;
    }
};