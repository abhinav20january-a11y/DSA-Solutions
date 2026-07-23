class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int original_ones=0;
        for(char ch:s){
            if(ch=='1'){
                original_ones++;
            }

        }
        s="1"+s+"1";
        int max_gain=0;
        int n=s.size();
        for(int i=0;i<n;){
            int left_zero=0;
            if(s[i]=='0'){
            while(i<n && s[i]=='0'){
                left_zero++;
                i++;

            }
             while(i<n && s[i]=='1'){
                i++;

            }
            int j=i;
            int right_zero=0;
             while(j<n && s[j]=='0'){
                right_zero++;
                j++;

            }
            if(right_zero>0){
                max_gain=max(max_gain,left_zero+right_zero);

            }}
            else{
                i++;
            }


        }
        return max_gain+original_ones;
        
    }
};
