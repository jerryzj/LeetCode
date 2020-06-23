#include <iostream>
#include <numeric>
#include <vector>

bool canPartition(std::vector<int> &nums);

int main(void) {
    std::vector<int> nums{1, 2, 3, 4, 5};

    std::cout << canPartition(nums) << std::endl;
    return 0;
}

bool canPartition(std::vector<int> &nums) {
    int sum(std::accumulate(nums.begin(), nums.end(), 0));
    const int target(sum / 2);
    const int n(nums.size());
    std::vector<bool> dp(target + 1);

    // If sum is an odd number, return false
    if ((sum ^ 1) != (sum + 1)) {
        return false;
    }
    // Init vector
    dp.assign(target + 1, false);
    dp[0] = true;

    for (auto i : nums) {
        for (int j = target; j >= i; --j) {
            dp[j] = dp[j] || dp[j - i];
        }
    }
    return dp[target];
}