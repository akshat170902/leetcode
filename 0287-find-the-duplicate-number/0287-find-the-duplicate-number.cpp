class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare=nums[0],tor=nums[0];
        do{
            hare=nums[nums[hare]];
            tor=nums[tor];
        }while(tor!=hare);
        tor=nums[0];
        while(tor!=hare){
            tor=nums[tor];
            hare=nums[hare];
        }
        return hare;
    }
};