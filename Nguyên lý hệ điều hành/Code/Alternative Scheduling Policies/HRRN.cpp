#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Process {
    int id;             // Mã tiến trình
    int arrivalTime;    // Thời gian đến
    int burstTime;      // Thời gian thực thi
    int waitingTime;    // Thời gian chờ
    int turnaroundTime; // Thời gian quay vòng
    bool completed;     // Đánh dấu tiến trình đã hoàn thành

    Process(int id, int arrivalTime, int burstTime) {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->waitingTime = 0;
        this->turnaroundTime = 0;
        this->completed = false;
    }
};

// Hàm tính tỷ lệ đáp ứng (Response Ratio)
double calculateResponseRatio(const Process &p, int currentTime) {
    int waitingTime = currentTime - p.arrivalTime;
    return (double)(waitingTime + p.burstTime) / p.burstTime;
}

// Hàm thực hiện lập lịch HRRN
void highestResponseRatioNext(std::vector<Process> &processes) {
    int currentTime = 0;
    int completedProcesses = 0;
    int numProcesses = processes.size();

    while (completedProcesses < numProcesses) {
        int idx = -1;
        double highestRR = -1;  // Tỷ lệ đáp ứng cao nhất

        // Tìm tiến trình có tỷ lệ đáp ứng cao nhất
        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].arrivalTime <= currentTime && !processes[i].completed) {
                double responseRatio = calculateResponseRatio(processes[i], currentTime);
                if (responseRatio > highestRR) {
                    highestRR = responseRatio;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            // Không có tiến trình nào sẵn sàng, tăng thời gian hệ thống
            currentTime++;
            continue;
        }

        // Thực thi tiến trình có tỷ lệ đáp ứng cao nhất
        Process &p = processes[idx];
        p.waitingTime = currentTime - p.arrivalTime;
        currentTime += p.burstTime; // Cập nhật thời gian hiện tại sau khi tiến trình hoàn thành
        p.turnaroundTime = currentTime - p.arrivalTime;
        p.completed = true;
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

    // Thực thi thuật toán HRRN
    highestResponseRatioNext(processes);

    // Hiển thị kết quả
    displayResults(processes);

    return 0;
}
