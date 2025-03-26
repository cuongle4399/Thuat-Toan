#include<iostream>
#include<stack>
#include<queue>
#include<cctype>
using namespace std;
int giaTri(char x){
	if(x == '+' || x == '-'){
		return 1;
	}
	else if(x == '*' || x == '/'){
		return 2;
	}
	else {
		return 0;
	}
}
int main () {
	stack<char> toanTu;
	queue<string> toanHang;
	string s;
	cout << "Nhap chuoi trung to: ";
	getline(cin,s);
	for(int i = 0;i < s.length();i++){
		if(isdigit(s[i])){
			string k = string(1,s[i]);
			while(isdigit(s[i+1] && i != s.length() -1)){
				k += s[i+1];
				i++;
			}
			toanHang.push(k);
		}
		else if (s[i] == '('){
			toanTu.push(s[i]);
		}
		else if(s[i] == ')'){
			
			while(!toanTu.empty() && toanTu.top() != '('){
			toanHang.push(string(1,toanTu.top()));	
			toanTu.pop();
			}
			toanTu.pop();
		}
		else {
			while(!toanTu.empty() && giaTri(s[i]) <= giaTri(toanTu.top())){
				toanHang.push(string(1,toanTu.top()));
				toanTu.pop();
			}
			toanTu.push(s[i]);
		}
	}
	while(!toanTu.empty()){
		toanHang.push(string(1,toanTu.top()));
		toanTu.pop();
	}
	cout << "Hau to cua trung to vua nhap la: ";
	while(!toanHang.empty()){
		cout << toanHang.front() << "";
		toanHang.pop();
	}
	return 0;
}
