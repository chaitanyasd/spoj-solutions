#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

int dfs(int node, vector<vector<int>> &graph, vector<int> &visited, vector<int> &dp, int t)
{
    // cout << node << endl;
    if (node == t)
        return 1;

    if (visited[node])
        return 0;

    if (dp[node] != -1)
        return dp[node];

    visited[node] = true;
    int sum = 0;

    for (int adj : graph[node])
    {
        sum += dfs(adj, graph, visited, dp, t);
        if (sum >= 1000000007)
            sum = sum % 1000000007;
    }

    visited[node] = false;
    dp[node] = sum;
    return sum;
}

int bfs(int s, vector<vector<int>> &graph, vector<int> &visited, vector<int> &dp, int t)
{
    fill(dp.begin(), dp.end(), 0);
    dp[s] = 1;
    fill(visited.begin(), visited.end(), false);

    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (visited[node])
            continue;
        visited[node] = true;

        for (int adj : graph[node])
        {
            dp[adj] += dp[node];
            dp[adj] %= 1000000007;
            q.push(adj);
        }
    }

    return dp[t];
}

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<int> visited(n + 1, false), dp(n + 1, -1);
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    if (s == t)
    {
        cout << 0 << endl;
        return;
    }

    // cout << dfs(s, graph, visited, dp, t) << endl;
    cout << bfs(s, graph, visited, dp, t) << endl;
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