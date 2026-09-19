class Solution {
public:
    int dfs(vector<vector<int>>& grid, pair<int,int> v){
        // base case
        int contri = 1, row = v.first, col = v.second;

        if(row < 0 || col < 0 || 
        row >= grid.size() || col >= grid[row].size() || 
        grid[row][col] == 0 || grid[row][col] == -1) return 0;

        // mark that cell with land as visited
        grid[row][col] = -1;
        
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

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, {i,j});
                    cout<<area<<" ";
                    maxArea = max(maxArea, area);
                    cout<<maxArea<<endl;
                }
            }
        }
        return maxArea;
    }
};
