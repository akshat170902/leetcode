class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j, int curr, int tot)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
        {
            return 0;
        }
        if (grid[i][j] == 2)
        {
            if (curr == tot)
            {
                return 1;
            }
            return 0;
        }
        grid[i][j] = -1;
        int cnt = solve(grid, i - 1, j, curr + 1, tot) + solve(grid, i + 1, j, curr + 1, tot) + solve(grid, i, j - 1, curr + 1, tot) + solve(grid, i, j + 1, curr + 1, tot);
        grid[i][j] = 0;
        return cnt;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int i, j, curr = 1, tot = 0;
        for (int ii = 0; ii < grid.size(); ii++)
        {
            for (int jj = 0; jj < grid[ii].size(); jj++)
            {
                if (grid[ii][jj] == 1)
                {
                    i = ii;
                    j = jj;
                }
                if (grid[ii][jj] != -1)
                {
                    tot++;
                }
            }
        }
        return solve(grid, i, j, curr, tot);
    }
};