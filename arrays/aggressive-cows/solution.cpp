class Solution {
  public:
    bool f(vector<int> &arr, int c,int d){
        int cows=1;
        int last=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last>=d){
                cows++;
                last=arr[i];
            }
            
            
        }
        if(cows>=c){
            return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int low=1;
        int high=arr[n-1]-arr[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(f(arr,k,mid)){
               low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
        
    }
};
