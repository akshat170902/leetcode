class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int>m;
        for(auto&card:hand){
            m[card]++;
        }
        int iteration=n/groupSize;
        for(int i=0;i<iteration;i++){
            auto val=m.begin()->first;
            cout<<val<<endl;
            for(int j=0;j<groupSize;j++){
                if(m.count(val)){
                    m[val]--;
                    if(m[val]==0){
                        m.erase(val);
                    }
                    val++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};