#ifndef YANDEX_WORLDDATA_H
#define YANDEX_WORLDDATA_H
#include <cmath>
using namespace std;

enum payments{
    cash,
    creditCard,
    cheque
};
enum carType{
    Economy=10,
    Comfort=20,
    ComfortPlus=25,
    Business=40
};
class coordinate{
private:
    int x;
    int y;
public:
    coordinate(){
        x=0;
        y=0;
    }
    coordinate(int a,int b){
        x=a;
        y=b;
    }
    void setXCoord(int a){
        x=a;
    }
    void setYCoord(int a){
        y=a;
    }
    int getXCoord(){
        return x;
    }
    int getYCoord(){
        return y;
    }
    int Distance(coordinate second){
        int dis=(int)sqrt(pow((second.getXCoord()-x),2)+pow((second.getYCoord()-y),2));
        return dis;
    }
};
class order{
private:
    int currentTime;
    carType typeOfCar;
    bool completed;
    payments payMethod;
    coordinate From;
    coordinate To;
public:
    order(coordinate from,coordinate to,carType car){
        From=from;
        To=to;
        typeOfCar=car;
        completed=false;
    }
    int getTime(){
        return (int)(From.Distance(To)/typeOfCar);
    }
    int getCost(){
        return (int)(From.Distance(To)*100/typeOfCar);
    }
    coordinate getToPlace(){
        return To;
    }
    coordinate getFromPlace(){
        return From;
    }
    void setPayment(payments pay){
        payMethod=pay;
    }
    payments getPayMethod(){
        return payMethod;
    }
    int getDistance(){
        return To.Distance(From);
    }
    carType getCarType(){
        return typeOfCar;
    }
    void completeOrder(){
        completed= true;

    }
    bool isCompleted(){
        return completed;
    }
};
class Car{
private:
    int freeBottleOfWater;
    carType typeOfCar;
    coordinate currentLocation;
    string model;
    int numberOfCar;
    static inline int numberCars=0;
public:
    Car(){

    }
    Car(string mod,carType type){
        numberOfCar=++numberCars;
        model=mod;
        typeOfCar=type;
    }
    carType getCarType(){
        return typeOfCar;
    }
    int getCarNumber(){
        return numberOfCar;
    }
    string getModel(){
        return model;
    }
    void setLocation(coordinate cor){
        currentLocation=cor;
    }
    coordinate getLocation(){
        return currentLocation;
    }
    void parkRightInFrontOfTheEntrance(){
        if (typeOfCar==Business){
            cout <<"Idk,what to write her<but this car is business"<<endl;
        }
    }
};

#endif //YANDEX_WORLDDATA_H
