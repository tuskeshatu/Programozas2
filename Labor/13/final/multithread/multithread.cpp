#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>

bool ready = false;
std::mutex mpx;

void increase(int &counter)
{
    while (!ready)
    {
        mpx.lock();
        counter++;
        mpx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void decrease(int &counter)
{
    while (!ready)
    {
        mpx.lock();
        counter--;
        mpx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void print(int &counter)
{
    while (!ready)
    {
        std::cout << counter << ',';
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main()
{
    int counter = 0;

    std::thread t1 = std::thread(increase, std::ref(counter));
    std::thread t2 = std::thread(decrease, std::ref(counter));
    std::thread t3 = std::thread(print, std::ref(counter));

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    ready = true;

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
