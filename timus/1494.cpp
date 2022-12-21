#include <iostream>
#include <deque>

using namespace std;



int main() {

    int n, value, a = 1, flag = 0;
    deque<int> q;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> value;
        while(a <= value) {
            q.push_back(a);
            ++a;
        }


        if (q.back() != value) flag = 1;
        else q.pop_back();
    }

    if (flag) cout << "Cheater";
    else cout << "Not a proof";
    return 0;
}


