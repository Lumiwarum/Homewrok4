#include <iostream>
#include "System.h"
int main() {
    System systema;
    PassengerGateway& mobApp=systema.getPassengersApp();
    DriverGateway& drApp=systema.getDriverApp();
    string name,surname;
    cin >>name>>surname;
    Passenger stranger(name,surname,5,cheque);
    int i=mobApp.searchForPerson(stranger);
    mobApp.addPassenger(stranger);
    mobApp.logIn(1);
    cout <<mobApp.currentPassenger().getName()<<endl;
    Car machine("Baklazhan",ComfortPlus);
    Driver driver1("Gay","Aktivist",machine,5,0);
    drApp.addDriver(driver1);
    return 0;
}
