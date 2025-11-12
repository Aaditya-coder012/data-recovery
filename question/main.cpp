/*
Question 1
#include <bits/stdc++.h>
using namespace std;

// --------------------------- MIN HEAP CLASS ---------------------------
class MinHeap {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

public:
    // Insert a new element
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Fix heap property (up-heapify)
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Delete the root (minimum element)
    void deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }

        // Replace root with last element and remove last
        heap[0] = heap.back();
        heap.pop_back();

        // Restore heap property
        heapify(0);
    }

    // Heapify function to maintain heap property
    void heapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    // Display the heap
    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    // Return heap array for property check
    vector<int> getHeap() {
        return heap;
    }
};

// --------------------------- MAX HEAP CLASS ---------------------------
class MaxHeap {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Fix heap property (up-heapify)
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);
    }

    void heapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    vector<int> getHeap() {
        return heap;
    }
};

// --------------------------- HEAP PROPERTY CHECKS ---------------------------

// ✅ Check if an array satisfies Min-Heap property
bool isMinHeap(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] > arr[2 * i + 1]) return false;
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) return false;
    }
    return true;
}

// ✅ Check if an array satisfies Max-Heap property
bool isMaxHeap(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] < arr[2 * i + 1]) return false;
        if (2 * i + 2 < n && arr[i] < arr[2 * i + 2]) return false;
    }
    return true;
}

// --------------------------- MAIN FUNCTION ---------------------------
int main() {
    MinHeap minH;
    MaxHeap maxH;

    cout << "----- MIN HEAP OPERATIONS -----\n";
    minH.insert(30);
    minH.insert(10);
    minH.insert(50);
    minH.insert(20);
    cout << "Min Heap after insertions: ";
    minH.display();

    minH.deleteRoot();
    cout << "Min Heap after deleting root: ";
    minH.display();

    cout << "\n----- MAX HEAP OPERATIONS -----\n";
    maxH.insert(30);
    maxH.insert(10);
    maxH.insert(50);
    maxH.insert(20);
    cout << "Max Heap after insertions: ";
    maxH.display();

    maxH.deleteRoot();
    cout << "Max Heap after deleting root: ";
    maxH.display();

    // ------------------ CHECK HEAP PROPERTY ------------------
    cout << "\n----- CHECK HEAP PROPERTY -----\n";
    vector<int> arr1 = {10, 20, 30, 40, 50};
    vector<int> arr2 = {50, 30, 20, 10, 5};

    cout << "Array 1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\nIs Min-Heap? " << (isMinHeap(arr1) ? "Yes" : "No") << endl;
    cout << "Is Max-Heap? " << (isMaxHeap(arr1) ? "Yes" : "No") << endl;

    cout << "\nArray 2: ";
    for (int x : arr2) cout << x << " ";
    cout << "\nIs Min-Heap? " << (isMinHeap(arr2) ? "Yes" : "No") << endl;
    cout << "Is Max-Heap? " << (isMaxHeap(arr2) ? "Yes" : "No") << endl;

    return 0;
}

*/

/*
Question 2
#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // If left child is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is greater than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from an unsorted array
void buildMaxHeap(vector<int> &arr, int n)
{
    // Start from the last non-leaf node and heapify each
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to perform Heap Sort
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Step 1: Build max heap
    buildMaxHeap(arr, n);

    // Step 2: One by one extract elements from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal (Unsorted) Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    // Convert array into Max-Heap and sort it
    heapSort(arr);

    cout << "Array After Heap Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
*/

/*
Question 3

#include <bits/stdc++.h>
using namespace std;

// Function to find Kth smallest element
int findKthSmallest(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;  // Max-Heap

    for (int num : arr) {
        maxHeap.push(num);
        if (maxHeap.size() > k)
            maxHeap.pop(); // keep only k smallest elements
    }
    return maxHeap.top();
}

// Function to find Kth largest element
int findKthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap

    for (int num : arr) {
        minHeap.push(num);
        if (minHeap.size() > k)
            minHeap.pop(); // keep only k largest elements
    }
    return minHeap.top();
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "K = " << k << endl;

    int kthSmallest = findKthSmallest(arr, k);
    int kthLargest = findKthLargest(arr, k);

    cout << "Kth Smallest Element: " << kthSmallest << endl;
    cout << "Kth Largest Element: " << kthLargest << endl;

    return 0;
}

*/
