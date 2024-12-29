#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <iomanip> // Thư viện cho setw
using namespace std;

// Hàm in ra bảng theo dõi các khung trang
void printFrames(const list<int>& lruList, int numFrames, int replacedPage = -1, bool pageFault = false) {
    auto it = lruList.begin();
    for (int i = 0; i < numFrames; i++) {
        if (i < lruList.size()) {
            if (replacedPage != -1 && *it == replacedPage) {
                cout << setw(4) << *it << "*"; // Đánh dấu trang vừa được thay thế
            } else {
                cout << setw(4) << *it; // In ra trang hiện tại trong khung
            }
            ++it;
        } else {
            cout << setw(4) << "-"; // Nếu chưa có khung này
        }
    }
    if (pageFault) {
        cout << "  PF"; // Đánh dấu Page Fault
    }
    cout << endl;
}

// Hàm tính số lượng page fault bằng thuật toán LRU và in bảng theo dõi
int findPageFaultsLRU(vector<int> referenceString, int numFrames) {
    unordered_map<int, list<int>::iterator> pageMap; // Bản đồ để lưu vị trí các trang
    list<int> lruList; // Danh sách sử dụng gần đây (least recently used)
    int pageFaults = 0;

    cout << "Reference String: ";
    for (int page : referenceString) {
        cout << page << " ";
    }
    cout << endl;
    cout << setw(10) << "Frames" << endl;

    for (int i = 0; i < referenceString.size(); i++) {
        int currentPage = referenceString[i];

        // Kiểm tra nếu trang chưa có trong bộ nhớ (page fault)
        if (pageMap.find(currentPage) == pageMap.end()) {
            pageFaults++; // Xảy ra page fault
            int replacedPage = -1; // Biến lưu trữ trang bị thay thế

            // Nếu bộ nhớ đã đầy
            if (lruList.size() == numFrames) {
                replacedPage = lruList.back(); // Trang ít được sử dụng gần đây nhất
                lruList.pop_back();           // Loại trang này khỏi danh sách
                pageMap.erase(replacedPage);  // Xóa trang khỏi bộ nhớ
            }

            // Thêm trang mới vào danh sách LRU và cập nhật bản đồ
            lruList.push_front(currentPage);
            pageMap[currentPage] = lruList.begin();

            // In trạng thái của các khung trang sau khi thay thế (nếu có)
            printFrames(lruList, numFrames, replacedPage, true);
        } else {
            // Nếu trang đã có trong bộ nhớ, di chuyển nó lên đầu danh sách
            lruList.erase(pageMap[currentPage]);  // Xóa trang khỏi vị trí cũ
            lruList.push_front(currentPage);      // Đưa trang lên đầu (vì vừa được sử dụng)
            pageMap[currentPage] = lruList.begin(); // Cập nhật vị trí mới trong bản đồ

            // In trạng thái khung mà không có page fault
            printFrames(lruList, numFrames);
        }
    }

    return pageFaults;
}

int main() {
    // Chuỗi tham chiếu trang
    vector<int> referenceString = {1,2,3,4,1,2,5,1,2,3,4,5};
    int numFrames = 5; // Số khung trang

    int pageFaults = findPageFaultsLRU(referenceString, numFrames);

    cout << "PF: " << pageFaults << endl;

    return 0;
}
