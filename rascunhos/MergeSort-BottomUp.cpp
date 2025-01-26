#include <iostream>
#include <vector>

using namespace std;

// Função para mesclar dois subarrays ordenados
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int m = 0; m < temp.size(); m++)
        arr[left + m] = temp[m];
}

// Implementação Bottom-Up do Merge Sort
void mergeSortBottomUp(vector<int>& arr) {
    int n = arr.size();
    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

// Função principal
int main() {
    vector<int> arr = {18, 12, 17, 20, 27, 4, 9, 50, 3, 1, 304, 5, 3, 5, 6, 2, 5, 1, 0};

    cout << "Array original:\n";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSortBottomUp(arr);

    cout << "Array ordenado:\n";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
