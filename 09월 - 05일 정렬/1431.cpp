#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int numSum(string str) {
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) >= 48 && str.at(i) <= 57) {
            sum += str.at(i) - 48;
        }
    }
    return sum;
}

bool cmp(const string &a, const string &b) {
    if (a.length() != b.length())
        return a.length() < b.length();
    if (numSum(a) != numSum(b))
        return numSum(a) < numSum(b);

    for (int i = 0; i < a.length(); i++) {
        if (a.at(i) != b.at(i)) {
            return a.at(i) < b.at(i);
        }
    }

}


int main() {

    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }
    return 0;
}
