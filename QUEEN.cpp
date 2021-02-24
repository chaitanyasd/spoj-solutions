#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void solve()
{
    int n, m, moves = 0, ans = INT_MAX;
    pair<int, int> s, f;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, 'X'));
    vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                s = {i, j};

            if (grid[i][j] == 'F')
                f = {i, j};
        }
    }

    if (s == f)
    {
        cout << moves << endl;
        return;
    }

    queue<pair<int, int>> q;
    q.push(s);
    cost[s.first][s.second] = 0;

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (auto d : dir)
        {
            int dr = d[0], dc = d[1], i = node.first, j = node.second;
            int r = i, c = j;

            while (true)
            {
                r += dr;
                c += dc;

                if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 'X' || cost[r][c] <= cost[i][j])
                    break;

                cost[r][c] = cost[i][j] + 1;

                if (grid[r][c] == 'F')
                    break;

                // cout << r << " " << c << endl;
                q.push({r, c});
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (cost[f.first][f.second] == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n", cost[f.first][f.second]);
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