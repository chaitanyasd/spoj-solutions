#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

void change(int i, int j, string &s)
{
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }
}

int solve(string start, string end)
{
    // cout << "new---" << endl;
    if (start == end)
        return 0;
    int steps = 0;
    queue<string> q;
    unordered_set<string> s;
    q.push(start);
    s.insert(start);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            string nextString = q.front();
            q.pop();
            // cout << nextString << endl;

            for (int i = 0; i < 10; i++)
            {
                for (int j = i + 1; j < 10; j++)
                {
                    // if (i == j)
                    //     continue;
                    string t = nextString;
                    change(i, j, t);

                    if (t == end)
                        return steps + 1;

                    if (s.find(t) == s.end())
                    {
                        s.insert(t);
                        q.push(t);
                        // cout << i << " " << j << " " << nextString << " " << t << endl;
                    }
                }
            }
        }

        steps++;
    }

    return -1;
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string start, end;
    while (true)
    {
        cin >> start >> end;
        if (start == "*" || end == "*")
            break;

        cout << solve(start, end) << endl;
    }

    return 0;
}