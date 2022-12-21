#include <iostream>
#include <algorithm>


using namespace std;

struct city
{
    int value;
    int number;
};

bool my_cmp(city a, city b)
{
    return (a.value < b.value) || (a.value == b.value && a.number < b.number);
}


int main()
{
    int n;
    scanf("%d", &n);
    city cities[70001];
    for(int i = 0; i < n; i++)
    {
        cities[i].number = i + 1;
        scanf("%d", &cities[i].value);
    }
    sort(cities, cities+n, my_cmp);

/*
    for(int i = 0; i < n; i++)
    {
        cout << cities[i].number << ' ' << cities[i].value << endl;
    }
*/

    int m, val, first, last;
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &first, &last, &val);

        int left = 0, right = n - 1, mid, flag = 0;
        while((right >= left))
        {
            mid = (right + left) / 2;
            //cout << mid << endl;
            if((cities[mid].value == val)&&(cities[mid].number <= last)&&(cities[mid].number >= first))
            {
                flag = 1;
                break;
            }else if((cities[mid].value > val)||(cities[mid].value == val && cities[mid].number > last))
            {
                right = mid - 1;
            }
            else if((cities[mid].value < val)||(cities[mid].value == val && cities[mid].number < first))
            {
                left = mid + 1;
            }
        }
        //cout << cities[mid].number << ' ' << cities[mid].value << endl;
        cout << flag;

    }

    return 0;
}
