#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, s, g, u, d, moves = 0;
    cin >> n >> s >> g >> u >> d;
    vector<int> visited(n + 1, false);
    queue<int> q;
    q.push(s);
    if (s == g)
    {
        cout << moves << endl;
        return 0;
    }

    while (!q.empty())
    {
        int num = q.size();
        while (num--)
        {
            int next = q.front();
            q.pop();
            if (visited[next])
                continue;
            visited[next] = true;

            int t = next + u;
            if (t == g)
            {
                cout << moves + 1 << endl;
                return 0;
            }
            if (t <= n && !visited[t])
            {
                q.push(t);
            }

            t = next - d;
            if (t == g)
            {
                cout << moves + 1 << endl;
                return 0;
            }
            if (t >= 1 && !visited[t])
            {
                q.push(t);
            }
        }
        moves++;
    }

    cout << "use the stairs" << endl;

    return 0;
}