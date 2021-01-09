// https://www.spoj.com/problems/TOPOSORT/

#include <bits/stdc++.h>
#define MAX 50001

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<vector<int>> graph;
vector<int> order;
set<int> q;
vector<int> indegree;

int toposort()
{
    int u, v, cnt = 0;
    for (int i = 1; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.insert(i);
    }

    while (!q.size() > 0)
    {
        cnt++;
        u = *q.begin();
        q.erase(q.begin());
        order.push_back(u);

        for (int adj : graph[u])
        {
            indegree[adj]--;
            if (indegree[adj] == 0)
                q.insert(adj);
        }
    }

    return cnt;
}

int main()
{
    fast_cin();
    int m, n;
    cin >> n >> m;

    indegree.resize(n + 1, 0);
    graph.resize(n + 1, vector<int>(0));

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    int numNodes = toposort();
    if (numNodes != n)
        cout << "Sandro fails." << endl;
    else
    {
        cout << order[0];
        for (int i = 1; i < order.size(); i++)
            cout << " " << order[i];
    }

    return 0;
}