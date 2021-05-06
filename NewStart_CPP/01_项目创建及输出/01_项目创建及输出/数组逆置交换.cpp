#include <iostream>

using namespace std;

//int main() {
//	int arr1[5] = {2, 4, 8, 1, 7};
//	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
//		cout << arr1[i];
//	}
//	cout << endl;
//
//	int num = sizeof(arr1) / sizeof(arr1[0]);
//	cout << "num:" << num << endl;
//	int start = 0;
//	int end = num - 1;
//	for (int i = 0; i < num/2; i++) {
//		int tmp = 0;
//		tmp = arr1[start];
//		arr1[start] = arr1[end];
//		arr1[end] = tmp;
//		start++;
//		end--;
//	}
//
//	for (int i = 0; i < num; i++) {
//		cout << arr1[i];
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}