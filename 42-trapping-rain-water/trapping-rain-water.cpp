class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>leftMax;
        vector<int>rightMax;
        int n=height.size();

        int lM=height[0];
        leftMax.push_back(lM);
        for(int i=1;i<height.size();i++){
            lM=max(lM,height[i]);
            leftMax.push_back(lM);
        }

        int rM=height[n-1];
        rightMax.push_back(rM);
        for(int i=n-2;i>=0;i--){
            rM=max(rM,height[i]);
            rightMax.push_back(rM);
        }
        reverse(rightMax.begin(),rightMax.end());

        int ans=0;
        for(int i=0;i<n;i++){
            if(height[i]<leftMax[i] && height[i]<rightMax[i])
                ans+=min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
    }
};