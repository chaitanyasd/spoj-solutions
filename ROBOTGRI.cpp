#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void solve()
{
    long long n, mod = ((long long)1 << 31) - 1;
    cin >> n;
    vector<vector<long long>> grid(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
                grid[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[0][i] == -1)
            break;
        grid[0][i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == -1)
            break;
        grid[i][0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == -1)
                continue;

            long long top = grid[i - 1][j] == -1 ? 0 : grid[i - 1][j];
            long long left = grid[i][j - 1] == -1 ? 0 : grid[i][j - 1];
            grid[i][j] = (top + left) % mod;
        }
    }

    if (grid[n - 1][n - 1] > 0)
    {
        cout << grid[n - 1][n - 1] << endl;
        return;
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    q.push({0, 0});

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        if (node.first == n - 1 && node.second == n - 1)
        {
            cout << "THE GAME IS A LIE" << endl;
            return;
        }

        for (auto d : dir)
        {
            int r = d[0] + node.first, c = d[1] + node.second;

            if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == -1)
                continue;

            grid[r][c] = -1;
            q.push({r, c});
        }
    }

    cout << "INCONCEIVABLE" << endl;
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}