// 2271086 오다민

#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;// 사용자로부터 N과 K를 입력 받기

    // 1~N 숫자를 저장할 벡터 people을 초기화
    std::vector<int> people;
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }

    // 제거된 사람들의 순서를 저장할 벡터 result를 초기화
    std::vector<int> result;
    int index = 0;

    while (!people.empty()) {// people 벡터가 empty가 될 때까지 루프
        index = (index + k - 1) % people.size();
        result.push_back(people[index]);
        people.erase(people.begin() + index);
    }

    std::cout << "<";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {// 마지막 원소가 아닌 경우 ', '를 추가
            std::cout << ", ";
        }
    }
    std::cout << ">\n";

    return 0;
}
