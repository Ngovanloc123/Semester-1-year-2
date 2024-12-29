#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id;             // Mã tiến trình
    int arrivalTime;    // Thời gian đến
    int burstTime;      // Thời gian thực thi ban đầu
    int waitingTime;    // Thời gian chờ
    int turnaroundTime; // Thời gian quay vòng
    bool completed;     // Đã hoàn thành hay chưa

    Process(int id, int arrivalTime, int burstTime) {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->waitingTime = 0;
        this->turnaroundTime = 0;
        this->completed = false;
    }
};

bool compareByArrival(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

bool compareByBurst(const Process &a, const Process &b) {
    return a.burstTime < b.burstTime;
}

void shortestProcessNext(std::vector<Process> &processes) {
    int currentTime = 0;
    int completedProcesses = 0;
    int numProcesses = processes.size();

    while (completedProcesses < numProcesses) {
        // Lọc các tiến trình đã đến và chưa hoàn thành
        std::vector<Process*> readyQueue;
        for (auto &p : processes) {
            if (p.arrivalTime <= currentTime && !p.completed) {
                readyQueue.push_back(&p);
            }
        }

        if (readyQueue.empty()) {
            currentTime++; // Nếu không có tiến trình sẵn sàng, tăng thời gian chờ
            continue;
        }

        // Chọn tiến trình có thời gian thực thi ngắn nhất
        std::sort(readyQueue.begin(), readyQueue.end(), [](Process *a, Process *b) {
            return a->burstTime < b->burstTime;
        });

        Process *currentProcess = readyQueue[0];

        // Cập nhật thời gian hệ thống và tiến trình
        currentTime += currentProcess->burstTime;
        currentProcess->completed = true;
        currentProcess->turnaroundTime = currentTime - currentProcess->arrivalTime;
        currentProcess->waitingTime = currentProcess->turnaroundTime - currentProcess->burstTime;

        completedProcesses++;
    }
}

// Hàm hiển thị kết quả
void displayResults(const std::vector<Process> &processes) {
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    std::cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto &p : processes) {
        std::cout << p.id << "\t\t" << p.arrivalTime << "\t\t"
                  << p.burstTime << "\t\t" << p.waitingTime << "\t\t"
                  << p.turnaroundTime << "\n";

        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnaroundTime;
    }

    std::cout << "Average waiting time: " << totalWaitingTime / processes.size() << "\n";
    std::cout << "Average turnaround time: " << totalTurnaroundTime / processes.size() << "\n";
}

int main() {
    int numProcesses;

    // Nhập số lượng tiến trình
    std::cout << "Enter the number of processes: ";
    std::cin >> numProcesses;

    std::vector<Process> processes;

    // Nhập thông tin cho từng tiến trình (ID, thời gian đến, thời gian thực thi)
    for (int i = 0; i < numProcesses; ++i) {
        int arrivalTime, burstTime;
        std::cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        std::cin >> arrivalTime >> burstTime;
        processes.push_back(Process(i + 1, arrivalTime, burstTime));
    }

    // Sắp xếp tiến trình theo thời gian đến
    std::sort(processes.begin(), processes.end(), compareByArrival);

    // Thực thi thuật toán SPN
    shortestProcessNext(processes);

    // Hiển thị kết quả
    displayResults(processes);

    return 0;
}
