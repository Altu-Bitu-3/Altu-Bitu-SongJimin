#include <iostream>
#include <cmath>

using namespace std;

//R+B는 m*n이다. 가능한 m,n조합 구하기.
int main() {
    int r, b, l, w;
    cin >> r >> b;

    int size = r + b; //최대 2,005,000

    for (int i = 3; i <= sqrt(size); i++) {
        //갈색은 항상 1개 이상, 빨강은 항상 8개 이상이므로 각 l,w가 3이상 이어야한다.
        if (size % i == 0) {
            l = max(i, size / i);
            w = min(i, size / i);
            if (r + 4 == (w + l) * 2){
                cout << l << ' ' << w;
                break;
            }
        }

    }

    return 0;
}
