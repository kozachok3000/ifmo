#include <iostream>
#include <deque>
using namespace std;


struct met{
    int value;
    int index;
};

int main(){
    int m, n = 0;
    cin >> m;
    met input{};
    deque<met> output;
    while((cin >> input.value) && input.value != -1){
        input.index = n++;
        while(!output.empty() && output.front().index < n - m)
            output.pop_front();

        while(!output.empty() && output.back().value < input.value)
            output.pop_back();

        output.push_back(input);

        if (n >= m)
            cout << output.front().value << endl;
    }
    return 0;
}

