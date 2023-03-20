class Solution {
public:
    bool canPlaceFlowers(vector<int> flowerbed, int n) {
        int ans=0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0){
                if(i>0&&flowerbed[i-1]==1){
                    continue;
                }
                if(i<flowerbed.size()-1&&flowerbed[i+1]==1){
                    continue;
                }
                ans++;
                cout<<ans<<i<<endl;
                flowerbed[i]=1;
            }
        }
        return ans>=n;
    }
};