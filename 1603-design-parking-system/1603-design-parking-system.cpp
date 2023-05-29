class ParkingSystem {
    int b,m,s;
public:
    ParkingSystem(int big, int medium, int small) {
        b=big;
        s=small;
        m=medium;
        cout<<big<<small<<medium<<endl;
    }
    
    bool addCar(int carType) {
        if(carType==3){
            if(s){
                s--;
                return true;
            }
            else{
                return false;
            }
        }
        if(carType==2){
            if(m){
                m--;
                return true;
            }
            else{
                return false;
            }
        }
        if(carType==1){
            cout<<"HI"<<endl;
            if(b){
                b--;
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */