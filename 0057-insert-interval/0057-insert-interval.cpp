class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& nInter) {
        vector<int>a,b;
        vector<vector<int>>ans;
        for(auto &val:inter){
            a.push_back(val[0]);
            b.push_back(val[1]);
        }
        int x=upper_bound(a.begin(),a.end(),nInter[0])-a.begin()-1;
        int y=upper_bound(a.begin(),a.end(),nInter[1])-a.begin()-1;
        
        cout<<x<<y<<endl;
        if(x==y){
            if(x==-1){
                ans.push_back(nInter);
                for(int i=0;i<inter.size();i++){
                    ans.push_back(inter[i]);
                    
                }
                return ans;
            }
            else{
                if(nInter[0]>inter[x][1]){
                    for(int i=0;i<inter.size();i++){
                        ans.push_back(inter[i]);
                        if(i==x){
                            ans.push_back(nInter);
                        }
                        
                    }
                    return ans;
                }
            }
        }
        bool flag=true;
        for(int i=0;i<inter.size();i++){
            if(flag&&(i==x||x==-1)){
                if(x!=-1&&inter[x][1]<nInter[0]){
                    ans.push_back(inter[x]);
                }
                ans.push_back({min(nInter[0],inter[x+(x==-1||inter[x][1]<nInter[0])][0]),max(nInter[1],inter[y][1])});
                i=y;
                flag=false;
            }
            else{
                ans.push_back(inter[i]);
            }
        }
        return ans;

    }
};