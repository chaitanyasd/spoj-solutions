// https://www.spoj.com/problems/BLINNET/

#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<pair<long long, pair<int, int>>> edges;
vector<int> parent;
vector<int> urank;

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
    long long ans = 1, i = 0;
    int vt = 0;
    while (vt < n-1)
    {
        long long cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (_union(u, v))
        {
            vt++;
            ans *= cost;
        }
        i++;
    }

    cout << __builtin_ctzll(ans) + 1 << endl;
}

// int log2(long long pow)
// {
//     int ans = -1;
//     while (pow)
//     {
//         pow >>= 1;
//         ans++;
//     }
//     return ans;
// }

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
        urank.clear();
        parent.clear();

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