class Solution {
private:
    void bfs(int r , int c , vector<vector<char>>&matrix , vector<vector<int>>&vis ,int n , int m){
        vis[r][c] = 1;
        queue<pair<int,int>>q;
        q.push({r,c});
        int dx [] = {1,-1,0,0};
        int dy [] = {0,0,1,-1};

        while(!q.empty()){
            auto itr = q.front();
            q.pop();
            int _r = itr.first;
            int _c = itr.second;

            for(int i=0 ; i<4 ; i++){
                int nr = _r + dx[i];
                int nc = _c + dy[i];
                if(nr<n && nr>=0 && nc<m && nc>=0 && matrix[nr][nc]=='1' && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0 ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,grid,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
