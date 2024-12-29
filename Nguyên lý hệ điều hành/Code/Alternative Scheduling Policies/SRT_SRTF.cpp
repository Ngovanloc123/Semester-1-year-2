#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;

struct Process {
    int id;             // Mã tiến trình
    int arrivalTime;    // Thời gian đến
    int burstTime;      // Thời gian thực thi ban đầu
    int remainingTime;  // Thời gian còn lại
    int waitingTime;    // Thời gian chờ
    int turnaroundTime; // Thời gian quay vòng
    bool completed;     // Đánh dấu tiến trình đã hoàn thành

    Process(int id, int arrivalTime, int burstTime) {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->remainingTime = burstTime;
        this->waitingTime = 0;
        this->turnaroundTime = 0;
        this->completed = false;
    }
};

void shortestRemainingTime(std::vector<Process> &processes) {
    int currentTime = 0;
    int completedProcesses = 0;
    int numProcesses = processes.size();
    int lastExecutedTime = -1; // Để lưu thời gian chạy của tiến trình cuối cùng

    while (completedProcesses < numProcesses) {
        // Tìm tiến trình có thời gian còn lại ngắn nhất tại thời điểm hiện tại
        int idx = -1;
        int minRemainingTime = INT_MAX;

        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].arrivalTime <= currentTime && 
                !processes[i].completed && 
                processes[i].remainingTime < minRemainingTime) {
                minRemainingTime = processes[i].remainingTime;
                idx = i;
            }
        }

        if (idx == -1) {
            // Không có tiến trình nào sẵn sàng, tăng thời gian hệ thống
            currentTime++;
            continue;
        }

        // Nếu thời gian hiện tại khác với thời gian của tiến trình cuối cùng,
        // tiến trình này được chờ, cập nhật thời gian chờ cho các tiến trình khác
        if (lastExecutedTime != currentTime) {
            for (int i = 0; i < numProcesses; i++) {
                if (i != idx && processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                    processes[i].waitingTime++;
                }
            }
        }

        // Giảm thời gian còn lại của tiến trình đang chạy
        processes[idx].remainingTime--;
        currentTime++;
        lastExecutedTime = currentTime;

        // Nếu tiến trình hoàn thành
        if (processes[idx].remainingTime == 0) {
            completedProcesses++;
            processes[idx].completed = true;
            processes[idx].turnaroundTime = currentTime - processes[idx].arrivalTime;
            processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
        }
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

    // Thực thi thuật toán SRT
    shortestRemainingTime(processes);

    // Hiển thị kết quả
    displayResults(processes);

    return 0;
}
