#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid; // Found
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; 
}
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1; 

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearchRecursive(arr, low, mid - 1, target);
    else
        return binarySearchRecursive(arr, mid + 1, high, target);
}

int main() {
    int arr[] = {3, 7, 15, 18, 21, 29, 34, 40, 42, 57};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 21;
    int result1 = binarySearchIterative(arr, size, target);
    if (result1 != -1)
        cout << "Iterative: Found at index " << result1 << endl;
    else
        cout << "Iterative: Not found\n";
        
    int result2 = binarySearchRecursive(arr, 0, size - 1, target);
    if (result2 != -1)
        cout << "Recursive: Found at index " << result2 << endl;
    else
        cout << "Recursive: Not found\n";

    return 0;
}
