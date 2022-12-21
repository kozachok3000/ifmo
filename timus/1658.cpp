#include <iostream>

using namespace std;

struct state
{
    int x;
    //int y;
    int val;
}a[901][8101];

int main()
{
    int n, x, y, res[1000];
    a[0][0].x = 0;
    a[0][0].val = 0;
    for(int i = 1; i <= 900; i++)
    {
        a[i][0].x = -1;
        a[i][0].val = 10000000;
    }
    for(int i = 1; i <= 8100; i++)
    {
        a[0][i].x = -1;
        a[0][i].val = 10000000;
    }

    for(int i = 1; i <= 900; i++)
        for(int j = 1; j <= 8100; j++)
        {

            a[i][j].val = 10000000;
            a[i][j].x = -1;

            for(int k = 9; k >= 1; k--)
            {
                x = i - k;
                y = j - (k * k);

                if((x >= 0 && y >= 0) && (a[x][y].x != -1) &&(a[x][y].val < a[i][j].val))
                {


                    a[i][j].val = a[x][y].val + 1;
                    a[i][j].x = x;
                }
            }
        }

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;

        if((x <= 900)&&(y <= 8100)&&(a[x][y].x != -1)&&(a[x][y].val <= 100))
        {
            int t, counter = 0;
            while(x != 0)
            {
                t = (x - a[x][y].x);
                res[counter] = t;
                counter++;
                x -= t;
                y -= t*t;
            }
            for(int j = 0; j < counter; j++)
                cout << res[j];
            cout << endl;
        }
        else
            cout << "No solution\n";
    }
    return 0;
}
