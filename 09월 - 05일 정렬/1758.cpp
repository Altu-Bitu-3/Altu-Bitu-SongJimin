#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long int result = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //팁을 최대로 받으려면, 큰 숫자가 앞에와서 감소되는 값을 줄여야함 >> 내림차순

    sort(arr.begin(), arr.end(), greater<>());

    for (int i = 0; i < n; i++) {
        if (arr[i] - (i + 1 - 1) > 0)
            result += arr[i] - (i + 1 - 1);
    }
    cout << result;

    return 0;
}
