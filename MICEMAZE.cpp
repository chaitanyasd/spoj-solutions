#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ
typedef pair<long, long> pll;

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long n, s, t, m;
    cin >> n >> s >> t >> m;

    vector<long> dist(n + 1, LONG_MAX);
    vector<bool> visited(n + 1, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<vector<pll>> graph(n + 1);

    while (m--)
    {
        long u, v, w;
        cin >> u >> v >> w;
        graph[v].push_back({u, w});
    }

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto from = pq.top();
        pq.pop();
        long u = from.second;
        if (visited[u])
            continue;
        visited[u] = true;

        for (auto to : graph[u])
        {
            long v = to.first;
            long w = to.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    long mice = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
        if (dist[i] <= t)
            mice++;
    }

    cout << mice;

    return 0;
}