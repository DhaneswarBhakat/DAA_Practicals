#include <iostream>
using namespace std;

void MERGE(int A[], int low, int mid, int high) {
    int h = low, i = low, j = mid + 1;
    int B[high + 1];

    while (h <= mid && j <= high) {
        if (A[h] <= A[j]) {
            B[i] = A[h];
            h++;
        } else {
            B[i] = A[j];
            j++;
        }
        i++;
    }

    if (h > mid) {
        for (int k = j; k <= high; k++) {
            B[i] = A[k];
            i++;
        }
    } else {
        for (int k = h; k <= mid; k++) {
            B[i] = A[k];
            i++;
        }
    }

    for (int k = low; k <= high; k++) {
        A[k] = B[k];
    }
}

void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        MERGE(A, low, mid, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    MergeSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
