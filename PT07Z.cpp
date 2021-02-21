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
    vector<bool> visited(n + 1, false);
    vector<vector<int>> graph(n + 1);

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0, ansNode = 1;
    dfs(1, graph, visited, ans, ansNode, 0);

    visited.clear();
    visited.resize(n + 1, false);
    dfs(ansNode, graph, visited, ans, ansNode, 0);

    cout << ans << endl;
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