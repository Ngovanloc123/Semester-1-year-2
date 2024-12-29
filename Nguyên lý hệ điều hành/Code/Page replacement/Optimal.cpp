#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>
using namespace std;

// Hàm tìm trang cần thay thế bằng thuật toán Optimal
int findOptimalReplacement(vector<int> referenceString, vector<int> frames, int currentIndex) {
    int farthest = currentIndex;
    int frameToReplace = -1;

    for (int i = 0; i < frames.size(); i++) {
        int j;
        for (j = currentIndex; j < referenceString.size(); j++) {
            if (frames[i] == referenceString[j]) {
                if (j > farthest) {
                    farthest = j;
                    frameToReplace = i;
                }
                break;
            }
        }

        // Nếu trang này không bao giờ được sử dụng lại
        if (j == referenceString.size()) {
            return i;
        }
    }

    // Nếu tất cả các trang sẽ được sử dụng lại, trả về trang xa nhất
    return (frameToReplace == -1) ? 0 : frameToReplace;
}

// Hàm in ra bảng theo dõi các khung trang
void printFrames(const vector<int>& frames, int numFrames, int replacedFrame = -1, bool pageFault = false) {
    for (int i = 0; i < numFrames; i++) {
        if (i < frames.size()) {
            if (frames[i] == -1) {
                cout << setw(4) << "-"; // Nếu khung chưa chứa trang
            } else {
                if (i == replacedFrame) {
                    cout << setw(4) << frames[i] << "*"; // Đánh dấu trang vừa bị thay thế
                } else {
                    cout << setw(4) << frames[i]; // In ra trang hiện tại trong khung
                }
            }
        } else {
            cout << setw(4) << "-"; // Nếu chưa có khung này
        }
    }
    if (pageFault) {
        cout << "  PF"; // Đánh dấu Page Fault
    }
    cout << endl;
}

// Hàm tính số lượng page fault bằng thuật toán Optimal và in bảng theo dõi
int findPageFaultsOptimal(vector<int> referenceString, int numFrames) {
    unordered_set<int> framesSet; // Bộ nhớ hiện tại chứa các trang
    vector<int> frames(numFrames, -1); // Danh sách các khung trang (ban đầu trống)
    int pageFaults = 0;

    cout << "Reference String: ";
    for (int page : referenceString) {
        cout << page << " ";
    }
    cout << endl;
    cout << setw(10) << "Frames" << endl;

    for (int i = 0; i < referenceString.size(); i++) {
        int currentPage = referenceString[i];

        // Kiểm tra nếu trang chưa có trong bộ nhớ
        if (framesSet.find(currentPage) == framesSet.end()) {
            pageFaults++; // Xảy ra page fault
            int replacedFrame = -1; // Biến lưu trữ chỉ số khung bị thay thế

            // Nếu bộ nhớ đã đầy
            if (framesSet.size() == numFrames) {
                replacedFrame = findOptimalReplacement(referenceString, frames, i + 1);
                framesSet.erase(frames[replacedFrame]); // Loại bỏ trang cần thay thế
                frames[replacedFrame] = currentPage;    // Thay trang mới vào khung đó
            } else {
                // Tìm vị trí trống trong danh sách frames
                for (int j = 0; j < numFrames; j++) {
                    if (frames[j] == -1) {
                        frames[j] = currentPage;
                        break;
                    }
                }
            }

            framesSet.insert(currentPage); // Thêm trang vào bộ nhớ

            // In trạng thái của các khung trang sau khi thay thế và đánh dấu PF
            printFrames(frames, numFrames, replacedFrame, true);
        } else {
            // Nếu trang đã có trong bộ nhớ, in trạng thái khung hiện tại
            printFrames(frames, numFrames);
        }
    }

    return pageFaults;
}

int main() {
    // Chuỗi tham chiếu trang
    vector<int> referenceString = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int numFrames = 4; // Số khung trang

    int pageFaults = findPageFaultsOptimal(referenceString, numFrames);

    cout << "PF: " << pageFaults << endl;

    return 0;
}
