class Solution {
public:
    static bool cmp(vector<int>& A,vector<int>& B){
        if(A[0]==B[0])return A[1]>B[1];
        return A[0]<B[0];
    }
    int lis(vector<int>& arr,int idx,int prev){
        if(idx>=arr.size())return 0;
        //include the number
        int include=0;
        if(prev==-1 || arr[prev]<arr[idx]){
            include=1+lis(arr,idx+1,idx);
        }
        //exclude
        int exclude=lis(arr,idx+1,prev);
        return max(include,exclude);
    }
    int dpWithBinarySearch(vector<int>& arr){
        if(arr.size()==0)return 0;
        vector<int>longest_increasing_length;
        longest_increasing_length.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(longest_increasing_length.back()<arr[i]){
                longest_increasing_length.push_back(arr[i]);
            }else{
                //find just greater element than arr[i]
                int idx=lower_bound(longest_increasing_length.begin(),longest_increasing_length.end(),arr[i])-longest_increasing_length.begin();
                longest_increasing_length[idx]=arr[i];
            }
        }
        return longest_increasing_length.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>heights;
        for(auto env:envelopes){
            heights.push_back(env[1]);
        }
        // return lis(heights,0,-1);
        return dpWithBinarySearch(heights);
    }
};