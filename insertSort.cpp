#include<iostream>
#include <type_traits>

void insertSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		for (int j = i; j > 0 && arr[j-1] > arr[j]; j--) {
			std::swap(arr[j], arr[j-1]);
		}
	}
}

int main() {
	int arr[5] = {5,9,2,8,0};
	insertSort(arr, 5);
	for (int i = 0; i < 5; i++) {
  	std::cout<<arr[i]<<" ";
	}
}

