class Solution {
public:
   static bool compareLength(string &s,string &t){
        return s.size()<t.size();
    }
    bool lcs(string&s,string&t){
        if(s.size()==t.size()-1){
        int i=0;
        while(i<s.size()&&s[i]==t[i]){
            i++;
        }
            if(i==s.size()){
                return true;
            }
            else{
                while(i<s.size()&&s[i]==t[i+1]){
                    i++;
                }
                if(i==s.size())return true;
                else{return false;}
            }
        }
        else{
            return false;
        }
        // vector<int>dp(t.size()+1),pre(t.size()+1);
        // for(int i=0;i<s.size();i++){
        //     for(int j=0;j<t.size();j++){
        //         if(s[i]==t[j]){
        //             dp[j+1]=pre[j]+1;
        //         }
        //         else{
        //             dp[j+1]=max(pre[j+1],dp[j]);
        //         }
        //     }
        //     pre=dp;
        // }
        // return t.size()+s.size()-2*dp[t.size()]==1;
    }
    int longestStrChain(vector<string>& words) {
        sort(begin(words),end(words),compareLength);
        vector<int>dp(words.size()+1),prev(words.size()+1);
        for(int cur=words.size()-1;cur>=0;cur--){
            // cout<<words[cur]<<endl;
            for(int pre=cur;pre>=-1;pre--){
               int take=0;
                if(pre==-1||(words[cur].size()>words[pre].size()&&lcs(words[pre],words[cur]))){
                    // cout<<words[cur]<<" "<<pre<<endl;
                    take=prev[cur+1]+1;
                    // cout<<take<<endl;
                }
               int notTake=prev[pre+1];
                dp[pre+1]=max(notTake,take);
                // cout<<dp[pre+1]<<" ";
                if(dp[pre+1]==16)return 16;
            }
            // cout<<endl;
            prev=dp;
        }
        return dp[0];
    }
};