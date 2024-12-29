#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void matrixChainOrder(vector<int> &p, vector<vector<int>> &m, vector<vector<int>> &s) {
    int n = p.size();
    // Trường hợp cơ sở
    for(int i = 1; i <= n; i++) m[i][i] = 0;

    for(int l = 2; l <= n; ++l) {
        for(int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printMatrix(vector<vector<int>> a) {
    int n = a.size() - 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    ifstream file("Matrix.inp");
    if(!file) {
        cout << "Cannot open file!" << endl;
        return 0;
    }

    int n;
    file >> n;
    vector<int> p;
    for(int i = 0; i <= n; i++) {
        int tmp;
        file >> tmp;
        p.push_back(tmp);
    }
    // Tạo ma trận quy hoạch
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    // Tạo ma trận lưu vách ngăn
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
    matrixChainOrder(p, m, s);
    cout << "Ma trận quy hoạch:" << endl;
    printMatrix(m);
    cout << "Ma trận lưu vách ngăn:" << endl;
    printMatrix(s);
    file.close();
} 