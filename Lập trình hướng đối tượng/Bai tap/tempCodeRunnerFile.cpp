#include <iostream>
using namespace std;

template <class T>
class Exam {
public:
    T Func(const T& var_x, const T& var_y);
};

template <class T>
T Exam<T>::Func(const T& var_x, const T& var_y) {
    return var_x / var_y;
}

int main() {
    Exam<char> obj;
    cout << obj.Func(65, 1) << obj.Func(60.28, 1.1); // Biểu diễn ký tự 'A' bằng giá trị ASCII 65
    return 0;
}
