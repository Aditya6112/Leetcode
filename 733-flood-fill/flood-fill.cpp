class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == color) return image; // no change needed
        
        int dirx[] = {-1, 0, 1, 0};
        int diry[] = {0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int x = i + dirx[k];
                int y = j + diry[k];
                
                if (x >= 0 && y >= 0 && x < m && y < n && image[x][y] == oldColor) {
                    image[x][y] = color;
                    q.push({x, y});
                }
            }
        }
        return image;
    }
};
