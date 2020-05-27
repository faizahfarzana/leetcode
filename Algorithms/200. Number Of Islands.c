Solution 1: DFS, using seperate array to track visited cells
void findIsland (char** grid, int** visited, int gridSize, int gridColSize, int row, int col);
    
int numIslands(char** grid, int gridSize, int* gridColSize){
    if (gridSize == 0 || *gridColSize == 0) 
        return 0;
    
    int count = 0;
    
    int **visited = malloc(gridSize * sizeof(int*));

    for (int i = 0 ; i < gridSize ; i++) 
        visited[i] = malloc ((*gridColSize) * sizeof(int));
    
    for (int row = 0; row < gridSize; ++row)
        for (int col = 0; col < *gridColSize; ++col)
            visited[row][col] = 0;
        
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < *gridColSize; ++col) {
            if (!visited[row][col] && grid[row][col] == '1') {
                count++;
                findIsland(grid, visited, gridSize, *gridColSize, row, col);
            }
        } 
    }

    return count;
}

void findIsland (char** grid, int** visited, int gridSize, int gridColSize, int row, int col) {
    if(row < 0 || row == gridSize || col < 0 || col == gridColSize)
        return;
    
    if (visited[row][col] || grid[row][col] == '0')  
        return;

    visited[row][col] = 1;

    findIsland(grid, visited, gridSize, gridColSize, row - 1, col);
    findIsland(grid, visited, gridSize, gridColSize, row + 1, col);
    findIsland(grid, visited, gridSize, gridColSize, row, col - 1);
    findIsland(grid, visited, gridSize, gridColSize, row, col + 1);
}


Solution 2: DFS, using in-place modification of visited cell

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (gridSize == 0 || *gridColSize == 0) 
        return 0;
    
    int count = 0;
        
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < *gridColSize; ++col) {
            if (grid[row][col] == '1') {
                count++;
                findIsland(grid, gridSize, *gridColSize, row, col);
            }
        } 
    }
        
    return count;
}

void findIsland (char** grid, int gridSize, int gridColSize, int row, int col) {
    if(row < 0 || row == gridSize || col < 0 || col == gridColSize || grid[row][col] == '0')
        return;

    grid[row][col] = '0';

    findIsland(grid, gridSize, gridColSize, row - 1, col);
    findIsland(grid, gridSize, gridColSize, row + 1, col);
    findIsland(grid, gridSize, gridColSize, row, col - 1);
    findIsland(grid, gridSize, gridColSize, row, col + 1);
}