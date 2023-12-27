class Solution {
public:
    int minCost(string colors, vector<int>& T) {
        int ans=0;
        for(int i=0;i<colors.size();){
            if(colors[i]==colors[i+1]){
                char ch=colors[i];
                int sum=0;
                int maximum=0;
                
                while(colors[i]==ch){
                    sum+=T[i];
                    maximum=max(maximum,T[i]);
                    
                    i++;
                }
                ans+=(sum-maximum);
            }
            else{
                i++;
            }
        }
        return ans;
    }
};