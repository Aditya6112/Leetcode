class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>arr(colors.begin(),colors.end());
        for (int i = 0; i < k - 1; i++) {
            arr.push_back(colors[i]);
        }
        int i=0;
        int j=1;
        int cnt=0;
        while(j<arr.size()){
            if(arr[j]==arr[j-1]){
                i=j;
                j++;
                continue;
            }
            j++;
            if(j-i<k)continue;
            cnt++;
            i++;
        }
        return cnt;
    }
};