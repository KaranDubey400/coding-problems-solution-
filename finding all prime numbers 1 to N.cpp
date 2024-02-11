#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    int num = 2;
    while (num <= N) {
        bool is_prime = true;
        int divisor = 2;
        while (divisor < num) {
            if (num % divisor == 0) {
                is_prime = false;
                break;
            }
            divisor++;
        }
        if (is_prime) {
            cout << num << " ";
        }
        num++;
    }
    return 0;
}
