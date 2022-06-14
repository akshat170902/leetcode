class Solution {
public:
    int maxProfit(vector<int>& prices) {
    vector<vector<int>>cur(2,vector<int>(3)),ahead(2,vector<int>(3));
    for(int i=prices.size()-1;i>=0;i--){
        for(int j=0;j<=1;j++){
            for(int k=1;k<3;k++){
                
                    if(j){
                        cur[j][k]=max(-prices[i]+ahead[0][k],ahead[1][k]);
                    }
                    else{
                        cur[j][k]=max(prices[i]+ahead[1][k-1],ahead[0][k]);
                    }
                
                
            }
            ahead=cur;
        }
    }
    return cur[1][2];
}
};