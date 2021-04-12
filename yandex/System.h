#ifndef YANDEX_SYSTEM_H
#define YANDEX_SYSTEM_H
#include "Persons.h"
#include <fstream>
using namespace std;

class PassengerGateway{
private:
    vector<Passenger> passengers;
    int currentUser;
    vector<order> currentOrders;
    bool logged;
public:
    PassengerGateway(){}
    PassengerGateway(vector<Passenger> passengers){
        this->passengers=passengers;


    }
    bool isLogged(){
        return logged;
    }
    void addPassenger(Passenger pers){
        passengers.push_back(pers);
    }
    int searchForPerson(Passenger stranger){
        for (int i = 0;i<passengers.size();i++){
            if ((stranger.getName()==passengers[i].getName())&&(stranger.getSurname()==passengers[i].getSurname())){
                return i;
            }
        }
        return -1;
    }
    void logIn(int i){
        if ((i>-1)&&(i<passengers.size())){
            currentUser=i;
            logged= true;
        }
    }
    void logOut(){
        logged=false;
    }
    int seePrice(coordinate From,coordinate To,carType type){
        return (int)(From.Distance(To)*type/100);
    }
    int seeTime(coordinate From,coordinate To,carType type){
        return (int)(From.Distance(To)/type);
    }
    void orderRide(coordinate From,coordinate To,carType type){
        order NewOrder(From,To,type);
        NewOrder.setPayment(passengers[currentUser].getPayMethod());
        currentOrders.push_back(NewOrder);
    }
    Passenger& currentPassenger(){
        if (logged) return passengers[currentUser];
    }
    vector<Passenger> getPassengers(){
        return passengers;
    }

};
class DriverGateway{
private:
vector<Driver> drivers;
int currentUser;
vector<order> currentOrders;
bool logged;
public:
    DriverGateway(){}
    DriverGateway(vector<Driver> drivers){
        this->drivers=drivers;
        logged = false;
    }
    vector<Driver> getDrivers(){
        return drivers;
    }
    Driver& currentDriver(){
        if (logged) return drivers[currentUser];
    }
    vector<order> seeOrders(){
        return currentOrders;
    }
    order acceptOrder(int i){
        order retOrder=currentOrders[i];
        currentOrders.erase(currentOrders.begin()+i);
        return retOrder;
    }
    void addDriver(Driver newDriver){
        drivers.push_back(newDriver);
    }
    int searchForPerson(Driver stranger){
        for (int i=0;i<drivers.size();i++){
            if ((stranger.getName()==drivers[i].getName())&&(stranger.getSurname()==drivers[i].getSurname())){
                return i;
            }
        }
        return -1;
    }
    void logIn(int i){
        if ((i>0)&&(i<drivers.size())){
            currentUser=i;
            logged= true;
        }
    }
    void logOut(){
        logged=false;
    }

};
class System{
private:
    PassengerGateway pApp;
    DriverGateway dApp;
public:
    System(){
        vector<Passenger> passengers;
        ifstream fin("../Data.txt");
        int n=0,rate,pay; string name,surname;
        if (fin.peek()!='\0'){fin >>n;}
        for (int i = 0;i<n;i++){
            fin >>name>>surname>>rate>>pay;
            switch (pay+1){
                case 1: {
                    Passenger pu(name, surname, 5, cash);
                    passengers.push_back(pu);
                    break;
                }
                case 2: {
                    Passenger pu(name, surname, 5, creditCard);
                    passengers.push_back(pu);
                    break;
                }
                case 3: {
                    Passenger pu(name, surname, 5, cheque);
                    passengers.push_back(pu);
                    break;
                }
                default:
                    break;
            }
        }
        fin >>n; bool isDriving;int carNumber;string model;int type;
        vector<Driver> drivers;
        for (int i = 0;i<n;i++){
            fin >>name>>surname>>rate>>isDriving>>carNumber>>model>>type;
            switch (type) {
                case 10:{
                    Driver driver(name,surname,Car(model,Economy),rate,isDriving);
                    drivers.push_back(driver);
                    break;
                }
                case 20:{
                    Driver driver(name,surname,Car(model,Comfort),rate,isDriving);
                    drivers.push_back(driver);
                    break;
                }
                case 25:{
                    Driver driver(name,surname,Car(model,ComfortPlus),rate,isDriving);
                    drivers.push_back(driver);
                    break;
                }
                case 40:{
                    Driver driver(name,surname,Car(model,Business),rate,isDriving);
                    drivers.push_back(driver);
                    break;
                }

            }
        }
        PassengerGateway mobApp(passengers);
        DriverGateway drApp(drivers);
        pApp= mobApp;
        dApp=drApp;
    }
    PassengerGateway& getPassengersApp(){
        return pApp;
    }
    DriverGateway& getDriverApp(){
        return dApp;
    }
    ~System(){
        ofstream fout;
        fout.open("../Data.txt");
        vector<Passenger> passengers=pApp.getPassengers();
        fout <<passengers.size()<<endl;
        for(Passenger curPassenger : passengers){
            fout<<curPassenger.getName()<<" "<<curPassenger.getSurname()<<" "<<curPassenger.getRating()<<" ";
            fout<<curPassenger.getPayMethod()<<endl;
        }
        vector<Driver> drivers= dApp.getDrivers();
        fout <<drivers.size()<<endl;
        for (Driver curDriver : drivers){
            Car curCar=curDriver.getCar();
            fout<<curDriver.getName()<<" "<<curDriver.getSurname()<<" "<<curDriver.getRating()<<" ";
            fout<<curDriver.isDriving()<<" "<<curCar.getCarNumber()<<" "<<curCar.getModel()<<" ";
            fout<<curCar.getCarType()<<endl;
        }
        fout.close();
    }
};
#endif //YANDEX_SYSTEM_H
