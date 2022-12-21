#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int dp[n], arr[m];
    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 2;
    for(int i = 1; i < n; i++)
    {
        dp[i] = 2;
        for(int j = 0; j < m; j++)
        {
            if(i - arr[j] >= 0 && dp[i - arr[j]] == 2)
                dp[i] = 1;
        }
    }
    cout << dp[n-1];
    return 0;
}
