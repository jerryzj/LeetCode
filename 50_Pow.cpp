#include <iostream>

double myPow(double x, int n);
inline double compute(double x, int n);

int main() {
    double x(2);
    int n(-3);

    std::cout << "Ans: " << myPow(x, n) << std::endl;
    return 0;
}

double myPow(double x, int n) {
    double ans = compute(x, abs(n));

    if (n < 0) {
        return 1.0 / ans;
    } else {
        return ans;
    }
}

inline double compute(double x, int n) {
    double ans(1.0);
    while (n != 0) {
        // Reduce number of multiply by reduce n exponentially
        if (n % 2 != 0) {
            ans *= x;
        }
        x = x * x;
        n /= 2;
    }
    return ans;
}