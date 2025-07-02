class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> ans(n + 1);
    
            ans[0] = 0;
            if (n == 0)
                return ans;
    
            ans[1] = 1;
            int msb = 2;
            for (int i = 2; i < n + 1; i++) {
                if (i == 2 * msb) {
                    msb *= 2;
                }
                ans[i] = 1 + ans[i - msb];
            }
            return ans;
        }
    };
