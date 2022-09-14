#include <iostream>
#include <queue>
#include <vector>
//하나씩 검사하면서 뒤로 보내기, k번째는 pop (empty체크)

using namespace std;

void JosephusPermutation(int n, int k, queue<int> &q, vector<int> &v) {
    for (int i = 0; i < n; i++) {
        if (!q.empty()) {
            for (int j = 1; j < k; j++) {
                q.push(q.front());
                q.pop();
            }
            v[i] = q.front();
            q.pop();
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    vector<int> arr(n, 0);

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    JosephusPermutation(n, k, q, arr);

    cout << "<" << arr[0];
    for (int i = 1; i < n; i++) {
        cout << ", " << arr[i];
    }
    cout << ">" << "\n";

    return 0;
}