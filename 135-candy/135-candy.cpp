class Solution {
public:
    int candy(vector<int>& rating) {
        
        int n=rating.size();
        vector<int>val(n,1),value(n,1);
        
        int cur=1,least=INT_MAX;
        for(int i=0;i<n;i++){
            if(rating[i]<least){
                least=rating[i];
                cur=i;
            }
        }
        int left=n-2,right=1;
        // cout<<left<<endl;
        while(left>=0){
            if(rating[left]>rating[left+1]){
                val[left]=val[left+1]+1;
            }
            else{
                val[left]=1;
            }
            left--;
        }
        while(right<n){
            if(rating[right]>rating[right-1]){
                value[right]=value[right-1]+1;
            }
            else{
                value[right]=1;
            }
            right++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(value[i],val[i]);
        }
        return ans;
    }
};