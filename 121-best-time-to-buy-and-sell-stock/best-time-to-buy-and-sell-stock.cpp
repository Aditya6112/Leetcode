class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int prev_price=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prev_price){
                int profit=prices[i]-prev_price;
                max_profit=max(max_profit,profit);
            }else{
                prev_price=prices[i];
            }
        }
        return max_profit;
    }
};