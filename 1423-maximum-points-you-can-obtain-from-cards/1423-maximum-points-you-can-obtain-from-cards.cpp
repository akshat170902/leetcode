class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size()-k;
        vector<int>arr(cardPoints.size());
        int sum =0;
        for(int i=0;i<cardPoints.size();i++){
            arr[i]=cardPoints[i]+sum;
            sum =arr[i];
        }
        int least=1e9;
        if(n==0)return arr[cardPoints.size()-1];
        for(int i=-1;i+n<cardPoints.size();i++){
            least=min(least,i==-1?arr[i+n]:arr[i+n]-arr[i]);
        }
        return arr[cardPoints.size()-1]-least;
        
    }
};