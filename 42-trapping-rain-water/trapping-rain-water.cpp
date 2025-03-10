class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int>leftMax;
        leftMax.push_back(height[0]);

        vector<int>rightMax;
        rightMax.push_back(height[n-1]);


        for(int i=1;i<n;i++){
            if(height[i]>=leftMax[i-1]){
                leftMax.push_back(height[i]);
            }else{
                leftMax.push_back(leftMax[i-1]);
            }
        }

        int prev=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(height[i]>prev){
                prev=height[i];
                rightMax.push_back(height[i]);
            }else{
                rightMax.push_back(prev);
            }
        }
        reverse(rightMax.begin(),rightMax.end());

        int capacity=0;
        for(int i=0;i<n;i++){
            if(height[i]<leftMax[i] && height[i]<rightMax[i]){
                capacity+=min(leftMax[i],rightMax[i])-height[i];
            }
        }
        return capacity;
    }
};