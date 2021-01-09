// https://www.spoj.com/problems/MARYBMW/
// https://ideone.com/DXvfdq

#include <bits/stdc++.h>
#define MAX 50001

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<pair<long long, pair<int, int>>> edges;
vector<int> parent(MAX);
vector<int> urank(MAX, 1);

int find(int i)
{
    if (i != parent[i])
        parent[i] = find(parent[i]);
    return parent[i];
}

bool _union(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if (pa == pb)
        return false;

    if (urank[pa] > urank[pb])
        parent[pb] = pa;
    else if (urank[pb] > urank[pa])
        parent[pa] = pb;
    else
    {
        urank[pa]++;
        parent[pb] = pa;
    }

    return true;
}

void solve(int n)
{
    for (int i = edges.size() - 1; i >= 0; i--)
    {
        long long speed = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        _union(u, v);
        if (find(1) == find(n))
        {
            cout << speed << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    fast_cin();
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, a, b;
        long long v;
        cin >> n >> m;

        edges.clear();
        parent.resize(n + 1);
        urank.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        while (m--)
        {
            cin >> a >> b >> v;
            edges.push_back({v, {a, b}});
        }

        sort(edges.begin(), edges.end());
        solve(n);
    }

    return 0;
}