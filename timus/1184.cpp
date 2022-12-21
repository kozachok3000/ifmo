#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    float t;
    for (int i = 0; i < n ; i++)
    {
        cin >> t;
        a[i] = int(t * 100);
    }
    int l = 0, r = 100000000, mid, counter, res;
    while (l <= r)
    {
        mid = (l + r)/2;
        if(mid == 0)
        {
            res = 0;
            break;
        }
        else
        {
            counter = 0;
            for(int i = 0; i < n; i++)
            {
                counter += a[i]/mid;
            }
            if (counter >= k)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    printf("%d.%02d", res/100, res%100);
    //cout << res/100 << '.' << res%100;
    return 0;
}
