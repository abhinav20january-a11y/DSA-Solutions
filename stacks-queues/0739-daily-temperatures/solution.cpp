class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>arr(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                arr[i]=0;


            }
            else{
                arr[i]=st.top()-i;
                
            }
            st.push(i);

        }
        return arr;


        
    }
};
