#ifndef VIN_HPP
#define VIN_HPP

#include <iostream>

class Vin
{   
public:
    Vin();
    Vin(std::string vin);
    ~Vin();
    std::string getVin();
    bool operator==(const Vin vin);
    friend std::ostream& operator<<(std::ostream& os, Vin& vin);
    
protected:
    std::string *vin_;
};

#endif