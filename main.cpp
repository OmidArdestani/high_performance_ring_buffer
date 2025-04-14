#include "HPRingBuffer.hpp"

#include <iostream>
#include <thread>
#include <chrono>

int main() {
    HPRingBuffer<uint32_t, 1024> rb;

    using clock = std::chrono::high_resolution_clock;
    auto start_time = clock::now();

    constexpr uint64_t count = 10e6;

    std::thread producer([&]() {
        for (uint64_t i = 0; i < count; ++i) {
            while (!rb.push(i)) {
                // busy wait
            }
        }
    });

    std::thread consumer([&]() {
        uint64_t received = 0;
        while (received < count) {
            auto val = rb.pop();
            if (val) {
                ++received;
            }
        }
    });

    producer.join();
    consumer.join();

    auto end_time = clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Processed "<< count << " items in " << (duration.count()/1000) << " ms" << std::endl;
}
