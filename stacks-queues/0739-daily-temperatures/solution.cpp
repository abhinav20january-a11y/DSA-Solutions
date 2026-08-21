class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>arr(n);
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            while(!st.empty() && st.top()<=temperatures[i]){
                st.pop();
                cnt++;
            }
            if(st.empty()){
                arr[i]=0;

            }
            else{
                arr[i]=cnt;
                
            }
            st.push(temperatures[i]);

        }
        return arr;


        
    }
};
