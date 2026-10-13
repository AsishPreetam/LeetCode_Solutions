class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int x = nums[i];

            int a = curMax * x;
            int b = curMin * x;

            curMax = max({x, a, b});
            curMin = min({x, a, b});

            result = max(result, curMax);
        }
        return result;
    }
};