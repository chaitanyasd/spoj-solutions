#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void solve()
{
    long n, r, m;
    cin >> n >> r >> m;

    vector<vector<long>> adj(n + 1);
    vector<long> visited(n + 1, -1);
    queue<pair<pair<long, long>, long>> q;

    for (int i = 0; i < r; i++)
    {
        long a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < m; i++)
    {
        long city, s;
        cin >> city >> s;
        visited[city] = i;
        q.push({{city, s}, i});
    }

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        long city = node.first.first;
        long strength = node.first.second;
        long soldier = node.second;

        if (strength == 0)
            continue;

        for (long adjCity : adj[city])
        {
            if (visited[adjCity] == -1)
            {
                visited[adjCity] = soldier;
                q.push({{adjCity, strength - 1}, soldier});
            }
            else
            {
                if (visited[adjCity] != soldier)
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == -1)
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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