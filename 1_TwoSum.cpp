class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int remainder = target - nums[i];
            if (map.find(remainder) != map.end()) {
                ans.push_back(map[remainder]);
                ans.push_back(i);
                return ans;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};
