#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id;             // Mã tiến trình
    int arrivalTime;    // Thời gian đến
    int burstTime;      // Thời gian thực thi ban đầu
    int remainingTime;  // Thời gian còn lại
    int waitingTime;    // Thời gian chờ
    int turnaroundTime; // Thời gian quay vòng
    int queueLevel;     // Mức hàng đợi hiện tại

    Process(int id, int arrivalTime, int burstTime) {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->remainingTime = burstTime;
        this->waitingTime = 0;
        this->turnaroundTime = 0;
        this->queueLevel = 0; // Bắt đầu ở hàng đợi cao nhất
    }
};

// Hàm lập lịch feedback scheduling
void feedbackScheduling(vector<Process> &processes, const vector<int> &quantumLevels, int numQueues) {
    vector<queue<int>> queues(numQueues); // Mảng các hàng đợi tương ứng với các mức ưu tiên
    int currentTime = 0, completedProcesses = 0, numProcesses = processes.size();

    while (completedProcesses < numProcesses) {
        // Đưa tiến trình vào hàng đợi cao nhất nếu đã đến
        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 && processes[i].queueLevel == 0) {
                queues[0].push(i);
            }
        }

        bool foundProcess = false; // Kiểm tra nếu có tiến trình nào đang chạy

        // Duyệt từng hàng đợi từ cao xuống thấp
        for (int level = 0; level < numQueues; ++level) {
            if (!queues[level].empty()) {
                int processIndex = queues[level].front();
                queues[level].pop();
                Process &p = processes[processIndex];

                int quantum = quantumLevels[level]; // Quantum của hàng đợi hiện tại
                foundProcess = true;

                // Thực thi tiến trình trong thời gian quantum
                if (p.remainingTime > quantum) {
                    currentTime += quantum;
                    p.remainingTime -= quantum;

                    // Chuyển tiến trình xuống hàng đợi ưu tiên thấp hơn nếu còn
                    if (level < numQueues - 1) {
                        p.queueLevel++;
                        queues[level + 1].push(processIndex);
                    } else {
                        queues[level].push(processIndex); // Ở hàng đợi thấp nhất, quay lại hàng đợi đó
                    }
                } else { // Tiến trình hoàn thành
                    currentTime += p.remainingTime;
                    p.remainingTime = 0;
                    p.turnaroundTime = currentTime - p.arrivalTime;
                    p.waitingTime = p.turnaroundTime - p.burstTime;
                    completedProcesses++;
                }
                break; // Thực thi tiến trình xong, bỏ qua các mức hàng đợi khác
            }
        }

        // Nếu không có tiến trình nào đang chạy, tăng thời gian hệ thống
        if (!foundProcess) {
            currentTime++;
        }
    }
}

// Hàm hiển thị kết quả
void displayResults(const vector<Process> &processes) {
    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto &p : processes) {
        cout << p.id << "\t\t" << p.arrivalTime << "\t\t"
             << p.burstTime << "\t\t" << p.waitingTime << "\t\t"
             << p.turnaroundTime << "\n";

        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnaroundTime;
    }

    cout << "Average waiting time: " << totalWaitingTime / processes.size() << "\n";
    cout << "Average turnaround time: " << totalTurnaroundTime / processes.size() << "\n";
}

int main() {
    int numProcesses, numQueues;

    // Nhập số lượng tiến trình
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<Process> processes;

    // Nhập thông tin cho từng tiến trình (ID, thời gian đến, thời gian thực thi)
    for (int i = 0; i < numProcesses; ++i) {
        int arrivalTime, burstTime;
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> arrivalTime >> burstTime;
        processes.push_back(Process(i + 1, arrivalTime, burstTime));
    }

    // Nhập số lượng hàng đợi
    cout << "Enter the number of queues: ";
    cin >> numQueues;

    vector<int> quantumLevels(numQueues);

    // Nhập thời gian quantum cho từng hàng đợi
    for (int i = 0; i < numQueues; ++i) {
        cout << "Enter quantum time for queue " << i + 1 << ": ";
        cin >> quantumLevels[i];
    }

    // Thực thi thuật toán feedback scheduling
    feedbackScheduling(processes, quantumLevels, numQueues);

    // Hiển thị kết quả
    displayResults(processes);

    return 0;
}
