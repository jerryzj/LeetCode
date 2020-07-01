#include <iostream>
#include <limits>

// By adding the followings, the runtime is reduced from 4ms to 0ms
static auto dividend = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return NULL;
}();

static auto divisor = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return NULL;
}();

int divide(int dividend, int divisor);

int main(void) {
    int ans(divide(-10, 1));

    std::cout << "Ans = " << ans << std::endl;
    return 0;
}

int divide(int dividend, int divisor) {
    // corner case
    if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
        return std::numeric_limits<int>::max();
    }
    // Real Calculation
    uint tmp_dividend(std::abs(dividend));
    uint tmp_divisor(std::abs(divisor));
    uint res(0);
    uint reduce(tmp_divisor);
    uint increment(1);

    while (tmp_dividend >= tmp_divisor) {
        if (reduce > tmp_dividend) {
            reduce = tmp_divisor;
            increment = 1;
        }
        // Record results
        res += increment;
        tmp_dividend -= reduce;
        // Update increment step
        reduce += tmp_divisor;
        ++increment;
    }

    // Get Sign
    const int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    return sign * res;
}
