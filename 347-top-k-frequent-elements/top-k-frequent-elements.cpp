class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> A, pair<int, int> B) {
            return A.second < B.second; 
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>maxH;
        unordered_map<int,int>freq;
        vector<int>res;

        for(auto num:nums){
            freq[num]++;
        }

        for(auto it:freq){
            maxH.push({it.first,it.second});
        }

        while(k-- && !maxH.empty()){
            int top=maxH.top().first;
            maxH.pop();
            res.push_back(top);
        }
        return res;
    }
};