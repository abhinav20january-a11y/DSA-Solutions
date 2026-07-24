class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()) * 2;

        vector<bool> pairXor(mx, false);

        // Store all possible XORs of two numbers
        for (int a : nums) {
            for (int b : nums) {
                pairXor[a ^ b] = true;
            }
        }

        vector<bool> ans(mx, false);

        // XOR every pair XOR with every number
        for (int x = 0; x < mx; x++) {
            if (!pairXor[x]) continue;

            for (int c : nums) {
                ans[x ^ c] = true;
            }
        }

        return count(ans.begin(), ans.end(), true);
    }
};
