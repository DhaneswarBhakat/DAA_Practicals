#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
    vector<int> arr;

    void insert(int value) {
        arr.push_back(value);
        int index = arr.size() - 1;
        int parentIndex = (index - 1) / 2;

        while (index > 0 && arr[parentIndex] < value) {
            arr[index] = arr[parentIndex];
            index = parentIndex;
            parentIndex = (parentIndex - 1) / 2;
        }
        arr[index] = value;
    }

    void printHeap() {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    while (true) {
        cout << "1. Insert Node in Heap ";
        cout << "2. Print Heap ";
        cout << "3. Exit" << endl;
        cout << "Enter your choice ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int node;
            cout << "Enter a value : ";
            cin >> node;
            h.insert(node);
        } else if (choice == 2) {
            h.printHeap();
        } else {
            break;
        }
    }

    return 0;
}
