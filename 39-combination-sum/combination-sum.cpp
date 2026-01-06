class Solution {
public:
    void solve(vector<int>& candidates,int i,int target,vector<vector<int>>& ans,vector<int>& temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=candidates.size() || target<0){
            return;
        }
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(candidates,i,target-candidates[i],ans,temp);
            temp.pop_back();
        }
        solve(candidates,i+1,target,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<vector<int>>dp(candidates.size()+1,vector<int>(target+1,-1));
        solve(candidates,0,target,ans,temp);
        return ans;
    }
};