#include <iostream>

using namespace std;

int main()
{
    int n, numb[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cin >> n;
    if(n == 0)
    {
        cout << 10;
    }
    else if(n == 1)
    {
        cout << 1;
    }
    else
    {
    for(int i = 9; i >= 2; i--)
        while(n % i == 0)
        {
            numb[i]++;
            n /= i;
        }
    if(n == 1)
    for(int i = 2; i <= 9; i++)
        for(int j = 0; j < numb[i]; j++)
            cout << i;
    else
        cout << -1;
    }
    return 0;
}
