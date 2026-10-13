class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr; // {value, original index}

        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());

        int low = 0, high = n - 1;
        while(low < high)
        {
            int sum = arr[low].first + arr[high].first;
            if(sum == target)
            {
                return {arr[low].second, arr[high].second};
            }
            else if(sum < target)
            {
                low++;
            }
            else if(sum > target){
                high--;
            }
        }
        return {-1, -1};
    }
};