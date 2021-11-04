#ifndef ELECTRIC_HPP
#define ELECTRIC_HPP

class Electric
{
public:
    virtual void chargeBatteryByPercent(int percent) = 0;

protected:
    int battery_;
};

#endif