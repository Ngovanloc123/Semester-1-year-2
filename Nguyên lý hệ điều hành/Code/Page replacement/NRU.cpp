#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct Page {
    int pageNumber;  // Số trang
    bool referenced; // Cờ tham chiếu
    bool modified;   // Cờ đã sửa đổi

    Page(int pageNumber) {
        this->pageNumber = pageNumber;
        referenced = false;
        modified = false;
    }
};

// Hàm để đặt lại cờ tham chiếu
void resetReferencedBits(std::vector<Page> &pages) {
    for (auto &page : pages) {
        page.referenced = false; // Đặt lại cờ tham chiếu
    }
}

// Hàm thay thế trang theo thuật toán NRU
int nruReplacement(const std::vector<Page> &pages) {
    std::vector<int> class0, class1, class2, class3;

    // Phân loại các trang theo cờ tham chiếu và cờ đã sửa đổi
    for (int i = 0; i < pages.size(); ++i) {
        const Page &page = pages[i];
        if (!page.referenced && !page.modified) {
            class0.push_back(i);  // Lớp 0
        } else if (!page.referenced && page.modified) {
            class1.push_back(i);  // Lớp 1
        } else if (page.referenced && !page.modified) {
            class2.push_back(i);  // Lớp 2
        } else {
            class3.push_back(i);  // Lớp 3
        }
    }

    // Chọn trang để thay thế dựa trên lớp
    if (!class0.empty()) {
        return class0[rand() % class0.size()];  // Chọn ngẫu nhiên trang trong lớp 0
    }
    if (!class1.empty()) {
        return class1[rand() % class1.size()];  // Chọn ngẫu nhiên trang trong lớp 1
    }
    if (!class2.empty()) {
        return class2[rand() % class2.size()];  // Chọn ngẫu nhiên trang trong lớp 2
    }
    return class3[rand() % class3.size()];      // Chọn ngẫu nhiên trang trong lớp 3
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Khởi tạo hạt giống ngẫu nhiên

    int numFrames, numPages;
    // std::cout << "Enter the number of frames: ";
    
    // std::cout << "Enter the number of pages: ";
    

    std::vector<Page> pages = {0,4,1,4,2,4,3,4,2,4,0,4,1,4,2,4,3,4};
    numFrames = 3;
    numPages = pages.size();
    // std::cout << "Enter the page reference string (space-separated): ";
    // for (int i = 0; i < numPages; ++i) {
    //     int pageNumber;
    //     std::cin >> pageNumber; // Nhập số trang từ người dùng
    //     pages.push_back(Page(pageNumber)); // Thêm trang vào danh sách
    // }

    std::vector<int> frames(numFrames, -1); // Danh sách khung trang
    int pageFaults = 0; // Số lỗi trang

    for (int i = 0; i < numPages; ++i) {
        bool pageInMemory = false; // Kiểm tra xem trang đã có trong bộ nhớ hay chưa

        // Kiểm tra xem trang đã có trong bộ nhớ hay chưa
        for (int j = 0; j < numFrames; ++j) {
            if (frames[j] == pages[i].pageNumber) {
                pageInMemory = true; // Trang đã có trong bộ nhớ
                pages[i].referenced = true; // Đặt cờ referenced
                break;
            }
        }

        // Nếu trang không có trong bộ nhớ
        if (!pageInMemory) {
            int replaceIndex;
            // Kiểm tra xem còn khung trống không
            if (std::find(frames.begin(), frames.end(), -1) != frames.end()) {
                replaceIndex = std::find(frames.begin(), frames.end(), -1) - frames.begin(); // Lấy vị trí khung trống
            } else {
                replaceIndex = nruReplacement(pages); // Gọi hàm thay thế NRU
            }
            frames[replaceIndex] = pages[i].pageNumber; // Thay thế trang
            pages[i].referenced = true; // Đặt cờ referenced
            pageFaults++; // Tăng số lỗi trang
        }

        // Đặt lại các bit referenced sau mỗi chu kỳ
        if (i % 5 == 0) {
            resetReferencedBits(pages); // Đặt lại cờ tham chiếu
        }
    }

    // Hiển thị kết quả
    std::cout << "Total page faults: " << pageFaults << std::endl;
    return 0;
}
