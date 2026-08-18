class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>ar(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ar[i]=-1;
                
            }
            else{
            ar[i] = st.top();
            
            }
            st.push(arr[i]);
        }
        return ar;
    }
};
