// https://www.spoj.com/problems/RPLA/
// https://ideone.com/VqCzUr

#include <bits/stdc++.h>
#define MAX 50001

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<vector<int>> graph;
priority_queue<int, vector<int>, greater<int>> q;
vector<int> indegree;

int toposort()
{
    int u, v, cnt = 1;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        while (n--)
        {
            u = q.top();
            q.pop();
            temp.push_back(u);
        }
        for (int u : temp)
        {
            cout << cnt << " " << u << endl;

            for (int adj : graph[u])
            {
                indegree[adj]--;
                if (indegree[adj] == 0)
                    q.push(adj);
            }
        }
        cnt++;
    }

    return cnt;
}

int main()
{
    fast_cin();
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int r, n;
        cin >> n >> r;

        while (!q.empty())
            q.pop();

        indegree.clear();
        graph.clear();

        indegree.resize(n, 0);
        graph.resize(n, vector<int>(0));

        while (r--)
        {
            int u, v;
            cin >> u >> v;
            graph[v].push_back(u);
            indegree[u]++;
        }

        cout << "Scenario #" << k << ":" << endl;
        toposort();
    }

    return 0;
}