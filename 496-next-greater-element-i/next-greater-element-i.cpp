class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int num1: nums1){
            int i=0;
            while(i<nums2.size()){
                if(nums2[i]==num1){
                    break;
                }
                i++;
            }
            if(i==nums2.size()){
                ans.push_back(-1);
            }else{
                bool found=false;
                while(i<nums2.size()){
                    if(nums2[i]>num1){
                        ans.push_back(nums2[i]);
                        found=true;
                        break;
                    }
                    i++;
                }
                if(!found){
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};