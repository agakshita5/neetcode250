class Solution {
public:
    set<pair<int,int>> visit;

    int dfs(vector<vector<int>>& grid, pair<int,int> v){
        // base case
        int contri = 0, row = v.first, col = v.second;
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[row].size() || grid[row][col] == 0) return 1;

        // go away from that dir
        if(grid[row][col] == 1) visit.insert({row,col});
        // go left
        if(!visit.contains({row, col-1})) contri += dfs(grid, {row,col-1});
        // go right
        if(!visit.contains({row, col+1})) contri += dfs(grid, {row,col+1});
        // go up
        if(!visit.contains({row-1, col})) contri += dfs(grid, {row-1,col});
        // go down
        if(!visit.contains({row+1, col})) contri += dfs(grid, {row+1,col});

        return contri;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    visit.insert({i,j});
                    ans = dfs(grid, {i,j});
                    return ans;
                }
            }
        }
    }
};