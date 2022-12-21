#include <iostream>
using namespace std;


int main(){
    int n, i;
    float a0, an1, c, a1, sum = 0;
    cin >> n;
    cin >> a0 >> an1; //a = a0, b = a_(n+1)
    for (i = 0; i < n; ++i){
        cin >> c;
        sum += (n - i) * c;
    }
    a1 = (n * a0 + an1 - sum * 2) / (n + 1);
    printf("%.2f", a1);
    return 0;
}
