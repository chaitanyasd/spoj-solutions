#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void solve()
{
    int m, n;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dist(n + 1, INT_MAX);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a != b)
        {
            adj[b].push_back({a, 1});
            adj[a].push_back({b, 0});
        }
        else
            adj[a].push_back({b, INT_MAX});
    }

    deque<int> q;
    q.push_front(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        // cout << node << endl;

        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;

                if (w == 1)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }

    if (dist[n] == INT_MAX)
    {
        cout << -1 << endl;
        return;
    }

    cout << dist[n] << endl;
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