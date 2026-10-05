class Solution {
  public:
    int countOnes(vector<int>& arr) {
       int low=0;
       int n=arr.size();
       int high=n-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(arr[mid]==1){
               low=mid+1;
           }
           else if (arr[mid]<1){
               high=mid-1;
           }
           
       }
       return high+1;
        
    }
};
