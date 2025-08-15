class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left_to_right_max;
        int maxi=INT_MIN;
        for(int i=0;i<height.size();i++){
            maxi=max(maxi,height[i]);
            left_to_right_max.push_back(maxi);
        }
        vector<int>right_to_left_max;
        maxi=INT_MIN;
        for(int i=height.size()-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            right_to_left_max.push_back(maxi);
        }
        reverse(right_to_left_max.begin(),right_to_left_max.end());

        int cap=0;
        for(int i=0;i<height.size();i++){
            if(height[i]<left_to_right_max[i] && height[i]<right_to_left_max[i]){
                cap+=min(left_to_right_max[i],right_to_left_max[i])-height[i];
            }
        }
        return cap;
    }
};