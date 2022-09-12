class Solution {
public:
    // int bag(vector<int>& tokens, int power,int score,int idx,int j,vector<vector<int>>&dp) {
    //     int n=tokens.size();
    //     if(idx>j){
    //         return 0;
    //     }
    //     if(dp[idx][j]!=-1){
    //         return dp[idx][j];
    //     }
    //     int take=0,notTake=0;
    //     if(tokens[idx]<=power){
    //         take=bag(tokens,power-tokens[idx],score+1,idx+1,j,dp)+1;
    //     }
    //     if(score>=1){
    //         notTake=bag(tokens,power+tokens[j],score-1,idx,j-1,dp)-1;
    //     }
    //     return dp[idx][j]=max(take,notTake);
    // }
    int bagOfTokensScore(vector<int>& tokens, int power,int score=0) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int low=0,high=n-1;
        int ans=0;
        while(low<=high){
            if(power>=tokens[low]){
                power-=tokens[low++];
                score++;
            }
            else if(score>=1){
                power+=tokens[high--];
                score--;
            }
            else{
                break;
            }
            ans=max(ans,score);
        }
        ans=max(ans,score);
        return ans;
    }
};