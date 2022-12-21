#include <iostream>
#include <algorithm>

using namespace std;

struct line
{
    int l;
    int r;
};

line lines[100001];

bool my_cmp(int a,int b)
{
    return (lines[a].l < lines[b].l) || (lines[a].l == lines[b].l && lines[a].r < lines[b].r);
}

int main()
{

    int n = 0, m;
    int optR[5001];
    int idx[5001];
    int dp[5001];
    int trace[5001];
    for(int i = 0; i <= 5000; ++i)
    {
        optR[i] = 100000;
        idx[i] = trace[i] = -1;
    }
    cin >> m;

    while(cin >> lines[n].l >> lines[n].r)
    {
        if(lines[n].l == 0 && lines[n].r == 0)
        {
            break;
        }
        if(lines[n].r >= 0)
        {
            int r = min(lines[n].r, m);
            int l = max(lines[n].l, 0);
            if(optR[r] > l)
            {
                optR[r] = l;
                idx[r] = n;
            }
        }
        ++n;
    }

    for(int i = 0; i <= 5000; ++i)
    {
        dp[i] = 100000;
    }
    for(int i = 0; i <= 5000; ++i)
    {
        if(optR[i] == 0)
        {
            dp[i] = 1;
        }
    }
    for(int i = 0; i <= 5000; ++i)
    {
        if(optR[i] == 100000)
        {
            continue;
        }
        for(int j = i; j >= optR[i]; --j)
        {
            if(dp[i] > dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
    }
    if(dp[m] == 100000)
    {
        cout << "No solution" << endl;
    }
    else
    {
        cout << dp[m] << endl;
        int ord[dp[m]];
        int j = 0;
        while(1)
        {
            ord[j++] = idx[m];
            m = trace[m];
            if(m < 0)
                break;
        }
        sort(ord, ord + j, my_cmp);
        for(int i = 0; i < j; ++i)
        {
            cout << lines[ord[i]].l << ' ' << lines[ord[i]].r << endl;
        }
    }
    return 0;
}
