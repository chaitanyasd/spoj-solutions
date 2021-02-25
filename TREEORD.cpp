#include <bits/stdc++.h>

using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define OJ
#define LEFT 0
#define RIGHT 1

unordered_map<int, unordered_map<int, int>> tree;

int search(int data, int i, int j, vector<int> &arr)
{
    while (i <= j)
    {
        if (arr[i] == data)
            return i;
        i++;
    }

    return -1;
}

int dfs(vector<int> &in, vector<int> &pre, int i, int j, int &index)
{
    if (i > j)
        return -2;

    index++;
    int root = search(pre[index], i, j, in);
    if (root == -1)
        return -1;

    int left = dfs(in, pre, i, root - 1, index);
    if (left == -1)
        return -1;

    int right = dfs(in, pre, root + 1, j, index);
    if (right == -1)
        return -1;

    tree[root][LEFT] = left;
    tree[root][RIGHT] = right;

    return root;
}

bool checkPostorder(int root, vector<int> &in, vector<int> &post, int &index)
{
    if (root == -2)
        return true;
    int left = tree[root][LEFT], right = tree[root][RIGHT];

    checkPostorder(left, in, post, index);
    checkPostorder(right, in, post, index);

    return in[root] == post[index++];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> pre(n, -1), post(n, -1), in(n, -1);

    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];

    int index = -1;
    int root = dfs(in, pre, 0, n - 1, index);

    index = 0;
    if (root != -1)
    {
        if (checkPostorder(root, in, post, index) && index == post.size())
            cout << "yes";
        else
            cout << "no";
    }
    else
        cout << "no";
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}