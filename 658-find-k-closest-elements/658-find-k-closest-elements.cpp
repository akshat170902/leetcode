class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            arr[i]=arr[i]-x;
            
        }
        sort(arr.begin(),arr.end(),[](int a,int b){
            if(abs(a)==abs(b))
                return a<b;
            
            return abs(a)<abs(b);
                
            
        });
        for(int i=0;i<k;i++){
            ans.push_back(arr[i]+x);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};