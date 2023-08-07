class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),low=0,high=n-1;
        while(low<high){
            int mid=low+(high-low+1)/2;
            if(matrix[mid][0]==target){
                return true;
            }
            else if(matrix[mid][0]<target){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        int idx=high;
        low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[idx][mid]==target){
                return true;
            }
            else if(matrix[idx][mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};