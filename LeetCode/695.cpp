class Solution {
private:
    int dfs(vector<vector<int>>& grid, int x, int y, int area) {
        
    
    if (x >=0 && y >= 0 && x <= grid.size()-1 && y <= grid[0].size()-1 && grid[x][y] == 1) {
        grid[x][y] = 0;
        area = 1 + dfs(grid, x+1, y, area) + dfs(grid, x, y+1, area) + dfs(grid, x-1, y, area) + dfs(grid, x, y-1, area);
        return area;
    }
        
        return 0;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        if (grid.size() == 0)
            return 0;
        
        int a = 0; 
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    a = max(a, dfs(grid, i, j, 0));
                }  
            }
        }
        
        return a;
        
    }
};
