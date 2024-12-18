class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>res;
        for(int i=0;i<prices.size();i++){
            int num=prices[i];
            res.push_back(num);
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]<=num){
                    res.pop_back();
                    res.push_back(num-prices[j]);
                    break;
                }
            }
        }
        return res;
    }
};