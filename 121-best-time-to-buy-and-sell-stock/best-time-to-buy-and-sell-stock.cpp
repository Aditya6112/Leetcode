class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            int profit=0;
            if(prices[i]<buy){
                buy=prices[i];
            }else{
                profit=prices[i]-buy;
                max_profit=max(max_profit,profit);
            }
        }
        return max_profit;
    }
};