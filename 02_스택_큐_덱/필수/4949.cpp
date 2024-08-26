// 2271086 오다민

#include <iostream>
#include <stack>
#include <string>

int main() {
    while (true) {
        std::string line;
        std::getline(std::cin, line);

        // 입력 종료 조건
        if (line == ".") {
            break;
        }

        // 균형 판단을 위한 stack 선언
        std::stack<char> bracket_stack;
        bool is_balanced = true;

        for (char ch : line) {
            if (ch == '(' || ch == '[') {
                // 왼쪽 괄호 -> 추가
                bracket_stack.push(ch);
            }
            else if (ch == ')' || ch == ']') {
                // 오른쪽 괄호 ->
                if (bracket_stack.empty()) {
                    // 스택이 비어있다면 -> 짝이 맞지 x
                    is_balanced = false;
                    break;
                }

                // 스택의 top과 현재 괄호의 짝이 맞는지 확인
                char top = bracket_stack.top();
                bracket_stack.pop();

                if ((ch == ')' && top != '(') || (ch == ']' && top != '[')) {
                    // 짝이 맞지 않는 경우
                    is_balanced = false;
                    break;
                }
            }
        }

        // 남아있는 왼쪽 괄호가 있다면 -> 균형이 맞지 x
        if (!bracket_stack.empty()) {
            is_balanced = false;
        }

        // 결과 출력
        if (is_balanced) {
            std::cout << "yes\n";
        }
        else {
            std::cout << "no\n";
        }
    }

    return 0;
}
