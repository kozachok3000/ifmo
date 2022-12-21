#include <iostream>


using namespace std;

int main()
{
    int pows[245], n, j;
    for(int i = 0; i <= 245; i++)
    {
        pows[i] = i*i;
    }
    cin >> n;
    int a[n+1];
    for(int i = 0; i <= n; i++)
    {
        a[i] = i;
        j = 2;
        while(pows[j] <= i)
        {
            a[i] = min(a[i], a[i-pows[j]]+1);
            j++;
        }
    }
    cout << a[n] << endl;
    return 0;
}
