#include <iostream>
using namespace std;

const int MAX = 100; // Giới hạn độ dài dãy nhị phân
int n;               // Độ dài của dãy nhị phân
int s[MAX];          // Mảng lưu trữ dãy nhị phân

// Hàm đệ quy sinh các dãy nhị phân
void generateBinary(int k) {
    if (k == n + 1) { // Nếu đã điền đủ n phần tử
        for (int i = 1; i <= n; i++) {
            cout << s[i] << " "; // In ra dãy nhị phân
        }
        cout << endl;
    } else {
        s[k] = 0; // Gán giá trị 0 cho phần tử s[k]
        generateBinary(k + 1); // Gọi đệ quy với k+1

        s[k] = 1; // Gán giá trị 1 cho phần tử s[k]
        generateBinary(k + 1); // Gọi đệ quy với k+1
    }
}

int main() {
    cout << "Enter the length of binary sequence: ";
    cin >> n; // Nhập độ dài của dãy nhị phân
    generateBinary(1); // Gọi hàm bắt đầu từ phần tử thứ 1
    return 0;
}
