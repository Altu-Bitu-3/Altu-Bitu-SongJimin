//시작점을 어느 도시로 하는지에 따른 비용계산
//계산된 n개의 비용중 최소비용 선텍

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 10;
int arr[SIZE][SIZE];
vector<bool> visited(SIZE, false);

int findNext(int n, int nextCity, int sum, int cnt, int start) {
    int currentCity = nextCity;
    if (cnt == n - 1) {
        sum += arr[currentCity][start];
        return sum;
    }
    visited[currentCity] = true;
    cnt++;
    int lineMin = 1000000;

    for (int j = 0; j < n; j++) {
        if (!visited[j]) {
            //아직 방문하지 않은 도시면
            if (lineMin > arr[currentCity][j]) {
                lineMin = arr[currentCity][j];
                nextCity = j;
            }
        }
    }
    sum += lineMin;
    findNext(n, nextCity, sum, cnt, start);

}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    //시작 점 마다의 최소비용중 최소를 찾기
    int result = findNext(n, 0, 0, 0, 0);
    for (int start = 1; start < n; start++) {
        visited = {0,0,0,0,0,0,0,0,0,0};
        int temp = findNext(n, start, 0, 0, start);
        if (result > temp) {
            result = temp;
        }
    }

    cout << result;


    return 0;
}