class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col){
        // base case
        if(row < 0 || col < 0 || 
        row >= grid.size() || col >= grid[row].size() || 
        grid[row][col] == 0 ) return 0;

        int contri = 1;

        // mark that cell with land as visited
        grid[row][col] = 0;
        
        // go left
        contri += dfs(grid, row, col-1);
        // go right
        contri += dfs(grid, row, col+1);
        // go up
        contri += dfs(grid, row-1, col);
        // go down
        contri += dfs(grid, row+1, col);

        return contri;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
