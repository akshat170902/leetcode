class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return (sum%10+sum/10)%10+(sum%10+sum/10)/10;

    }
};