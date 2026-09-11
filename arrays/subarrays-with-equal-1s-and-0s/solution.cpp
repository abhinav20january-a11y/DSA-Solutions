class Solution {
  public:
    int countSubarray(vector<int>& arr) {
        map<int,int>mp;
        int sum=0;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                sum--;
                
                
            }
            else{
                sum++;
            }
            if(sum==0){
                cnt++;
            }
            if(mp.count(sum)){
                cnt+=mp[sum];
            }
            mp[sum]++;
        }
        return cnt;
        
        
        
          
        
        
    }
};
