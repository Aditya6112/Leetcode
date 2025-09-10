class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diagMap;

        // Store all diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                diagMap[i - j].push_back(grid[i][j]);
            }
        }

        // Sort each diagonal according to rules
        for (auto& [key, vec] : diagMap) {
            if (key >= 0) {
                // Bottom-left & main diagonal → non-increasing
                sort(vec.begin(), vec.end(), greater<int>());
            } else {
                // Top-right → non-decreasing
                sort(vec.begin(), vec.end());
            }
        }

        // Refill matrix
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                grid[i][j] = diagMap[key][idx[key]++];
            }
        }

        return grid;
    }
};