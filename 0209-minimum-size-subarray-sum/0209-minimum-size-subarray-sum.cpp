class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0;
        int sum = 0;
        int min_len = n + 1;
        for(high = 0; high < n; high++)
        {
            sum += nums[high];
            while(sum >= target){
                min_len = min(min_len, high - low + 1);
                sum -= nums[low++];
            }
        }
        if(min_len == n + 1) return 0;
        else return min_len;
    }
};