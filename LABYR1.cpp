#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m = 0, n = 0;

void dfs(int i, int j, int depth, int &maxDepth, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#' || visited[i][j])
        return;

    visited[i][j] = true;
    if (depth >= maxDepth)
    {
        m = i;
        n = j;
        maxDepth = depth;
    }

    for (auto d : dir)
        dfs(d[0] + i, d[1] + j, depth + 1, maxDepth, grid, visited);
}

void solve()
{
    int r, c;
    cin >> c >> r;

    if (r == 0)
    {
        cout << "Maximum rope length is 0." << endl;
        return;
    }

    vector<vector<char>> grid(r, vector<char>(c, '$'));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '.')
            {
                m = i;
                n = j;
            }
        }
    }

    int maxDepth = 0;
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    dfs(m, n, 0, maxDepth, grid, visited);

    vector<vector<bool>> visited1(r, vector<bool>(c, false));
    dfs(m, n, 0, maxDepth, grid, visited1);

    cout << "Maximum rope length is " << maxDepth << "." << endl;
    return;
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}