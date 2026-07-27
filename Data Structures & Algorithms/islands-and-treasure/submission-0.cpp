class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Push all treasure cells (sources) into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = r + dx[k];
                int nc = c + dy[k];

                // Check boundaries and visit only unvisited land cells (INF)
                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == INT_MAX) {

                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};

