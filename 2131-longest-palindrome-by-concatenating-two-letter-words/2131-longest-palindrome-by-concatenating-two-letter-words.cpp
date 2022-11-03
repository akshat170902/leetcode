class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        bool odd=false;
        
        unordered_map<string,int>m;
        for(string&word:words){
            m[word]++;
        }
        
        for(int i=0;i<words.size();i++){
            string rev="";
            rev+=words[i][1];
            rev+=words[i][0];
            // cout<<rev<<endl;
            // cout<<words[i]<<" "<<rev<<endl;
            if(rev!=words[i]){
                if(m.count(rev)){
                    // cout<<m[words[i]]<<" "<<m[rev]<<endl;
                    ans+=(min(1,(min(m[rev],m[words[i]])))*4);
                    m[rev]>0?m[rev]--:true;
                    m[words[i]]>0?m[words[i]]--:true;
                    // cout<<ans<<endl;
                }
            }
            else{
                // cout<<m[rev]<<endl;
                ans+=(m[rev]/2)*4;
                m[rev]%=2;
                if(m[rev]==1){
                    odd=true;
                }
                // cout<<ans<<endl;
            }
        }
        
        odd?ans+=2:true;
        
        return ans ;
    }
};