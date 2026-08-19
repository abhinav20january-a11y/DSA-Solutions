class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=(int)(1e9+7);
        int mini=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                sum+=mini%mod;
                

            }
        }
        return sum;
        
    }
};
