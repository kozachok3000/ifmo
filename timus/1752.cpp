#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> request[50001];
vector<int>graph[20001];
int a[50001], b[50001], ans[50001];

void dfs1(int u, int v)
{
    int p;
    for (int i = 0; i < graph[u].size(); i++)
    {
        p = graph[u][i];
        if(p != v)
        {
        a[p] = a[u] + 1;
        dfs1(p, u);
        }
    }
}

void dfs2(int u, int v, int di)
{
    b[di] = u;
    int p, q;

    while(!request[u].empty())
    {
        p = request[u].back().first;
        if (p > di) break;
        q = request[u].back().second;
        ans[q] = b[di - p];
        request[u].pop_back();
    }
    for (int i = 0; i < graph[u].size(); i++)
    {
        p = graph[u][i];
        if (p != v)
            dfs2(p,u,di + 1);
    }
}
int main()
{
    int n, q, u, v;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= q; i++)
    {
        int c, d;
        cin >> c >> d;
        request[c].emplace_back(d, i);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(request[i].begin(), request[i].end());
        reverse(request[i].begin(), request[i].end());
    }

    int m = 0, e = 1, f = 1;
    dfs1(1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
            e = i;
        }
    }
    a[e] = m = 0;
    dfs1(e, -1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
            f = i;
        }
    }

    dfs2(e, -1, 0);
    dfs2(f, -1, 0);

    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;

    }
    return 0;
}

