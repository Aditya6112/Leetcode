class Solution {
public:
    int solve(vector<int>& days, int idx, vector<int>& costs, vector<int>& dp) {
        if (idx >= days.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int cost1 = costs[0] + solve(days, idx + 1, costs, dp);

        int i;
        for (i = idx; i < days.size() && days[i] < days[idx] + 7; i++)
            ;

        int cost2 = costs[1] + solve(days, i, costs, dp);

        for (i = idx; i < days.size() && days[i] < days[idx] + 30; i++)
            ;

        int cost3 = costs[2] + solve(days, i, costs, dp);
        
        return dp[idx] = min({cost1, cost2, cost3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, -1);
        return solve(days, 0, costs, dp);
    }
};