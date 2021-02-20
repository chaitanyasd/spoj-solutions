#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void solve()
{
    int n;
    cin >> n;
    vector<int> path(n + 1, 0);
    vector<vector<int>> keys(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 1; i < n; i++)
    {
        int k, num;
        cin >> k;
        while (k--)
        {
            cin >> num;
            keys[i].push_back(num);
        }
        sort(keys[i].begin(), keys[i].end());
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    path[1] = 1;

    while (!q.empty())
    {
        int boxNum = q.front();
        q.pop();

        if (boxNum == n)
        {
            vector<int> ans;

            int parent = path[n];
            while (parent != 1)
            {
                ans.push_back(parent);
                parent = path[parent];
            }
            ans.push_back(1);

            cout << ans.size() << endl;
            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i] << " ";
            cout << endl;
            return;
        }

        for (int nextBox : keys[boxNum])
        {
            if (!visited[nextBox])
            {
                visited[nextBox] = true;
                q.push(nextBox);
                path[nextBox] = boxNum;
            }
        }
    }

    cout << -1 << endl;
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
    while (t--)
    {
        solve();
    }

    return 0;
}