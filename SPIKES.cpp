#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ
typedef pair<int, int> pii;

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n, spikes;
    cin >> m >> n >> spikes;
    queue<pair<pii, int>> q;
    vector<vector<char>> grid(m, vector<char>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = c;

            if (c == '@')
            {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }

    // int moves = 0;
    while (!q.empty())
    {
        int num = q.size();
        while (num--)
        {
            auto node = q.front();
            q.pop();
            int i = node.first.first, j = node.first.second, s = node.second;

            if (grid[i][j] == 'x')
            {
                if (s <= (spikes / 2))
                {
                    cout << "SUCCESS" << endl;
                    return 0;
                }
            }
            else
            {
                for (auto d : dir)
                {
                    int r = i + d[0];
                    int c = j + d[1];
                    int sp = s;

                    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '#' || visited[r][c])
                        continue;

                    if (grid[r][c] == 's')
                    {
                        sp++;
                        if (sp > (spikes / 2))
                            continue;
                    }
                    visited[r][c] = true;
                    q.push({{r, c}, sp});
                }
            }
        }
        // moves++;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}