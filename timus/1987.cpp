#include <iostream>
#include <stack>

using namespace std;

struct segment
{
    int l, r, index;
};

int main()
{
    int n;
    cin >> n;
    segment a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].index = i + 1;
    }
    int m;
    cin >> m;
    int counter = 0;
    stack<segment> s;
    for(int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        while(counter < n && a[counter].l <= c)
        {
            s.push(a[counter]);
            counter++;
        }
        while(!s.empty() && s.top().r < c)
        {
            s.pop();
        }
        if(s.empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            segment t = s.top();
            if (c >= t.l && c <= t.r)
            {
                cout << t.index << endl;
            }
            else
                cout << -1 << endl;
        }
    }
    return 0;
}
