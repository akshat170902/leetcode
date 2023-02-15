class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        int i=num.size()-1;
        vector<int>ans;
        
        while(i>=0||k||carry){
            int val=(i>=0?num[i]:0)+(carry>0?carry:0)+(k>0?k%10:0);
            k/=10;
            ans.push_back(val%10);
            i--;
            carry=val/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};