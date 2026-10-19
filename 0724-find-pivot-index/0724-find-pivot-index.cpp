class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefixSum[i] += sum;
        }
        //{1, 8, 11, 17, 22, 28}
        int leftSum = 0;
        int rightSum = 0;
        for(int i = 0; i < n; i++){
            if(i==0){
                rightSum = prefixSum[n-1] - prefixSum[0];
                leftSum = 0;
                if(leftSum == rightSum) return i;
            }
            else if(i < n-1 && i > 0){
                leftSum = prefixSum[i-1];
                rightSum = prefixSum[n-1] - prefixSum[i];
                if(leftSum == rightSum) return i;
            }
            else{
                leftSum = prefixSum[n-2];
                rightSum = 0;
                if(leftSum == rightSum) return i;
            }
        }
        return -1;
    }
};