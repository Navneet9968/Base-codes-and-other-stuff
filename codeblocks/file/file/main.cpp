#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Create a mutex object to synchronize access to shared resources
std::mutex mtx;

// Define a bounded buffer to store data
int buffer[5];
int buffer_index = 0;

// Function to simulate IPC
void ipc_simulator(int id) {
    // Lock the mutex before accessing shared resources
    mtx.lock();
    
    // Simulate some IPC activity
    std::cout << "Process " << id << " is performing IPC" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    // Unlock the mutex after accessing shared resources
    mtx.unlock();
}

// Function to simulate bounded buffer activity
void bb_simulator(int id) {
    // Lock the mutex before accessing shared resources
    mtx.lock();
    
    // Simulate some bounded buffer activity
    if (buffer_index < 5) {
        buffer[buffer_index] = id;
        buffer_index++;
    }
    std::cout << "Thread " << id << " added an item to the buffer" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    // Unlock the mutex after accessing shared resources
    mtx.unlock();
}

int main() {
    // Create two threads to simulate IPC and bounded buffer activity
    std::thread t1(ipc_simulator, 1);
    std::thread t2(bb_simulator, 2);
    
    // Wait for both threads to finish
    t1.join();
    t2.join();
    
    return 0;
}
