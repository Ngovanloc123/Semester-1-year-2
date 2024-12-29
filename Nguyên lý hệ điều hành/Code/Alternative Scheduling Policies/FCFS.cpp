#include <iostream>
#include <vector>

struct Process {
    int id;             // Mã tiến trình
    int arrivalTime;    // Thời gian đến
    int burstTime;      // Thời gian thực thi
    int waitingTime;    // Thời gian chờ đợi
    int turnaroundTime; // Thời gian quay vòng

    Process(int id, int arrivalTime, int burstTime) {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->waitingTime = 0;
        this->turnaroundTime = 0;
    }
};

// Hàm tính toán thời gian chờ đợi và thời gian quay vòng cho mỗi tiến trình
void calculateTimes(std::vector<Process> &processes) {
    int currentTime = 0;

    for (int i = 0; i < processes.size(); ++i) {
        Process &p = processes[i];

        // Tính thời gian chờ: Thời gian bắt đầu - thời gian đến
        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;  // Nếu CPU nhàn rỗi, chờ đến khi tiến trình đến
        }
        p.waitingTime = currentTime - p.arrivalTime;

        // Tính thời gian quay vòng: Thời gian hoàn thành - thời gian đến
        currentTime += p.burstTime;
        p.turnaroundTime = p.waitingTime + p.burstTime;
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

    // Tính thời gian chờ và thời gian quay vòng trung bình
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

    // Tính toán thời gian chờ và thời gian quay vòng
    calculateTimes(processes);

    // Hiển thị kết quả
    displayResults(processes);

    return 0;
}
