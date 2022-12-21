#include <iostream>
#include <vector>

using namespace std;

vector <vector<pair<int,int>>> graph;
vector <vector< int > > dp;
vector < int > h;
vector < int > dist;

void dfs(int u,int par)
{
    //Обход в глубину
    dp[0][u] = par;

    for(auto [v,w] : graph[u])
    {
        if(v != par)
        {
            h[v] = h[u] + 1;
            dist[v] = dist[u] + w;
            dfs(v,u);
        }
    }
}

int main()
{
    int n, q, u, v, w, Lca, distCounter;

    cin >> n;

    graph.resize(n, vector < pair < int, int > > ());

    for(int i = 1; i < n; ++i)
    {

        cin>>u>>v>>w;
        graph[u].emplace_back(make_pair(v,w));
        graph[v].emplace_back(make_pair(u,w));
    }
    dist.resize(n ,0);
    h.resize(n, 0);
    dp.resize(17, vector < int > (n, 0));

    dfs(0, 0);
    for(int j = 1; j <= 16; ++j)
    {
        for(int i = 0; i < n; ++i)
        {
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }

    cin >> q;
    while(q--)
    {
        cin >> u >> v;

        distCounter = dist[u] + dist[v];
        if(h[u] < h[v])
        {
            swap(u, v);
        }
        for(int j = 16; j >= 0; --j)
        {
            if(h[dp[j][u]] >= h[v])
            {
                u = dp[j][u];
            }
        }
        if(u == v)
        {
            Lca = u;
        }
        else
        {
            for(int j = 16; j > -1; --j)
            {
                if(dp[j][u] != dp[j][v])
                {
                    u = dp[j][u];
                    v = dp[j][v];
                }
            }
            Lca = dp[0][u];
        }
        distCounter -= 2 * dist[Lca];

        cout << distCounter << endl;
    }
    return 0;
}

