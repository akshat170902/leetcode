class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        int left=0;
        unordered_map<int,int>m;
        for(int i=0;i<fruits.size();i++){
            m[fruits[i]]++;
            if(m.size()>2){
                while(m.size()>2){
                    m[fruits[left]]--;
                    if(m[fruits[left]]==0){
                        m.erase(fruits[left]);
                    }
                    left++;
                }
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};