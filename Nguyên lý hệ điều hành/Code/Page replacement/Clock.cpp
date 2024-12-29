#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numFrames, numPages;
    // Chuỗi tham chiếu trang
    vector<int> pages = {1, 2, 3, 4, 2, 5, 3, 1, 6, 7, 2, 2, 6};
    numFrames = 3; // Số khung trang

    vector<int> frames(numFrames, -1); // Danh sách khung trang
    vector<bool> referenced(numFrames, false); // Cờ tham chiếu
    int hand = 0; // Con trỏ vòng quay
    int pageFaults = 0; // Số lỗi trang

    for (int page : pages) {
        bool found = false;

        // Kiểm tra xem trang đã có trong bộ nhớ hay chưa
        for (int i = 0; i < numFrames; i++) {
            if (frames[i] == page) {
                referenced[i] = true; // Đánh dấu là đã tham chiếu
                found = true;
                break;
            }
        }

        // Nếu trang không có trong bộ nhớ
        if (!found) {
            // Vòng qua các khung trang để tìm vị trí thay thế
            while (true) {
                if (!referenced[hand]) {
                    // Thay thế trang không được tham chiếu
                    frames[hand] = page; // Gán trang mới vào khung
                    referenced[hand] = true; // Đánh dấu là đã tham chiếu
                    hand = (hand + 1) % numFrames; // Di chuyển con trỏ
                    pageFaults++; // Tăng số lỗi trang
                    break;
                } else {
                    // Nếu trang đã được tham chiếu, đặt lại cờ và di chuyển con trỏ
                    referenced[hand] = false;
                    hand = (hand + 1) % numFrames; // Di chuyển con trỏ
                }
            }
        }
    }

    // Hiển thị kết quả
    cout << "Total page faults: " << pageFaults << endl;
    return 0;
}
