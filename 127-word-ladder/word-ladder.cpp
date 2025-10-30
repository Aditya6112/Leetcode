class Solution {
public:
    int ladderLength(string beginWord, string endWord,vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while (!q.empty()) {
            auto frontNode = q.front();
            string s = frontNode.first;
            int steps = frontNode.second;
            q.pop();
            if (s == endWord) return steps;
            for (int i = 0; i < s.size(); i++) {
                char originalChar = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    s[i] = ch;
                    if (st.find(s) != st.end()) {
                        st.erase(s);
                        q.push({s,steps+1});
                    }
                }
                s[i] = originalChar;
            }
        }
        return 0;
    }
};