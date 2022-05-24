class Solution {
public:
    int numTeams(vector<int>& r ) {
        int sum=0;
        for(int i=1;i<r.size()-1;i++){
            int lb=0,hb=0;
            int la=0,ha=0;

            for(int j=0;j<i;j++){
                if(r[j]<r[i]){
                    lb++;
                }
                if(r[i]<r[j]){
                    hb++;
                }
            }
            for(int j=i+1;j<r.size();j++){
                 if(r[j]<r[i]){
                    la++;
                }
                if(r[i]<r[j]){
                    ha++;
                }
            }
            // cout<<min(lb,ha)<<" "<<min(la,hb)<<endl;
            sum+=lb*ha+la*hb;
        }
        return sum;
    }
};