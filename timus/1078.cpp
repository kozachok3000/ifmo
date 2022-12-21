#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct segment
{
    int x, y, n, depth;
    segment* parent;
    segment(int x, int y, int n, segment* parent) : x(x), y(y), n(n), parent(parent), depth(1) { }
};

bool my_cmp(segment& a, segment& b)
{
    return a.y - a.x > b.y - b.x;
}

int main()
{
    int n, x, y, res;
    vector<segment> line;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        line.push_back(segment(x, y, i, 0));
    }
    sort(line.begin(), line.end(), my_cmp);
    res = 1;
    segment* maxp = &line[0];
    for(int i = 0; i < n; i++)
    {
        int resd = 0;
        for(int j = 0; j < i; j++)
        {
            if(line[i].x > line[j].x && line[i].y < line[j].y)
            {
                if(line[j].depth + 1 > resd)
                {
                    line[i].depth = resd = line[j].depth + 1;
                    line[i].parent = &line[j];
                    if(resd > res)
                    {
                        res = resd;
                        maxp = &line[i];
                    }
                }
            }
        }
    }

    cout << res << endl;
    segment* e = maxp;
    while(e)
    {
        cout << e->n << ' ';
        e = e->parent;
    }
    return 0;
}
