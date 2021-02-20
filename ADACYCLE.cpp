#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void solve(int start, int n, vector<vector<int>> &grid)
{
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int moves = 0;

    while (!q.empty())
    {
        int num = q.size();
        while (num--)
        {
            auto node = q.front();
            q.pop();

            for (int v = 0; v < n; v++)
            {
                if (grid[node][v] && v == start)
                {
                    cout << moves + 1 << endl;
                    return;
                }

                if (grid[node][v] && !visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        moves++;
    }

    cout << "NO WAY" << endl;
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        solve(i, n, grid);
    }

    return 0;
}