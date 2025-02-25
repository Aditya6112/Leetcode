const int MOD=1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int evenCnt=1;
        int oddCnt=0;
        int result=0;
        int prefixSum=0;
        for(auto num:arr){
            prefixSum+=num;
            if(prefixSum%2==0){
                result=(result+oddCnt)%MOD;
                evenCnt++;
            }
            else{
                result=(result+evenCnt)%MOD;
                oddCnt++;
            }
        }
        return result;
    }
};