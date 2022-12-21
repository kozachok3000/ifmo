#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> L[100];
vector<int> W[100];
int mem[101][100];

int dp(int cur, int prev, int q)
{
    if(q == 0)
        return 0;
    else
    {
        int &res= mem[cur][q];

        if(res == -1)
        {
            int g = L[cur].size();
            res = 0;

            if(g > 1)
            {
                for(int i = g - 1; i >= 0; i--)
                {
                    if(L[cur][i] != prev)
                    {
                        for(int j = i-1; j >= 0; j--)
                        {
                            if(L[cur][j] != prev)
                            {
                                for(int k = 0; k <= q; k++)
                                {
                                    int t1 = 0, t2 = 0;
                                    if(k != 0)
                                        t1 = W[cur][i]+dp(L[cur][i],cur,k-1);

                                    if(k != q)
                                        t2 = W[cur][j]+dp(L[cur][j],cur,q-k-1);

                                    res = max(res, t1+t2);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
}

int main()
{
    int n, q, u, v, w;
    cin >> n >> q;

    for(int i = 1; i < n ; i++)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        L[u].push_back(v);
        L[v].push_back(u);
        W[u].push_back(w);
        W[v].push_back(w);
    }

    memset(mem, -1, sizeof(mem));

    cout << dp(0, -1, q) << endl;

    return 0;
}
