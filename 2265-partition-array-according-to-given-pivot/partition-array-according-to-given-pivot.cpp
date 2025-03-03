class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>leftEle;
        vector<int>rightEle;
        vector<int>eqEle;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                leftEle.push_back((nums[i]));
            }else if(nums[i]>pivot){
                rightEle.push_back(nums[i]);
            }else{
                eqEle.push_back(nums[i]);
            }
        }
        for(auto l:leftEle){
            ans.push_back(l);
        }
        for(auto e:eqEle){
            ans.push_back(e);
        }
        for(auto r:rightEle){
            ans.push_back(r);
        }
        return ans;
    }
};