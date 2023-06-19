// You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

// Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

// Two paths are considered different if they do not have exactly the same sequence of visited cells.

struct Point {
    int x, y, val;
    Point(int x = 0, int y = 0, int val = 0): x(x), y(y), val(val) {}
    bool operator<(const Point &other) const {
        return val < other.val;
    }
};
class Solution {
public:
    static const int MOD = 1000000007;
    int countPaths(vector<vector<int>>& grid) {
        vector<Point> xy;
        vector<vector<int>> dp;
        int n = grid.size();
        int m = grid[0].size();
        xy.reserve(n*m);
        dp.reserve(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                xy.push_back(Point(i, j, grid[i][j]));
            dp.push_back(vector<int>(m, 0));
        }

        sort(xy.begin(), xy.end());
        for (Point &p : xy) {
            int way = 1;
            if (p.x > 0 && grid[p.x - 1][p.y] < p.val) {
                way += dp[p.x - 1][p.y];
                way %= MOD;
            }
            if (p.y > 0 && grid[p.x][p.y - 1] < p.val) {
                way += dp[p.x][p.y - 1];
                way %= MOD;
            }
            if (p.x + 1 < n && grid[p.x + 1][p.y] < p.val) {
                way += dp[p.x + 1][p.y];
                way %= MOD;
            }
            if (p.y + 1 < m && grid[p.x][p.y + 1] < p.val) {
                way += dp[p.x][p.y + 1];
                way %= MOD;
            }
            dp[p.x][p.y] = way;
        }

        int ret = 0;
        for (vector<int> &way : dp) {
            for (int val : way) {
                ret += val;
                ret %= MOD;
            }
        }

        return ret;
    }
};