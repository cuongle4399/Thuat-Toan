#include<iostream>

using namespace std;

const int MAXCOLS = 105;
const int MAXROWS = 105;
void inputArr2D(int arr[][MAXCOLS], int m, int n){
	if(n > MAXCOLS || m > MAXROWS){
		cout << "loi";
		exit(1);
	}
	else {
		for(int i = 0;i < m;i++){
			for(int j = 0;j< n;j++){
				cin >> arr[i][j];
			}
		}
	}
}
void printArr2D(int arr[][MAXCOLS], int m, int n){
	cout << "ma tran da nhap:" << endl;;
	for(int i = 0 ;i < m;i++){
		for(int j = 0;j < n;j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void addArr2D(int a[][MAXCOLS], int b[][MAXCOLS], int m, int n, int c[][MAXCOLS]){
	for(int i= 0;i < m;i++){
		for(int j =0;j <n ;j++){
			c[i][j]= a[i][j]+ b[i][j];
		}
	}
	cout << endl;
}
int maxArr2D(int arr[][MAXCOLS], int m, int n, int &rowMax, int &colMax){
	rowMax = 0;
	colMax = 0;
	int max1 = arr[rowMax][colMax];
	for(int i= 0;i < m;i++){
		for(int j = 0;j < n ;j++){
			if(arr[i][j] > max1){
				max1 = arr[i][j];
				
				rowMax = i;
				colMax = j;
				cout << i <<" "<< j<< " ";
			}
		}
	}
	return max1;	
}
void multiplyArr2D(int a[][MAXCOLS], int b[][MAXCOLS], int m, int p, int n, int c[][MAXCOLS]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0; 
            for (int k = 0; k < p; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printArr2D(c,m,n);
}
int main () {
	int m, n;
	cout << "nhap so hang: ";
	cin >> m;
	cout << "nhap so cot: ";
	cin >> n;
	if(m < 0 || n < 0){
		return 0;
	}
	int a[m][MAXCOLS];
	inputArr2D(a,m,n);
	printArr2D(a, m , n);
	cout << "nhap mang b: " << endl;
	int b[MAXROWS][MAXCOLS];
	inputArr2D(b,m,n);
	
	int c[MAXROWS][MAXCOLS];
	addArr2D(a, b, m, n, c);
	printArr2D(c, m, n);
	
	int hang, cot;
	cout << "gia tri lon nhat la: "<< maxArr2D(a, m, n,hang, cot)
	<< " tai hang: " << hang << " va cot thu: "<< cot << endl;
	cout << "nhap index p: ";
	int p;
	cin >> p;
	int y[MAXROWS][MAXCOLS];
	inputArr2D(y,m,p);
	printArr2D(y, m, p);
	
	int u[MAXROWS][MAXCOLS];
	inputArr2D(u,p,n);
	printArr2D(u, p, n);
	
	int kq[MAXROWS][MAXCOLS];

	multiplyArr2D(y, u,m,p, n,kq);*/
	return 0;
}
