Solution 1: DFS, using seperate vector to check visited cells

class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
    
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    count++;
                    findIsland(grid, visited, row, col);
                }
            } 
        }
        
        return count;
    }
    
    void findIsland (vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if(row < 0 || row == grid.size() || col < 0 || col == grid[row].size())
            return;
        
        if (visited[row][col] == true || grid[row][col] == '0')  
            return;
        
        visited[row][col] = true;
            
        findIsland(grid, visited, row - 1, col);
        findIsland(grid, visited, row + 1, col);
        findIsland(grid, visited, row, col - 1);
        findIsland(grid, visited, row, col + 1);
    }
};

Solution 2: DFS, using in-place modification of visited cells

class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
    
        //vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == '1') {
                    count++;
                    findIsland(grid, row, col);
                }
            } 
        }
        
        return count;
    }
    
    void findIsland (vector<vector<char>>& grid, int row, int col) {
        if(row < 0 || row == grid.size() || col < 0 || col == grid[row].size() || grid[row][col] == '0')
            return;
        
        grid[row][col] = '0';
            
        findIsland(grid, row - 1, col);
        findIsland(grid, row + 1, col);
        findIsland(grid, row, col - 1);
        findIsland(grid, row, col + 1);
    }
};