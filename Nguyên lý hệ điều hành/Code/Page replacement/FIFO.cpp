#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// Hàm in ra trạng thái khung trang
void printFrames(const vector<int>& frames, int numFrames, bool pageFault) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] != -1) {
            cout << " " << frames[i] << " "; // In trang
        } else {
            cout << " - "; // Khung trống
        }
    }
    if (pageFault) {
        cout << " PF"; // Đánh dấu page fault
    }
    cout << endl;
}

// Hàm tính số lượng page fault bằng thuật toán FIFO
int findPageFaultsFIFO(vector<int> referenceString, int numFrames) {
    unordered_set<int> pages; // Bộ nhớ chứa các trang
    queue<int> pageOrder;     // Hàng đợi để theo dõi thứ tự các trang được nạp
    vector<int> frames(numFrames, -1); // Khung trang khởi tạo với -1
    int pageFaults = 0;

    for (int currentPage : referenceString) {
        bool pageFault = false; // Biến đánh dấu page fault

        // Kiểm tra nếu trang chưa có trong bộ nhớ (page fault)
        if (pages.find(currentPage) == pages.end()) {
            pageFault = true; // Đánh dấu trang bị lỗi
            pageFaults++; // Tăng số lượng page fault

            // Nếu số khung trang đã đầy
            if (pages.size() == numFrames) {
                int pageToRemove = pageOrder.front(); // Lấy trang lâu nhất (FIFO)
                pageOrder.pop();                     // Loại bỏ trang đó
                pages.erase(pageToRemove);           // Xóa trang khỏi bộ nhớ

                // Cập nhật lại khung trang
                for (int j = 0; j < numFrames; j++) {
                    if (frames[j] == pageToRemove) {
                        frames[j] = -1; // Đặt lại khung trang đã bị xóa
                        break;
                    }
                }
            }

            // Nạp trang mới vào bộ nhớ
            pages.insert(currentPage);
            pageOrder.push(currentPage);

            // Cập nhật trạng thái khung trang
            for (int j = 0; j < numFrames; j++) {
                if (frames[j] == -1) {
                    frames[j] = currentPage; // Đưa trang vào khung trống đầu tiên
                    break;
                }
            }
        }

        // In ra trạng thái khung sau mỗi lần nạp trang
        printFrames(frames, numFrames, pageFault);
    }
    return pageFaults;
}

int main() {
    // Chuỗi tham chiếu trang
    vector<int> referenceString = {1,2,3,4,1,2,5,1,2,3,4,5};
    int numFrames = 3; // Số khung trang

    int pageFaults = findPageFaultsFIFO(referenceString, numFrames);

    cout << "PF: " << pageFaults << endl;

    return 0;
}
