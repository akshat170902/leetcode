class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int arr[1001]={0};
        int sor[1001]={0};
        vector<int>ans(arr1.size(),0);
        for(int i=0;i<arr1.size();i++){
            arr[arr1[i]]++;
        }
        int j=0;
        for(int i=0;i<arr2.size();i++){
            sor[arr2[i]]++;
            while(arr[arr2[i]]>0){
                cout<<i<<" "<<j<<endl;
                ans[j]=arr2[i];
                j++;
                arr[arr2[i]]--;
            }
        }
        for(int i=0;i<1001;i++){
            while(arr[i]>0){
                cout<<i<<endl;
                ans[j]=i;
                j++;
                arr[i]--;
            }
        }
        return ans;
    }
};