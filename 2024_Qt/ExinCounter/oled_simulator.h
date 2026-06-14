#ifndef OLED_SIMULATOR_H
#define OLED_SIMULATOR_H

#include <iostream>

class OLEDSimulator {
public:
    static void displayCounter(int value) {
        std::cout << "Simulated OLED: Count = " << value << std::endl;
    }
};

#endif // OLED_SIMULATOR_H
