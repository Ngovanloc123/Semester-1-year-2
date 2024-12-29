#include <iostream>
#include <vector>

using namespace std;

void display(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}

bool ascending(int left, int right) {
    return left > right;
}

bool descending(int left, int right) {
    return left < right;
}

void selectionSort(int n, int a[], bool CompFunction(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (CompFunction(a[pos], a[j])) {
                pos = j;
            }
        }
        swap(a[i], a[pos]);
    }
}
//
void insertionSort(int n, int a[], bool CompFunction(int, int)) {
    for(int i = 1; i < n; i++) {
        int value = a[i], pos = i - 1;
        while(pos >= 0 && CompFunction(a[pos], value))
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = value;
    }
} 

void bubbleSort(int n, int a[], bool CompFunction(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (CompFunction(a[j], a[j + 1])) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int partition(int a[], int l, int r, bool CompFunction(int, int)) {
    int pivot = a[r];// Chọn giá trị cuối làm chốt
    int i = l - 1;
    for(int j = l; j < r; j++) {
        if(CompFunction(pivot, a[j])){
            ++i;
            swap(a[j], a[i]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}
//
void quickSort(int a[], int l, int r, bool CompFunction(int, int)) {
    if(l >= r) return;
    int p = partition(a, l, r, CompFunction);
    quickSort(a, l, p - 1, CompFunction);
    quickSort(a, p + 1, r, CompFunction);
}

void merge(int a[], int l, int m, int r, bool CompFunction(int, int)) {
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while(i < x.size() && j < y.size()) {
		if(CompFunction(y[j], x[i])) a[l++] = x[i++];
		else a[l++] = y[j++];
	}
	while(i < x.size()) a[l++] = x[i++];
	while(j < y.size()) a[l++] = y[j++];
}

void mergeSort(int a[], int l ,int r, bool CompFunction(int, int)) {
	if(l < r) {
		int m = (l + r)/2;
		mergeSort(a, l, m, CompFunction);
		mergeSort(a, m + 1, r, CompFunction);
		merge(a, l, m, r, CompFunction);
	}
}

void heapify(int a[], int n, int i, bool CompFunction(int, int)) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && CompFunction(a[l], a[largest]))
		largest = l;
	if (r < n && CompFunction(a[r], a[largest]))
		largest = r;
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify (a, n, largest, CompFunction);
	}
}

// Xây dựng MaxHeap hoặc MinHeap
void buildHeap(int a[], int n, bool CompFunction(int, int)) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i, CompFunction);
    }
}
//
void heapSort(int a[], int n, bool CompFunction(int, int)) {
	// Xây dựng MaxHeap hoặc MinHeap
	buildHeap(a, n, CompFunction);
    // Heap Sort
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		heapify(a, i, 0, CompFunction);
	}
}

void shellSort(int a[], int n, bool CompFunction(int, int)) {
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for(j = i; j >= gap && CompFunction(a[j - gap], temp); j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

bool binarySearch(int a[], int n, int x, bool CompFunction(int, int)) {
    int l = 0;
    int r = n - 1;
    while(l <= r) {
        int m = (l + r)/2;
        if(a[m] == x) return true;
        if(CompFunction(x, a[m])) l = m + 1;
        else r = m - 1;
    }
    return false;
}

int main() {
    int n = 11;
    int *A = new int[n];
    A[0] = 2;
    A[1] = 5;
    A[2] = 4;
    A[3] = 30;
    A[4] = 7;
    A[5] = 6;
    A[6] = 10;
    A[7] = 20;
    A[8] = 15;
    A[9] = 17;
    A[10] = 9;
    cout << "Selection Sort\n";
    cout << "Tang dan: ";
    selectionSort(n, A, ascending);
    display(n, A);
    cout << "Giam dan: ";
    selectionSort(n, A, descending);
    display(n, A);

    cout << "\nInsert Sort\n";
    cout << "Tang dan: ";
    insertionSort(n, A, ascending);
    display(n, A);
    cout << "Giam dan: ";
    insertionSort(n, A, descending);
    display(n, A);

    cout << "\nBubble Sort\n";
    cout << "Tang dan: ";
    bubbleSort(n, A, ascending);
    display(n, A);
    cout << "Giam dan: ";
    bubbleSort(n, A, descending);
    display(n, A);

    cout << "\nQuick Sort\n";
    cout << "Tang dan: ";
    quickSort(A, 0, n - 1, ascending);
    display(n, A);
    cout << "Giam dan: ";
    quickSort(A, 0, n - 1, descending);
    display(n, A);

    cout <<"\nMerge Sort\n";
    cout << "Tang dan: ";
    mergeSort(A, 0, n - 1, ascending);
    display(n, A);
    cout << "Giam dan: ";
    mergeSort(A, 0, n - 1, descending);
    display(n, A);

    cout << "\nHeap Sort\n";
    cout << "Tang dan: ";
    heapSort(A, n, ascending);
    display(n, A);
    cout << "Giam dan: ";
    heapSort(A, n, descending);
    display(n, A);

    cout << "\nShell Sort\n";
    cout << "Tang dan: ";
    shellSort(A, n, ascending);
    display(n, A);
    cout << "Giam dan: ";
    shellSort(A, n, descending);
    display(n, A);

    int x;
    cout << "\nBinary Search\n";
    cout << "Mang tang dan: ";
    quickSort(A, 0, n - 1, ascending);
    display(n, A);
    cout << "Nhap so can tim: "; cin >> x;
    cout << "Ket qua: " << (binarySearch(A, n, x, ascending)? "Tim thay" : "Khong tim thay") << endl;
    cout << "Mang giam dan: ";
    quickSort(A, 0, n - 1, descending);
    display(n, A);
    cout << "Nhap so can tim: "; cin >> x;
    cout << "Ket qua: " << (binarySearch(A, n, x, descending)? "Tim thay" : "Khong tim thay") << endl;
    

    return 0;
}