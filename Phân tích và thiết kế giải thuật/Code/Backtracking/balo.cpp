#include <iostream>
#include <vector>
using namespace std;

int n; // Số lượng vật phẩm
vector<int> v; // Giá trị của các vật phẩm
vector<int> w; // Trọng lượng của các vật phẩm
vector<int> s; // Vector giải pháp
vector<int> best_solution; // Giải pháp tốt nhất
int max_value = 0; // Giá trị lớn nhất tìm thấy

void xepbalo(int k, int W) {
    if (k == n) { 
        int current_value = 0;
        for (int i = 0; i < n; ++i) {
            current_value += s[i] * v[i];
        }
        if (current_value > max_value) {
            max_value = current_value;
            best_solution = s;
        }
    } else {
        s[k] = 0;
        xepbalo(k + 1, W);
        if (W >= w[k]) {
            s[k] = 1;
            xepbalo(k + 1, W - w[k]);
        }
    }
}

int main() {
    // Ví dụ khởi tạo
    n = 4;
    v = {10, 40, 30, 50};
    w = {5, 4, 6, 3};
    s.resize(n);
    best_solution.resize(n);

    int W = 10; // Trọng lượng tối đa của ba lô
    xepbalo(0, W);

    cout << "Giá trị lớn nhất: " << max_value << endl;
    cout << "Giải pháp tốt nhất: ";
    for (int i = 0; i < n; ++i) {
        cout << best_solution[i] << " ";
    }
    cout << endl;

    return 0;
}
