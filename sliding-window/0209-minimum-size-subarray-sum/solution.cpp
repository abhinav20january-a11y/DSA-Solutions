class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        int minl=INT_MAX;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                 minl=min(minl,r-l+1);
                 sum-=nums[l];
                 l++;
            }
          
            r++;


        }
        return minl;
        

        
    }
};
