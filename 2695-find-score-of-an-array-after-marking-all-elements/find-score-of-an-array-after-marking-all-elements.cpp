class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<bool> vis(nums.size(), false);
        for(int i=0;i<nums.size();i++){
            q.push({nums[i],i});
        }
        while(!q.empty()){
            int num=q.top().first;
            int idx=q.top().second;
            q.pop();
            if(vis[idx]==false){
                sum+=num;
                vis[idx]=true;
                if(idx-1>=0)vis[idx-1]=true;
                if(idx+1<nums.size())vis[idx+1]=true;
            }
        }
        return sum;
    }
};