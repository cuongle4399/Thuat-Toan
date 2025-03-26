#include<iostream>

using namespace std;

int *inputDynamicArr(int n){
	int *arr = new int[n];
	int x;
	cout << "nhap gia tri cac phan tu: "<< endl;
	for(int i = 0;i < n;i++){
		cin >> x;
        arr[i] = x;
	}
	return arr;
}
void printDynamicArr(int *arr, int n){
	for(int i = 0;i < n;i++){
		cout << arr[i] << " ";
	}
}
void appendDynamicArr(int *arr, int &n, int x){
	int *newArr = new int[n+1];
	for(int i = 0; i< n;i++){
		newArr[i] = arr[i];
	}
	newArr[n] = x;
	printDynamicArr(newArr, n+1);
	delete[] arr;
}
int main () {
	int n;
	cout << "nhap so phan tu mang: ";
	cin >> n;
	int *a = inputDynamicArr(n);
	cout << "con tro dau tien cua mang: " <<a<< endl;
	cout << "nhap x: " << endl;
	int x;
	cin >> x;
	appendDynamicArr(a, n, x);
	delete[] a;
	return 0;
}
