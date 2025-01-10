class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        deque<int>dq;
        vector<int>ans;
        while(j<n){
            //calculation
            while(!dq.empty()){
                if(dq.back()<nums[j]){
                    dq.pop_back();
                }else{
                    break;
                }
            }
            dq.push_back(nums[j]);

            if(j-i+1<k)j++;
            else if(j-i+1==k){
                //ans calculation
                ans.push_back(dq.front());
                if(nums[i]==dq.front()){
                    dq.pop_front();
                }
                //slide the window
                i++;
                j++;
            }
        }
        return ans;
    }
};