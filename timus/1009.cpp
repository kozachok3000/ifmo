#include <iostream>

using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    int a[n+1];
    a[0] = 0;
    a[1] = k - 1;

    for(int i = 2; i <= n; i++)
    a[i] = (k-1)*(a[i-1]+a[i-2]);

    cout << a[n]+a[n-1] << endl;
    return 0;
}
