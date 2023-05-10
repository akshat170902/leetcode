class Solution {
public:
    void spiral(vector<vector<int>>&arr,int n){
         int max_r=n-1,max_c=n-1;
        int min_r=0,min_c=0;
        int i=0,j=0;
        int cur=2;
        bool var=true;
        bool dir=true;
        arr[0][0]=1;
        while (min_r<=max_r||min_c<=max_c){
            if(var){
                if(dir){
                    j++;
                    for(  j;j<=max_c;j++){
                        arr[i][j]=cur;
                        
                        cur++;
                        
                    }
                    j--;
                    min_r++;
                    var=false;
                     
                }
                else{
                    j--;
                    for(  j;j>=min_c;j--){
                        arr[i][j]=cur;
                        cur++;
                        
                    }
                    j++;
                    max_r--;
                    var=false;
                }
            }
            else{
                if(dir){
                    i++;
                    for(  i;i<=max_r;i++){
                        arr[i][j]=cur;
                        cur++;
                        
                    }
                    i--;
                    max_c--;
                    var=true;
                    dir=false;
                }
                else{
                    i--;
                    for(  i;i>=min_r;i--){
                        arr[i][j]=cur;
                        cur++;
                        
                    }
                    i++;
                    min_c++;
                    var=true;
                    dir=true;
                }
            }
        }
    }
    vector<vector<int>> generateMatrix(int n) {
       
        vector<vector<int>>v(n,vector<int>(n,0));
        spiral(v,n);
        return v;
    }
};