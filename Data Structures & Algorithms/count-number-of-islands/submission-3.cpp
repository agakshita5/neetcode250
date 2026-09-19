class Solution {
public:
    void dfs(vector<vector<char>>& grid, pair<int,int> v){
        // base case
        int row = v.first, col = v.second;

        if(row < 0 || col < 0 || 
        row >= grid.size() || col >= grid[row].size() || 
        grid[row][col] == '0') return;
        
        // mark that cell with land as visited
        grid[row][col] = '0';
        
        // go left
        dfs(grid, {row,col-1});
        // go right
        dfs(grid, {row,col+1});
        // go up
        dfs(grid, {row-1,col});
        // go down
        dfs(grid, {row+1,col});
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, {i,j});
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
