#include <iostream> //입출력헤더
#include <vector> //벡터헤더

using namespace std;
//std라이브러리 사용

struct info //구조체 info
{
    int power; //내구도
    bool is_on; //로봇이 있는가 여부
};

vector<info> belt;  //원소를 info로 하는 컨베이어 벨트
int zero_power;     //내구도가 0인 칸의 개수

int minusPosition(int n, int pos) //인덱스 감소
{
    if (--pos >= 0) //pos 값이 0보다 크면
    {
        return pos; //pos값은 하나 줄어서 리턴이됨
    }
    return n * 2 - 1; //아니라면, 2n-1 리턴
}

void second(int n, int start, int end)
{
    int cur = end; //끝을 현재 위치로 저장
    while (cur != start) // 현재 시작점이 아니라면
    {
        cur = minusPosition(n, cur); //인덱스 감소시켜서 현재 위치로 저장
        int next = (cur + 1) % (n * 2); //한칸 다음 위치를 저장
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) //현재 칸에 로봇이 있고, 다음 칸에 로봇이 없, 내구도 0이 아닌값으로 존재하는 경우
        {
            belt[cur].is_on = false; //현재 위치에 있던 로봇을 없애고
            belt[next].power--; //다음 위치의 내구도 1 감소시키고
            if (next != end) // 다음 칸이 내리는 위치가 아니면
            {
                belt[next].is_on = true; //다음 칸에 로봇 옮기기
            }
            if (belt[next].power == 0) //다음 칸이 내구도가 0이면
            {
                zero_power++; //내구도가 0인 칸의 개수 1 증가
            }
        }
    }
}

void third(int start)
{
    if (belt[start].power) //시작점 즉, 올리는 위치의 내구도가 0이 아니면
    {
        belt[start].is_on = true; //현재 올리는 위치에 로봇이 있음
        belt[start].power--; //올리는 위치 내구도 1빼기
        if (belt[start].power == 0) //올리는 위치의 내구도가 0이면
        {
            zero_power++; //내구도가 0인 칸의 개수 1 증가
        }
    }
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 *
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 *
 * 해당 문제는 deque 자료구조를 사용해서도 구현 가능 (1번에서 회전하는 부분만 다르고 2번, 3번은 동일한 로직)
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //시간초과 방지

    int n, k;//정수형 변수 n,k선언

    //입력
    cin >> n >> k; //n,k입력
    belt.assign(n * 2, {0, false}); //벨트 칸은 n*2개, 내구도가 0이고 로봇이 위에 없는걸로 초기화
    for (int i = 0; i < n * 2; i++)
    {
        cin >> belt[i].power; // 내구도 입력받기
    }

    //연산
    int start = 0;    //올리는 위치
    int end = n - 1;  //내리는 위치
    int step = 0;     //단계 수 0으로 세팅
    while (true)
    {
        start = minusPosition(n, start); //올리는 위치 인덱스 감소
        end = minusPosition(n, end); //내리는 위치 인덱스 감소
        if (belt[end].is_on) //로봇이 내리는 위치에 있으면
        {
            belt[end].is_on = false; //내리는 위치에 있던 로봇 없애기
        }
        second(n, start, end); //second 함수 호출
        third(start); //third함수 호출
        step++; //단계 1증가
        if (zero_power >= k) //내구도가 0인 칸의 개수가 k개 이상이면
        {
            break; //종료
        }
    }

    //출력
    cout << step;
    //몇단계를 돌고 끝났는지 출력
    return 0;
}
