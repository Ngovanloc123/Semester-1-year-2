#include <iostream>
using namespace std;

const int MAX = 100; // Giới hạn số đỉnh
int n;               // Số lượng đỉnh của đồ thị
int s[MAX];          // Mảng lưu trữ đường đi
int C[MAX][MAX];     // Ma trận kề của đồ thị (1: có cạnh, 0: không có cạnh)
int destination;     // Thành phố đích

// Hàm kiểm tra điều kiện hợp lệ của đường đi
bool checkPath(int k) {
    // Kiểm tra có kết nối từ s[k-1] đến s[k] hay không
    if (C[s[k - 1]][s[k]] == 0) return false;

    // Kiểm tra đỉnh hiện tại có trùng với các đỉnh trước đó không
    for (int i = 1; i < k; i++) {
        if (s[i] == s[k]) return false;
    }
    return true;
}

// Hàm đệ quy tìm đường đi
void findPath(int k) {
    if (s[k - 1] == destination) { // Nếu đã đến đích
        for (int i = 1; i < k; i++) {
            cout << s[i] << " "; // In ra đường đi hiện tại
        }
        cout << endl;
    } else {
        for (int j = 1; j <= n; j++) { // Duyệt qua tất cả các đỉnh
            s[k] = j; // Thử đi tới đỉnh j
            if (checkPath(k)) { // Kiểm tra đường đi hợp lệ
                findPath(k + 1); // Gọi đệ quy để tìm đường tiếp theo
            }
        }
    }
}

int main() {
    cout << "Enter the number of vertices (n): ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> C[i][j];
        }
    }

    cout << "Enter the destination vertex: ";
    cin >> destination;

    s[1] = 1; // Giả sử bắt đầu từ đỉnh 1
    findPath(1); // Bắt đầu tìm đường từ đỉnh thứ 2

    return 0;
}
