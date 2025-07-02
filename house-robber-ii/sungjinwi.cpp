class Solution {
    public:
        int rob(vector<int>& nums) {
            if (nums.size() == 1)
                return (nums[0]);
            int n = nums.size();
            int curr1 = nums[0];
            int prev1 = 0;
            for (int i = 1; i < n - 1; i++) {
                int tmp = curr1;
                curr1 = max(curr1, prev1 + nums[i]);
                prev1 = tmp;
            }
    
            int curr2 = nums[1];
            int prev2 = 0;
            for (int i = 2; i < n; i++) {
                int tmp = curr2;
                curr2 = max(curr2, prev2 + nums[i]);
                prev2 = tmp;
            }
            return max(curr1, curr2);
        }
    };
