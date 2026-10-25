class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=st.top()){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
                st.push(arr[i]);
            }
            else{
                ans.push_back(st.top());
                st.push(arr[i]);
            }
        }
        return ans;
        
        
    }
};
