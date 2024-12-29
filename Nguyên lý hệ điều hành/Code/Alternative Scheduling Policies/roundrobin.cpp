#include <climits>
#include <iostream>
#include <iomanip> // Thư viện để sử dụng setw và định dạng in ấn
using namespace std;

struct Process {
    int AT, BT, ST[20], WT, FT, TAT, pos;
};

int quant;

int main() {
    int n, i, j;

    // Input số lượng tiến trình và quantum
    cout << "Enter the number of processes: ";
    cin >> n;
    Process p[n];

    cout << "Enter the quantum: ";
    cin >> quant;

    // Nhập các thông tin cần thiết
    // cout << "Enter the process numbers: " << endl;
    for (i = 0; i < n; i++)
        p[i].pos = i + 1;

    cout << "Enter the Arrival time and Burst time of processes: " << endl;
    for (i = 0; i < n; i++){
        cout << "Process " << i + 1 << ": ";
        cin >> p[i].AT >> p[i].BT;;
    }

    // cout << "Enter the Burst time of processes: " << endl;
    // for (i = 0; i < n; i++)
    //     cin >> p[i].BT;

    // Khởi tạo các biến
    int c = n, s[n][20];
    float time = 0, mini = INT_MAX, b[n], a[n];

    // Khởi tạo các mảng lưu burst time và arrival time
    int index = -1;
    for (i = 0; i < n; i++) {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
        for (j = 0; j < 20; j++) {
            s[i][j] = -1;
        }
    }

    int tot_wt = 0, tot_tat = 0;
    bool flag = false;

    while (c != 0) {
        mini = INT_MAX;
        flag = false;

        for (i = 0; i < n; i++) {
            float p = time + 0.1;
            if (a[i] <= p && mini > a[i] && b[i] > 0) {
                index = i;
                mini = a[i];
                flag = true;
            }
        }

        if (!flag) {
            time++;
            continue;
        }

        // Tính thời gian bắt đầu (start time)
        j = 0;
        while (s[index][j] != -1) {
            j++;
        }

        if (s[index][j] == -1) {
            s[index][j] = time;
            p[index].ST[j] = time;
        }

        if (b[index] <= quant) {
            time += b[index];
            b[index] = 0;
        } else {
            time += quant;
            b[index] -= quant;
        }

        if (b[index] > 0) {
            a[index] = time + 0.1;
        }

        // Tính toán thời gian hoàn thành (completion time)
        if (b[index] == 0) {
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            tot_wt += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            tot_tat += p[index].TAT;
        }
    }

    // In kết quả theo định dạng đẹp
    cout << left << setw(15) << "Process" 
         << setw(15) << "Arrival Time" 
         << setw(15) << "Burst Time" 
         << setw(25) << "Start Time(s)" 
         << setw(15) << "Final Time" 
         << setw(15) << "Wait Time" 
         << setw(20) << "TurnAround Time" << endl;

    cout << setfill('-') << setw(110) << "-" << endl; // Đường kẻ ngang
    cout << setfill(' '); // Reset fill character về mặc định

    for (i = 0; i < n; i++) {
        cout << left << setw(15) << p[i].pos
             << setw(15) << p[i].AT
             << setw(15) << p[i].BT;
        
        // In tất cả các thời gian bắt đầu
        j = 0;
        while (s[i][j] != -1) {
            cout << p[i].ST[j] << " ";
            j++;
        }

        cout << setw(25 - j * 3) << ""; // Căn khoảng trống sau Start Time

        cout << setw(15) << p[i].FT
             << setw(15) << p[i].WT
             << setw(20) << p[i].TAT << endl;
    }

    // Tính toán và in thời gian trung bình
    double avg_wt = tot_wt / static_cast<double>(n);
    double avg_tat = tot_tat / static_cast<double>(n);

    cout << setfill('-') << setw(110) << "-" << endl; // Đường kẻ ngang
    cout << setfill(' '); // Reset fill character về mặc định
    cout << "The average wait time is: " << avg_wt << endl;
    cout << "The average TurnAround time is: " << avg_tat << endl;

    return 0;
}
