class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        map<int,vector<int>>mp;
        
        for(auto val:arr)
            m[val]++;
        
        for(auto it=m.begin();it!=m.end();it++){
            mp[it->second].push_back(it->first);
        }
        int count=0;
        int removed_ele=0;
        for(auto it=mp.rbegin();it!=mp.rend();it++){
            
            int temp=it->second.size()*it->first;
            // cout<<temp<<endl;
            if(temp+removed_ele<arr.size()/2){
                removed_ele+=temp;
                count+=it->second.size();
            }
            else{
                int val=ceil(((arr.size()/2)-removed_ele)/(double)it->first);
                count+=val;
                break;
            }
        }
        return count;
    }
};