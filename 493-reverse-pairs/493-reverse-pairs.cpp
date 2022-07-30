class Solution {
public:
    long long merge(vector<int>& arr,int n,int low,int mid,int high,vector<int>& temp){
        int inv=0;
        int i=low;
        int j=mid+1;
        int k=low;
        while(i<=mid&&j<=high){
            long long int temp1=2*(long long)arr[j],temp2=arr[i];
            if(temp2<=temp1){
                i++;
            }
            else{
                inv+=(mid-i+1);
                j++;

            }
        }
        i=low;
        j=mid+1;
        k=low;
        while(i<=mid&&j<=high){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            else{
                
                temp[k++]=arr[j++];

            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=high){
            temp[k++]=arr[j++];
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i];
        }
        return inv;
    }
    long long mergeSort(vector<int>& arr,int n,int low,int high,vector<int>& temp){
        long long inv=0;
        if(low<high){
            int mid=low+(high-low)/2;
            inv+=mergeSort(arr,n,low,mid,temp);
            inv+=mergeSort(arr,n,mid+1,high,temp);
            inv+=merge(arr,n,low,mid,high,temp);
        }
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);
        return mergeSort(nums,n,0,n-1,temp);
    }
};