#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <chrono>
#include <string>

class Chronometer {
public:
    Chronometer();
    void start();
    void stop();
    double elapsed() const;
    void print(const std::string& message) const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
    bool isRunning;
};

#endif