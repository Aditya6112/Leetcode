class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int buy=prices[0];
        for(auto price:prices){
            int profit=price-buy;
            if(profit>maxProfit){
                maxProfit=profit;
            }
            buy=min(buy,price);
        }
        return maxProfit;
    }
};