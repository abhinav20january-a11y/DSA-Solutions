class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // If there are fewer than 3 elements,
        // only the numbers themselves can be formed.
        if (n < 3) return n;

        // Return the next power of 2 greater than or equal to n.
        int ans = 1;
        while (ans <= n) {
            ans <<= 1;
        }
        return ans;
    }
};
