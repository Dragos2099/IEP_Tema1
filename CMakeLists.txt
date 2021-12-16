cmake_minimum_required(VERSION 3.21.2)

project(CAR)

include_directories(include)

if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
    endif()    
endif()

set(myfiles 
    static/Car.cpp include/Car.hpp 
    static/ElectricCar.cpp include/ElectricCar.hpp 
    static/PetrolCar.cpp include/PetrolCar.hpp 
    static/HybridCar.cpp include/HybridCar.hpp
    include/Electric.hpp include/Petrol.hpp
    static/Vin.cpp include/Vin.hpp
    static/Lock.cpp include/Lock.hpp)

add_library(lib STATIC ${myfiles})    

add_executable(${PROJECT_NAME} static/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC lib pthread)

target_include_directories(${PROJECT_NAME} 
 PRIVATE static INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>)