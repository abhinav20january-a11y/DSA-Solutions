class Solution {
	public:
	int longestSubarray(vector<int>& arr, int k) {
	    map<int,int>mp;
	    int maxlen=0;
	    int sum=0;
	    for(int i=0;i<arr.size();i++){
	        sum+=arr[i];
	        if(sum==k){
	            maxlen=max(maxlen,i+1);
	        }
	        int need=sum-k;
	        if(mp.count(need)){
	            int len=i-mp[need];
	            maxlen=max(maxlen,len);
	        }
	       if(!mp.count(sum)){
	           mp[sum]=i;
	           
	       }
	        
	    }
	    return maxlen;
	    
	    
	    
		
	}
};
