#pragma once
#include <functional>
#include <chrono>
#include <ctime>
class Timer
{

    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool m_bRunning = false;
public:
    std::function<double()> Func1;
    Timer(char name = 'N') {
		switch (name) {
		case 'S': {
			Func1 = std::bind(&Timer::elapsedSeconds, this);
			break;
		}
		case 'M': {
			Func1 = std::bind(&Timer::elapsedMilliseconds, this);
			break;
		}
		case 'N': {
			Func1 = std::bind(&Timer::elapsedNanoseconds, this);
			break;
		}
		}
    }

    void start();
    void stop();
    double elapsedMilliseconds();
    double elapsedNanoseconds();
    double elapsedSeconds();
};



