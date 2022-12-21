#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n;

    long long tree[n+1][2];
    tree[0][0] = 0;
    tree[0][1] = 0;

    vector<int> div[n+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j*i <= n; j++)
            div[j*i].push_back(i);


    for(int i = 1; i <= n; i++)
    {
        cin >> tree[i][0];
        tree[i][1] = 0;
    }
    cin >> q;
    for(int e = 0; e < q; e++)
    {
        int opt;
        cin >> opt;
        if(opt == 1)
        {
            int i;
            long long ans;
            cin >> i;
            ans = tree[i][0];
            for(auto d : div[i])
            {
                int t = d;
                while(t > 0)
                {
                    ans += tree[t][1];
                    t -= t & -t;
                }
            }
            cout << ans << endl;
        }
        else
        {
            int l, r, d;
            cin >> l >> r >> d;
            while (l <= n)
            {
                tree[l][1] += d;
                l += l & -l;
            }
            r++;
            while (r <= n)
            {
                tree[r][1] -= d;
                r += r & -r;
            }

        }
    }
    return 0;
}
