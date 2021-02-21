#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ
bool cycle(int node, int prev, int &edges, vector<bool> &visited, vector<vector<int>> &graph)
{
    if (visited[node])
        return true;
    edges++;
    visited[node] = true;
    for (int adj : graph[node])
    {
        if (adj == prev)
            continue;
        if (cycle(adj, node, edges, visited, graph))
            return true;
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m != n - 1)
    {
        cout << "NO";
        return;
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int edges = 0;
    if (cycle(1, 0, edges, visited, graph))
        cout << "NO";
    else
    {
        // cout << "else" << edges << endl;
        if (edges == n)
            cout << "YES";
        else
            cout << "NO";
    }
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