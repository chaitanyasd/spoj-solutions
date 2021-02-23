#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

bool paradox(int s, vector<bool> &status, vector<bool> &visited, unordered_map<int, pair<int, bool>> &grid)
{
    int nextStatement = grid[s].first;
    bool nextStatementStatus = grid[s].second, nodeStatus = status[s];

    visited[s] = true;
    if (visited[nextStatement])
    {
        if (nodeStatus == false)
            nextStatementStatus = !nextStatementStatus;

        if (nextStatementStatus != status[nextStatement])
            return true;
        return false;
    }

    status[nextStatement] = nextStatementStatus;
    if (nodeStatus == false)
        status[nextStatement] = !status[nextStatement];

    return paradox(nextStatement, status, visited, grid);
}

void solve(int n)
{
    vector<bool> visited(n + 1, false), status(n + 1, false);
    unordered_map<int, pair<int, bool>> grid;

    for (int i = 1; i <= n; i++)
    {
        int a;
        string status;
        cin >> a >> status;
        grid[i] = {a, status == "true" ? true : false};
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            vector<bool> temp(status.begin(), status.end()), vis(visited.begin(), visited.end());

            status[i] = true;
            if (paradox(i, status, visited, grid))
            {
                temp[i] = false;
                if (paradox(i, temp, vis, grid))
                {
                    cout << "PARADOX" << endl;
                    return;
                }
            }
        }
    }

    cout << "NOT PARADOX" << endl;
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            return 0;
        solve(n);
    }

    return 0;
}