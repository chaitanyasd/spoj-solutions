// https://www.spoj.com/problems/MARYBMW/
// https://ideone.com/DXvfdq

#include <bits/stdc++.h>
#define MAX 50001

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

string s;
vector<int> v;

void solve(int n)
{
    cin >> s;
    v.clear();

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    long long res = 0;

    int start = 0, end = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            start = i;
            res += v[i] - v[0];
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            end = i;
            res += v[n - 1] - v[i];
            break;
        }
    }

    if (start == end)
    {
        cout << res << endl;
        return;
    }

    for (int i = start; i < end;)
    {
        int j = end;
        for (int k = i + 1; k < end; k++)
        {
            if (s[k] == '1')
            {
                j = k;
                break;
            }
        }

        int maxDiff = 0;
        for (int k = i; k < j; k++)
        {
            maxDiff = max(maxDiff, v[k + 1] - v[k]);
        }
        res += v[j] - v[i] - maxDiff;
        i = j;
    }

    cout << res << endl;
}

int main()
{
    fast_cin();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}