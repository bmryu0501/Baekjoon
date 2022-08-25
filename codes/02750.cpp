#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {
    int tmp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = i+1; j < size; j++) {
            if(arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main() {
    int N, arr[1000];

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, N);

    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
}