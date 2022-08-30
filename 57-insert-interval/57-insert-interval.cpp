class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        
        int n=interval.size();
        vector<vector<int>>ans;
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }
        bool flag=true;
        int start=newInterval[0],end=newInterval[1];
        for(int i=0;i<n;){
            
            if(flag&&i==0&&end<interval[0][0]){
                flag=false;
                ans.push_back(newInterval);
                
            }
            else if(flag&&i==n-1&&interval[n-1][1]<start){
                ans.push_back(interval[n-1]);
                i++;
                ans.push_back(newInterval);
                flag=false;
            }
            
            else if(flag&&i>0&&start>interval[i-1][1]&&end<interval[i][0]){
                ans.push_back(newInterval);
                flag=false;
                
            }
            else if(flag&&start<=interval[i][1]&&end>=interval[i][0]){
              
                flag=false;
                int prev=min(start,interval[i][0]);
                
                while(i<n&&end>interval[i][1]){
                    i++;
                }
                int val=end;
                if(i<n&&end>=interval[i][0]){
                    val=interval[i][1];
                    i++;
                }
                vector<int>temp={prev,val};
                ans.push_back(temp);
            }
            else{
                ans.push_back(interval[i]);
                i++;
            }
        }
        
        return ans;
    }
};