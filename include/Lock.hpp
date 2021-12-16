#ifndef LOCK_HPP
#define LOCK_HPP

#include <memory>
#include <mutex>
#include <iostream>
#include <../include/Car.hpp>

class Car;

class Lock
{
public:
    Lock(Car *car);
    ~Lock();
    void lock();
    void unlock();

private:
    Lock(const Lock&) = delete;
    Lock& operator=(Lock& lock) = delete;
    std::unique_ptr<std::mutex> mutexPtr_;
    Car *car_;
};

#endif