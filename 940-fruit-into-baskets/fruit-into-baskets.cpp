class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int ans = 0;
        
        while (j < fruits.size()) {
            mp[fruits[j]]++;
            
            while (mp.size() > 2) {  // Shrink window if >2 types
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]); // Correct key removal
                }
                i++;
            }
            
            ans = max(ans, j - i + 1); // Update max length
            j++;
        }
        
        return ans;
    }
};
