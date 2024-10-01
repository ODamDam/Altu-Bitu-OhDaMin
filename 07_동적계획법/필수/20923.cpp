#include <iostream>
#include <deque>

using namespace std;

// 게임 진행 함수
string playGame(int cardCount, int rounds, deque<int> &dodoDeck, deque<int> &suyeonDeck) {
    deque<int> dodoGround; // 도도의 그라운드 카드더미
    deque<int> suyeonGround; // 수연의 그라운드 카드더미

    bool isDodoTurn = true; // true는 도도의 차례, false는 수연의 차례
    int currentRound = 0; // 게임 진행 횟수
    string winner; // 이긴 사람

    while (true) {
        currentRound++; // 게임 진행 횟수 증가

        // 차례인 사람이 카드 내려놓기
        if (isDodoTurn) { // 도도의 차례
            dodoGround.push_back(dodoDeck.back()); // 도도가 카드 내려놓기
            dodoDeck.pop_back();
        } else { // 수연의 차례
            suyeonGround.push_back(suyeonDeck.back()); // 수연이가 카드 내려놓기
            suyeonDeck.pop_back();
        }

        // 0개 됐는지 체크
        if (dodoDeck.empty()) { // 도도의 카드 수가 0이면
            winner = "su";
            break;
        } else if (suyeonDeck.empty()) { // 수연이의 카드 수가 0이면
            winner = "do";
            break;
        }

        // 수연이가 종치기
        if (!dodoGround.empty() && !suyeonGround.empty() && 
            (dodoGround.back() + suyeonGround.back() == 5)) {
            // 도도의 그라운드의 카드더미를 수연이의 덱 밑에 합치기
            while (!dodoGround.empty()) {
                suyeonDeck.push_front(dodoGround.front());
                dodoGround.pop_front();
            }
            // 수연의 그라운드의 카드더미를 수연이의 덱 밑에 합치기
            while (!suyeonGround.empty()) {
                suyeonDeck.push_front(suyeonGround.front());
                suyeonGround.pop_front();
            }
        } 
        // 도도가 종치기
        else if ((!dodoGround.empty() && dodoGround.back() == 5) || 
                 (!suyeonGround.empty() && suyeonGround.back() == 5)) {
            // 수연의 그라운드의 카드더미를 도도의 덱 밑에 합치기
            while (!suyeonGround.empty()) {
                dodoDeck.push_front(suyeonGround.front());
                suyeonGround.pop_front();
            }
            // 도도의 그라운드의 카드더미를 도도의 덱 밑에 합치기
            while (!dodoGround.empty()) {
                dodoDeck.push_front(dodoGround.front());
                dodoGround.pop_front();
            }
        }

        // M번 진행한 후
        if (currentRound == rounds) {
            int dodoCardCount = dodoDeck.size();
            int suyeonCardCount = suyeonDeck.size();
            if (dodoCardCount < suyeonCardCount) {
                winner = "su";
            } else if (dodoCardCount > suyeonCardCount) {
                winner = "do";
            } else {
                winner = "dosu";
            }
            break;
        }

        isDodoTurn = !isDodoTurn; // 차례를 바꾼다.
    }

    return winner; // 게임의 승자를 return
}

int main() {
    int n, m; // n: 카드 수, m: 게임 진행 횟수
    cin >> n >> m;

    deque<int> dodoDeck(n); // 도도의 카드 덱
    deque<int> suyeonDeck(n); // 수연의 카드 덱

    for (int i = 0; i < n; i++) {
        cin >> dodoDeck[i] >> suyeonDeck[i];
    }

    string gameWinner = playGame(n, m, dodoDeck, suyeonDeck); // 게임 진행
    cout << gameWinner; // 승자 출력

    return 0;
}
