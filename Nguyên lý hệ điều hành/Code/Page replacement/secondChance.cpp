#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // Để format đầu ra đẹp hơn

using namespace std;

// Hàm in bảng trạng thái của các khung trang
void printFrames(const vector<int>& frames, const vector<bool>& secondChance, bool pageFault) {
    for (int i = 0; i < frames.size(); i++) {
        if (frames[i] != -1) {
            cout << setw(3) << frames[i] << (secondChance[i] ? "S" : " ");
        } else {
            cout << setw(3) << "-";
        }
    }
    if (pageFault) {
        cout << "  PF"; // Page fault xảy ra
    }
    cout << endl;
}

int main() {
    // Chuỗi tham chiếu trang
    vector<int> pages = {5, 3, 2, 5, 1, 6, 4, 3, 5, 6, 4, 1};
    int numFrames = 4; // Số khung trang

    vector<int> frames(numFrames, -1);           // Khung trang
    vector<bool> secondChance(numFrames, false); // Ghi nhớ cơ hội thứ hai cho từng khung
    queue<int> fifoQueue;                        // Hàng đợi quản lý theo FIFO
    int pageFaults = 0;

    cout << "Reference String: ";
    for (int page : pages) {
        cout << page << " ";
    }
    cout << endl << setw(15) << "Frames" << endl;

    for (int page : pages) {
        bool found = false;

        // Kiểm tra xem trang có trong khung chưa
        for (int i = 0; i < numFrames; i++) {
            if (frames[i] == page) {
                secondChance[i] = true; // Trang có trong bộ nhớ, được gán cơ hội thứ hai
                found = true;
                break;
            }
        }

        // Nếu trang không có trong bộ nhớ, page fault xảy ra
        if (!found) {
            pageFaults++; // Tăng số lượng page faults
            if (fifoQueue.size() < numFrames) {
                // Thêm trang mới vào khung nếu còn chỗ trống
                for (int i = 0; i < numFrames; i++) {
                    if (frames[i] == -1) { // Tìm khung trống
                        frames[i] = page;
                        secondChance[i] = true;
                        fifoQueue.push(i);
                        break;
                    }
                }
            } else {
                // Nếu bộ nhớ đầy, dùng thuật toán Second Chance để thay thế
                while (true) {
                    int index = fifoQueue.front(); // Lấy trang đầu tiên theo FIFO
                    fifoQueue.pop();

                    if (!secondChance[index]) { // Nếu trang không có cơ hội thứ hai
                        frames[index] = page;   // Thay thế trang
                        secondChance[index] = true; // Đặt cơ hội thứ hai cho trang mới
                        fifoQueue.push(index);  // Đưa lại vào hàng đợi
                        break;
                    } else {
                        // Bỏ cơ hội thứ hai của trang, đưa lại cuối hàng đợi
                        secondChance[index] = false;
                        fifoQueue.push(index);
                    }
                }
            }
            printFrames(frames, secondChance, true); // In trạng thái khung sau page fault
        } else {
            printFrames(frames, secondChance, false); // In trạng thái khung nếu không có page fault
        }
    }

    cout << "Total page faults: " << pageFaults << endl;
    return 0;
}
