#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ

vector<bool> isPrime;

void findPrimes()
{
    isPrime.resize(10000, true);
    for (int p = 2; p * p <= 9999; p++)
    {
        if (isPrime[p] == true)
        {
            for (int i = p * p; i <= 9999; i += p)
                isPrime[i] = false;
        }
    }
}

vector<int> getNext(int n, vector<bool> &visited)
{
    string num = to_string(n);
    vector<int> nxt;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            string temp = num;
            if (i == 0 && j == 0)
                continue;

            temp[i] = '0' + j;
            int m = stoi(temp);
            if (!visited[m] && isPrime[m])
            {
                nxt.push_back(m);
                // cout << m << endl;
            }
        }
    }

    return nxt;
}

void solve()
{
    vector<bool> visited;
    int s, d, moves = 0;
    cin >> s >> d;
    if (s == d)
    {
        cout << moves << endl;
        return;
    }

    visited.resize(10000, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int steps = q.size();
        while (steps--)
        {
            int n = q.front();
            q.pop();

            vector<int> nextNumbers = getNext(n, visited);
            for (int &num : nextNumbers)
            {
                if (num == d)
                {
                    cout << moves + 1 << endl;
                    return;
                }

                visited[num] = true;
                q.push(num);
            }
        }
        moves++;
    }

    cout << "Impossible" << endl;
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    findPrimes();

    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }

    return 0;
}