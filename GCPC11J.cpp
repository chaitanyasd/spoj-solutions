#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, int &ans, int &ansNode, int depth)
{
    if (visited[node])
        return;
    visited[node] = true;

    if (depth > ans)
    {
        ans = depth;
        ansNode = node;
    }

    for (int adj : graph[node])
        dfs(adj, graph, visited, ans, ansNode, depth + 1);
}

void solve()
{
    int n;
    cin >> n;
    vector<bool> visited(n, false);
    vector<vector<int>> graph(n);

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0, ansNode = 0;
    dfs(0, graph, visited, ans, ansNode, 0);

    visited.clear();
    visited.resize(n, false);
    dfs(ansNode, graph, visited, ans, ansNode, 0);

    if (ans & 1)
        ans++;
    cout << ans / 2 << endl;
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