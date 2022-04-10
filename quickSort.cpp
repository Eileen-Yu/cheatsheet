#include<iostream>

// low is the lowest index
// high is the highest index, not length

int partition(int arr[], int low, int high) {
	int pivot = arr[low];
	int pivotIdx = low;
	for ( int j = low + 1; j <= high; j++ ) {
		if( arr[j] < pivot ) {
			low += 1;
			std::swap(arr[low], arr[j]);
		}
	}
	std::swap(arr[pivotIdx], arr[low]);

	return low;
}

void quickSort(int arr[], int low, int high) {
	if ( low < high ) {
		int middle = partition(arr, low, high);
		quickSort(arr, low, middle - 1);
		quickSort(arr, middle + 1, high);  // ‘middle’ is already in its place
	}
}


int main() {
  int arr[10] = {-99,7,4,2,66,1000,0,-32,1,100};
	quickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		std::cout<<arr[i]<<" ";
	}
}
