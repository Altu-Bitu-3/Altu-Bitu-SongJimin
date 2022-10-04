#include <iostream>
#include <deque>


using namespace std;

int n, m;
string final_winner;
deque<int> dodo, suyeon, do_ground, su_ground;

char isWinner() {
    //수연이는 합이 5일때, 도도는 한 카드가 5일때
    if (do_ground.front() == 5) return 'd';
    if (su_ground.front() == 5) return 'd';
    if (do_ground.size() && su_ground.size() && dodo.front() + suyeon.front() == 5) return 's';
    return 0;
}

string playGame() {
    for (int i = 0; i < m; i++) {
        //0,짝수번은 도도차례, 홀수번은 수연이 차례
        if (i % 2 == 0) {
            do_ground.push_front(dodo.front());
            dodo.pop_front();
            if (dodo.empty()) {
                //도도 카드가 0장 되면 패 (수연 승)
                final_winner = "su";
                return final_winner;
            }
        } else if (i % 2 == 1) {
            su_ground.push_front(suyeon.front());
            suyeon.pop_front();
            if (suyeon.empty()) {
                //도도 카드가 0장 되면 패 (수연 승)
                final_winner = "do";
                return final_winner;
            }
        }
        char winner = isWinner();
        //이긴 사람은 상대방 그라운드 카드를 먼저 뒤집어합치고, 자기 그라운드 뒤집어카드를 합친다.
        if (winner == 'd') {
            while (!su_ground.empty()) {
                //수연이 그라운드 카드가 남을떄까지 뒤에서부터 빼서 뒤로 넣기
                dodo.push_back(su_ground.back());
                su_ground.pop_back();
            }
            while (!do_ground.empty()) {
                //본인 그라운드 카드 넣기
                dodo.push_back(do_ground.back());
                do_ground.pop_back();
            }

        } else if (winner == 's') {
            while (!do_ground.empty()) {
                suyeon.push_back(do_ground.back());
                do_ground.pop_back();
            }
            while (!do_ground.empty()) {
                //본인 그라운드 카드 넣기
                suyeon.push_back(su_ground.back());
                su_ground.pop_back();
            }

        }

    }
    //m번 시행뒤 최종 승자 결정
    if (dodo.size() > suyeon.size()) {
        final_winner = "do";
    } else if (dodo.size() < suyeon.size()) {
        final_winner = "su";
    } else {
        final_winner = "dosu";
    }
    return final_winner;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        //맨 처음 들어오는 숫자가 덱의 맨 아래로 가도록 입력값 앞으로 집어넣기
        dodo.push_front(a);
        suyeon.push_front(b);
    }
    cout<< playGame();

    return 0;
}

