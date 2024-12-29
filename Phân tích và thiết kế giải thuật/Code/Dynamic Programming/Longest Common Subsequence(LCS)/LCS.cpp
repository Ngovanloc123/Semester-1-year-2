#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void LCS(string &X, string &Y, vector<vector<int>> &c, vector<vector<char>> &b) {
    int m = X.size();
    int n = Y.size();
    // Trường hợp cơ sở
    for(int i = 0; i <= m; i++) {c[i][0] = 0; b[i][0] = 'n';}
    for(int i = 0; i <= n; i++) {c[0][i] = 0; b[0][i] = 'n';}
    // Tính các giá trị của c[i][j]
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';
            } 
            else  if(c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '|';
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '_';
            }
        }
    }
}

void printLCS(vector<vector<char>> b, string X, int i, int j) {
    if(i == 0 || j == 0) {
        return;
    }
    if(b[i][j] == '\\') {
        printLCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    }
    else if(b[i][j] == '|') {
        printLCS(b, X, i - 1, j);
    }
    else {
        printLCS(b, X, i, j - 1);
    }
}

template<typename T>
void print(vector<vector<T>> a) {
    int m = a.size();
    int n = a[0].size();
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    ifstream inpFile("string.inp");
    if (!inpFile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }
    string X, Y;
    inpFile >> X;
    inpFile >> Y;
    vector<vector<int>> c(X.size() + 1, vector<int>(Y.size() + 1, 0));
    vector<vector<char>> b(X.size() + 1, vector<char>(Y.size() + 1));
    LCS(X, Y, c, b);
    cout << "Ma tran quy hoach dong:\n";
    print(c);
    cout << "Ma tran duong di:\n";
    print(b);
    cout << "LCS: ";
    printLCS(b, X, X.size(), Y.size());

    inpFile.close();
}