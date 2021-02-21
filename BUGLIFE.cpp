#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

bool dfs(int node, int c, vector<vector<int>> &graph, vector<int> &color)
{
    if (color[node] != 0)
        return color[node] != c;

    color[node] = -c;
    for (int adj : graph[node])
    {
        if (!dfs(adj, -c, graph, color))
            return false;
    }

    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> color(n + 1, 0);
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int s, d;
        cin >> s >> d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            if (!dfs(i, 1, graph, color))
            {
                cout << "Suspicious bugs found!" << endl;
                return;
            }
        }
    }

    cout << "No suspicious bugs found!" << endl;
    return;
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
    for (int i = 1; i <= t; i++)
    {
        cout << "Scenario #" << i << ":" << endl;
        solve();
    }
    return 0;
}