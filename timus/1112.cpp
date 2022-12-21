#include <iostream>
#include <algorithm>

using namespace std;

struct line
{
    int a;
    int b;
};
bool my_cmp(line a, line b)
{
    if (a.a < b.a)
        return 1;
    else if (a.a > b.a)
        return 0;
    else if(a.b < b.b)
        return 1;
    return 0;
}

int main()
{
    int n, t;
    cin >> n;
    line lines[n];
    for(int i = 0; i < n; i++)
    {
        cin >> lines[i].a >> lines[i].b;
        if(lines[i].a > lines[i].b)
        {
            swap(lines[i].a, lines[i].b);
        }
    }
    sort(lines, lines+n, my_cmp);
    /*
    for(int i = 0; i < n; i++)
    {
        cout << lines[i].a << ' ' << lines[i].b << endl;
    }
    */

    int dp[n];
    int prev[n];
    for(int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        prev[i] = -1;
    }

    int maximum = -1, res = -1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i - 1; j >= 0; --j)
        {
            if(lines[j].b <= lines[i].a)
            {
                if(dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
        if(maximum < dp[i])
        {
            maximum = dp[i];
            res = i;
        }
    }
    cout<<maximum<<'\n';
    line result[n];
    int j = 0;
    while(res != -1)
    {
        result[j].a = lines[res].a;
        result[j].b = lines[res].b;
        j++;
        res = prev[res];
    }
    for(int i = j - 1; i >= 0; --i)
    {
        cout<<result[i].a<<' '<<result[i].b<<'\n';
    }
    return 0;
}
