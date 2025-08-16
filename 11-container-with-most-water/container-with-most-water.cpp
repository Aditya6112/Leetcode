class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=INT_MIN;
        int i=0,j=height.size()-1;
        while(i<j){
            int h=min(height[i],height[j]);
            int w=j-i;
            area=max(area,h*w);

            if(height[j]<=height[i]){
                j--;
            }else{
                i++;
            }
        }
        return area;
    }
};