#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void dfs(int node, vector<vector<int>> &graph, vector<int> &visited, long long &count)
{
    if (visited[node])
        return;
    count++;
    visited[node] = true;
    for (auto adj : graph[node])
        dfs(adj, graph, visited, count);
}

void solve()
{
    int m, n;
    cin >> n >> m;
    vector<int> visited(n + 1, false);
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    long long ans = 1, ways = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            long long count = 0;
            ways++;
            dfs(i, graph, visited, count);
            ans *= count;
            if (ans >= 1000000007)
                ans = ans % 1000000007;
        }
    }

    cout << ways << " " << ans << endl;
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