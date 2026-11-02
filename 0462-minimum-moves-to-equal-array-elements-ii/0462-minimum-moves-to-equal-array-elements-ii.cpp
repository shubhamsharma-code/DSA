class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());

        int median = nums[nums.size() / 2];
        long long moves = 0;

        for (int num : nums) {
            moves += llabs((long long)num - median);
        }

        return (int)moves;
    }
};