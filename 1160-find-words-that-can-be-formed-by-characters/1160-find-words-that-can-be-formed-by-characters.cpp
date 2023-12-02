class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
   
        int sum=0;
        for(int i=0;i<words.size();i++){
            sum+=words[i].size();
                 unordered_map<char,int>m,n;
        for(int i=0;i<chars.size();i++){
            m[chars[i]]++;
            
        }
             for(int j=0;j<words[i].size();j++){
if(m.count(words[i][j])<=0){
    sum-=words[i].size();
 
    break;
}
                else{
                  if(m[words[i][j]]==1){
                      m.erase(words[i][j]);
                      
                  }  
                    else{
                        m[words[i][j]]--;
                    }
                }
            }
        }
        return sum;
    }
};