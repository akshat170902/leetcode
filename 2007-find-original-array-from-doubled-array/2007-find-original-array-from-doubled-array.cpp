class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>m;
        int n=changed.size();
        vector<int>ans;
        
        for(int val:changed){
            m[val]++;
            // if(val!=0)
            //     m[val*2]--;
        }
//         for(auto it:m){
//             if((it.first==0&&it.second%2!=0)){
//                 return {};
//             }
//             if(it.second!=0){
//                 if(it.second>0){
//                     ans.push_back(it.first);
//                 }
                
//             }
//         }
        for(auto &it:m){
            if(it.second!=0){
                if((!it.first&&it.second%2)||!m.count(it.first*2)||m[it.first*2]<it.second){
                    return {};
                }
                
                while(it.second--){
                    ans.push_back(it.first);
                    m[it.first*2]--;
                }
            }
        }
        return ans;
    }
};