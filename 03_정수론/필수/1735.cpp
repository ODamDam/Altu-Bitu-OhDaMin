// C++17
#include <iostream>
using namespace std;

// Use Uclidean reciprocal method -> GCD
int GCD(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Find the sum of the two fractions -> convert them to the reduced fractions
pair<int, int> AddAndSimplify(int A, int B, int C, int D) {
    int num = A * D + C * B;
    int den = B * D;
    int g = GCD(num, den);   // Calc
    return { num / g, den / g }; // convert
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D; // input
    auto [num, den] = AddAndSimplify(A, B, C, D); // convert
    cout << num << " " << den; // output
    return 0;
}
