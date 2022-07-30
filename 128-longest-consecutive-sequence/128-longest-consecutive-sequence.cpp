class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_map<int,bool>m;
        for(int i=0;i<n;i++)m[nums[i]]=true;
        for(int i=0;i<n;i++)m[nums[i]]=m.count(nums[i]-1)?false:true;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second){
                int temp=it->first;
                int size=0;
                while(m.count(temp)){
                    temp++;
                    size++;
                }
                ans=max(ans,size);
            }
        }
        return ans;
    }
};