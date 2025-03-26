#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void inputArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap so thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

void outputArr(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

float avgArr(int a[], int n){
	float tong = 0;
	for(int i = 0;i< n;i++){
		tong += a[i];
	}
	return tong /n;
}
bool findArr(int a[], int n, int x){
	sort(a,a+n);
	int l = 0;
	int r = n -1;
	while (l <= r){
		int m = (l + r) /2;
		if(a[m] == x){
			return true;
		}
		else if (a[m] > x){
			r = m-1;
		}
		else {
			l = m+1;
		}
	}
	return false;
}
void sortArr(int a[], int n){
	for(int i = 0 ;i < n -1;i++){
		for(int j = i + 1;j < n;j++){
			if(a[i] > a[j]){
				int temp;
				temp = a[i];
				a[i]= a[j];
				a[j] = temp;
			}
		}
	}
}
void mergeArr(int a[], int n, int b[], int m, int c[]){
	sortArr(a,n);
    sortArr(b,m);
    int i = 0,k = 0,j = 0;
    while(i < n && j < m){
    	if(a[i] <= b[j]){
    		c[k] = a[i];
    		k++;
    		i++;
		}
		else {
			c[k] = b[j];
			k++;
			j++;
			
		}
	}
	while(i < n){
		c[k] = a[i]; 
		i++;
		k++;
	}
	while(j < m){
		c[k] = b[j];
		j++;
		k++;
	}
		
}
void countArr(int a[], int n, vector<int> b,vector<int> d){
	b.push_back(a[0]);
	bool ktra = false;
	for(int i = 1;i < n;i ++){
     	for(int j = 0 ;j < b.size();j++){
			if(a[i] == b[j]){
				ktra = true;
			}
		}
		if(ktra){
			ktra = false;
		}
		else {
			b.push_back(a[i]);
		}
	}
	cout << "cac gia tri co trong mang" << endl;
	for(int i =0;i < b.size();i++){
		cout << b[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < b.size();i++){
		int count = 0;
		sort(a, a + n);
		for(int j = 0;j < n;j++){
			if(a[j] == b[i]){
				count++;
			}
		}
		d.push_back(count);
	}
	cout << "so luong phan tu cua tung gia tri trong mang:" << endl;
	for(int i =0;i < d.size();i++){
		cout << d[i] << " ";
	}
	cout << endl;
}
int main() {
    const int size = 5;
    int x[size];

    inputArr(x, size);
    
    cout << "Mang da nhap: ";
    outputArr(x, size);
    cout << "trung binh cua mang: "<< avgArr(x, size) << endl;
    int a;
    cout << "nhap gia tri muon tim trong mang: ";
	cin >> a;
	if(findArr(x,size,a)){
		cout << a << " co ton tai trong mang" << endl;
	}
	else {
		cout << "khong tim thay gia tri nay trong mang" << endl;
	}
	sortArr(x,size);
	cout << "mang da duoc sap xep lai: " << endl;
	outputArr(x, size);
	cout <<"nhap so phan tu mang"<< endl;
	int m;
	cin >> m;
	int b[m];
	inputArr(b, m);
	int c[size+m];
	mergeArr(x,size,b,m,c);
	outputArr(c,size+m);
	vector<int> k;
	vector<int> h;
	countArr(x,size,h, k);
	outputArr(x,h.size());
	outputArr(x,k.size());
    return 0;
    
}

