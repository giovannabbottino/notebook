/*Giovanna Borges Bottino giovannabbottino@gmail.com*/
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int l, int r, int d);
  
int main()
{
    int n;
    scanf(" %d", &n);

    int id;
    int *arr = (int*) malloc( n * sizeof(int));
    for(int i= 0; i < n; i++){
        scanf("%d", &id);
        arr[i] = id;
    }

    int d;
    scanf(" %d", &d);

    int result = binarySearch(arr, 0, n - 1, d);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);
    return 0;
}

int binarySearch(int arr[], int l, int r, int d){
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == d)
            return mid;

        if (arr[mid] > d)
            return binarySearch(arr, l, mid - 1, d);
  
        return binarySearch(arr, mid + 1, r, d);
    }
    return -1;
}
  