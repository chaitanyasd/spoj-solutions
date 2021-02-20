#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void dfs(int node, vector<vector<int>> &graph, vector<int> &visited)
{
    if (visited[node])
        return;
    visited[node] = true;
    for (auto adj : graph[node])
        dfs(adj, graph, visited);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> visited(n, false);
    vector<vector<int>> graph(n);

    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans++;
            dfs(i, graph, visited);
        }
    }

    cout << ans << endl;
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