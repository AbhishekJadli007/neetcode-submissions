class Solution {
private:
int dfs(int r , int c , vector<vector<int>>&grid , vector<vector<int>>&vis , int n , int m){
    vis[r][c] = 1;
    int res = 1;
    int dx [] = {+1,-1,0,0};
    int dy [] = {0,0,+1,-1};

    for(int i=0 ; i<4 ; i++){
        int _r = r+dx[i];
        int _c = c+dy[i];

        if(_r>=0 && _r<n && _c>=0 && _c<m && !vis[_r][_c] && grid[_r][_c]==1){
            res = res+ dfs(_r,_c,grid,vis,n,m);
        }
    }

    return res;
}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int ans = 0 ;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans = max(ans,dfs(i,j,grid,vis,n,m));
                }
            }
        }
        return ans;
    }
};
