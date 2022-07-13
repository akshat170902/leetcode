class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>m;
        for(int i=0;i<time.size();i++){
            m[time[i]%60]++;
        }
       long long int ans=0;
        for(int i=1;i<30;i++){
            ans+=m[i]*m[60-i];
        }
        if(m[0]%2){
            ans+=m[0]*((m[0]-1)/2);
        }
        else{
            ans+=((m[0]/2)*(m[0]-1));
        }
        if(m[30]%2){
            ans+=m[30]*((m[30]-1)/2);
        }
        else{
            ans+=((m[30]/2)*(m[30]-1));
        }
        
        return ans;
    }
};