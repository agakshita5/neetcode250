class Solution {
public:
    int dfs(vector<vector<char>>& grid, pair<int,int> v){
        // base case
        int contri = 0, row = v.first, col = v.second;

        if(row < 0 || col < 0 || 
        row >= grid.size() || col >= grid[row].size() || 
        grid[row][col] == '0') return 1;

        if(grid[row][col] == '2') return contri;
        
        // mark that cell with land as visited
        grid[row][col] = '2';
        
        // go left
        contri += dfs(grid, {row,col-1});
        // go right
        contri += dfs(grid, {row,col+1});
        // go up
        contri += dfs(grid, {row-1,col});
        // go down
        contri += dfs(grid, {row+1,col});

        return contri;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    int ans = dfs(grid, {i,j});
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
