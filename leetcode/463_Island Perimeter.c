// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                if (i == 0 || grid[i - 1][j] == 0) ret++;
                if (i == gridSize - 1 || grid[i + 1][j] == 0) ret++;
                if (j == 0 || grid[i][j - 1] == 0) ret++;
                if (j == gridColSize[i] - 1 || grid[i][j + 1] == 0) ret++;
            }
        }
    }
    return ret;
}