class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        vector<int>value(n+1,0);
        for(int i=0;i<n;i++){
            value[i+1]=value[i];
            if(grumpy[i]==0){
                value[i+1]+=customers[i];
            }
            // cout<<value[i+1]<<" ";
        }
        // cout<<endl;
        int windowSum=0;
        for(int i=0;i<minutes;i++){
            windowSum+=customers[i];
        }
        int ans=windowSum+(value[n]-value[minutes]);
        // cout<<windowSum<<endl;
        for(int i=minutes;i<n;i++){
            
            windowSum+=customers[i];
            
            
            windowSum-=customers[i-minutes];

            int valueT=(value[n]-value[i+1])+value[i-minutes+1];
            ans=max(ans,windowSum+valueT);
            // cout<<value[n]-value[i+1]<<endl;
            // cout<<valueT<<" "<<windowSum<<endl;
        }
        return ans;
    }
};