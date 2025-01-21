#include "../include/Chronometer.h"
#include <iostream>

Chronometer::Chronometer() : isRunning(false) {}

void Chronometer::start() {
    startTime = std::chrono::high_resolution_clock::now();
    isRunning = true;
}

void Chronometer::stop() {
    endTime = std::chrono::high_resolution_clock::now();
    isRunning = false;
}

double Chronometer::elapsed() const {
    if (isRunning) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(currentTime - startTime).count();
    } else {
        return std::chrono::duration<double>(endTime - startTime).count();
    }
}

void Chronometer::print(const std::string& message) const {
    std::cout << message << elapsed() << " sec" << std::endl;
}