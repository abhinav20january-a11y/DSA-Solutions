class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int s=*min_element(nums.begin(),nums.end());
        int m=*max_element(nums.begin(),nums.end());
        for(int i=s;i<=m;i++){
            bool found=false;
            for(int j=0;j<nums.size();j++){
                if(i==nums[j]){
                    found=true;
                    break;


                }

            }
            if(!found){
                ans.push_back(i);
            }
        }
        ans.sort();
        return ans;

        
    }
};
