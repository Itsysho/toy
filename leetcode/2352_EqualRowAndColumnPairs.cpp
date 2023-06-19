// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                bool isEqual = true;
                for (int k = 0; k < grid.size(); k++) {
                    if (grid[i][k] != grid[k][j]) {
                        isEqual = false;
                        break;
                    }
                }
                if (isEqual) ret++;
            }
        }
        return ret;
    }
};