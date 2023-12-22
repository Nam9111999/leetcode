class Solution {
public:
    int dx[8] = {-1,0,1,1,1,0,-1,-1};
    int dy[8] = {-1,-1,-1,0,1,1,1,0};
    void bfs(vector<vector<int>>& grid,int m,int n) {
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()) {
            pair<int,int> top = q.front();q.pop();
            for(int k=0;k<8;k++){
                int i = top.first + dx[k];
                int j = top.second + dy[k];
                if(i >= 0 && i < m && j>=0&&j<m&& grid[i][j] == 0) {
                    q.push({i,j});
                    grid[i][j] = grid[top.first][top.second] + 1;
                }
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        int m = grid.size();
        int n = grid[0].size();
        if (grid[m-1][n-1] == 1) return -1;
        bfs(grid,m,n);
        if(grid[m-1][n-1] == 0) return -1;
        return grid[m-1][n-1];
    };
};
