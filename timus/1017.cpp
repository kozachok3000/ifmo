#include <iostream>
#include <cstring>

using namespace std;

long long mem[501][501];

long long dp(int x, int y)
{
    if(x==0)
        return 1;
    if(y==0)
        return 0;

    if(mem[x][y] == -1)
    {
        long long t = 0;
        if(x >= y)
            t = dp(x-y, y-1);
        mem[x][y] = t + dp(x, y-1);
    }
    return mem[x][y];
}


int main()
{
    int n;
    memset(mem,-1,sizeof(mem));
    cin >> n;


    cout << dp(n, n-1) << endl;
    return 0;
}
