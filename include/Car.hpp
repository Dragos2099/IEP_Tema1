#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>

const int VIN_SIZE = 12;
const int FIRST = 0;

class Car
{   
public:
    Car();
    Car(int horsePower, int nrSeats, std::string bodyStyle, std::string traction, int *vin);
    Car(const Car& car);
    ~Car();
    int getHorsePower();
    int getNrSeats();
    std::string getBodyStyle();
    std::string getTraction();
    std::string getVin();
    Car& operator=(const Car& car);
    virtual std::ostream& print(std::ostream& os);
    friend std::ostream& operator<<(std::ostream& os, Car& car);
    
protected:
    int horsePower_;
    int nrSeats_;
    std::string bodyStyle_;
    std::string traction_;
    int *vin_;
};

#endif