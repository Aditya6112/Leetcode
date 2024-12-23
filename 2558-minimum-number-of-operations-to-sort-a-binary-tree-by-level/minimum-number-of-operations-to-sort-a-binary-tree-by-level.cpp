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
	    vector<int>sortedNums(begin(nums),end(nums));
        sort(sortedNums.begin(),sortedNums.end());
        unordered_map<int,int>mpp;
        int swaps=0;
        int idx=0;
        for(auto num:nums){
            mpp[num]=idx;
            idx++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==sortedNums[i]){
                continue;
            }
            int currIdx=mpp[sortedNums[i]];
            mpp[nums[i]]=currIdx;
            mpp[nums[currIdx]]=i;
            swap(nums[i],nums[currIdx]);
            swaps++;
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