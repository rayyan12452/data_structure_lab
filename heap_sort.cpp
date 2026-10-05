#include <iostream>
using namespace std;

class HeapSort {
private:
    int arr[100];
    int n;

    
    void heapify(int size, int i) {

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        
        if (left < size && arr[left] > arr[largest])
            largest = left;

        
        if (right < size && arr[right] > arr[largest])
            largest = right;

        
        if (largest != i) {

            swap(arr[i], arr[largest]);

            
            heapify(size, largest);
        }
    }

public:

    
    HeapSort() {
        n = 0;
    }

    
    void createArray() {

        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter " << n << " elements:\n";

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Array created successfully.\n";
    }

    
    void display() {

        if (n == 0) {
            cout << "Array is empty.\n";
            return;
        }

        cout << "Array: ";

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    
    void heapSort() {

        if (n == 0) {
            cout << "Array is empty.\n";
            return;
        }

        
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(n, i);
        }

        
        for (int i = n - 1; i > 0; i--) {

            
            swap(arr[0], arr[i]);

            
            heapify(i, 0);
        }

        cout << "Array sorted successfully using Heap Sort.\n";
    }
};


int main() {

    HeapSort heap;

    int choice;

    do {

        cout << "\n========== HEAP SORT MENU ==========\n";
        cout << "1. Create Array\n";
        cout << "2. Display Array\n";
        cout << "3. Heap Sort\n";
        cout << "4. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            heap.createArray();
            break;

        case 2:
            heap.display();
            break;

        case 3:
            heap.heapSort();
            break;

        case 4:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}