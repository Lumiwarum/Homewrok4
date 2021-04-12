#ifndef YANDEX_PERSONS_H
#define YANDEX_PERSONS_H
#include "worldData.h"
#include <vector>

using namespace std;

class person {
private:
    string name;
    string surname;
    vector<order> orderHistory;
public:
    person(string name,string surname){
        this->name=name;
        this->surname=surname;
    }
    string getName(){
        return name;
    }
    string getSurname(){
        return surname;
    }
    void addOrderToHistory(order ord){
        orderHistory.push_back(ord);
    }
    vector<order> getOrderHistory(){
        return orderHistory;
    }
};

class Passenger: public person{
private:
    int rating;
    payments paymentMethod;
    vector<coordinate> pinnedAddresses;
public:
    Passenger(string name,string surname,int rate,payments pay): person(name,surname){
        rating=rate;
        paymentMethod=pay;
    }
    Passenger(): person("Ivan","Ivanov"){

    }
    int getRating(){
        return rating;
    }
    payments getPayMethod(){
        return paymentMethod;
    }
    void setPayMethod(payments newpay){
        paymentMethod=newpay;
    }
    void addPinnedAddress(coordinate cord){
        pinnedAddresses.push_back(cord);
    }
    vector<coordinate> getPinnedAddresses(){
        return pinnedAddresses;
    }
};

class Driver: public person{
private:
    Car taxi;
    int rating;
    bool working;
    bool driving;
public:
    Driver(string Name,string Surname,Car car,int rate,bool driving): person(Name,Surname){
        taxi=car;
        rating=rate;
        working = true;
        this->driving= driving;
    }
    Car getCar(){
        return taxi;
    }
    void changeRiding(){
        if (driving){driving=false;}
        else {driving=true;}
    }
    int getRating(){
        return  rating;
    }
    bool isDriving(){
        return driving;
    }
};
#endif //YANDEX_PERSONS_H
