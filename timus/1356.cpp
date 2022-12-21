#include <iostream>

using namespace std;

bool prime(int a)
{
    for (int i = 2; i*i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        if(prime(n))
        {
            cout << n << endl;
        }
        else if(prime(n-2))
        {
            cout << 2 << " " << n-2 << endl;
        }
        else
        {
            if(n % 2)
            {
                cout << 3 << " ";
                n -= 3;
            }
            int k = 3;
            while(!(prime(k) && prime(n-k)))
                k+= 2;
            cout << k << " " << n-k << endl;
        }
    }
    return 0;
}
