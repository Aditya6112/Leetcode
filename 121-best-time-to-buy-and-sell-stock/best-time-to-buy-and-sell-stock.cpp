class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minPrice=INT_MAX;
        for(auto p:prices){
            if(p<minPrice)minPrice=p;
            else{
                if(p-minPrice>maxProfit){
                    maxProfit=p-minPrice;
                }
            }
        }
        return maxProfit;
    }
};