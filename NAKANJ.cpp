#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

bool valid(int r, int c)
{
    return r >= 0 && c >= 0 && r < 8 && c < 8;
}

int solve()
{
    string s, e;
    cin >> s >> e;
    if (s == e)
        return 0;
    int sj = s[0] - 'a';
    int si = s[1] - '1';
    int ej = e[0] - 'a';
    int ei = e[1] - '1';
    int moves = 0;
    vector<vector<int>> nextMoves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        int n = q.size(), r, c;
        while (n--)
        {
            auto node = q.front();
            q.pop();

            if (node.first == ei && node.second == ej)
                return moves;

            for (auto nxt : nextMoves)
            {
                r = node.first + nxt[0];
                c = node.second + nxt[1];
                if (valid(r, c))
                    q.push({r, c});
            }
        }
        moves++;
    }

    return moves;
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
        cout << solve() << endl;
    }

    return 0;
}