class Solution {
public:
    int findKthPositive(vector<int>& arr, int sum) {
        arr.push_back(1000000);
        int n=arr.size();
        int prev=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            int val=arr[i]-prev-1;
            // cout<<sum<<endl;
            if(val<sum){
                sum-=val;
            }
            else{
                ans=prev+sum;
                break;
            }
            prev=arr[i];
        }
        return ans;
    }
};