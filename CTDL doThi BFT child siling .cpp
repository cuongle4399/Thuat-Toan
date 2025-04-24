#include <iostream>
#include <fstream>
using namespace std;

struct Word {
    string english;
    string vietnamese;
};

struct EngVietDict {
    Word data;
    EngVietDict *left;
    EngVietDict *right;
};
void insertWord(EngVietDict *&root, Word data) {
	if(root == NULL){
		root = new EngVietDict();
		root->data = data;
		root->left = NULL;
		root ->right = NULL;
	}
	else if (data.english > root->data.english){
		insertWord(root->right,data);
	}
	else if(data.english < root->data.english){
		insertWord(root->left,data);
	}
}
void inTuDien(EngVietDict *root){
	if(root != NULL){
		cout << root->data.english << ": " << root->data.vietnamese << endl;
		inTuDien(root->left);
		inTuDien(root->right);
	}
}
void readDictFromFile(EngVietDict *&root, string fileName) {
	ifstream openFile(fileName);
	string line;
	if(!openFile){
		cout << "file khong ton tai";
		return;
	}
	while(getline(openFile, line)){
		int index = line.find(':');
		string eng = line.substr(0,index);
		string vn = line.substr(index+1);
		insertWord(root,{eng,vn});
	}
	openFile.close();
}
string findVNofEng(EngVietDict *root, string English){
	if(root == NULL){
		return "";
	}
	if(root->data.english == English){
		return root->data.vietnamese;
	}
	if(English > root->data.english){
		return findVNofEng(root->right, English);
	}
	else if (English < root->data.english){
		return findVNofEng(root->left, English);
	}
}
EngVietDict *findEnlishMin(EngVietDict *root){
	if(root == NULL){
		return root;
	}
	else {
		return findEnlishMin(root->left);
	}
}
void xoa(EngVietDict *&root, string English){
	if(root != NULL){
		if(English == root->data.english){
			if(root->left != NULL && root->right == NULL){
				root = root->left;
			}
			else if(root->right != NULL && root->left == NULL){
				root = root->right;
			}
			else {
				EngVietDict *minRight = findEnlishMin(root->right);
				root->data.english = minRight->data.english;
				xoa(root->right,English);
			}
		}
		else if(English > root->data.english){
			xoa(root->right, English);
		}
		else if(English < root->data.english){
			xoa(root->left, English);
		}
	}
}
void printWorkH(EngVietDict *root){
	if(root != NULL){
		if("h" == root->data.english.substr(0,1)){
			cout << root->data.english << ": " << root->data.vietnamese << endl;
		}
		printWorkH(root->left);
		printWorkH(root->right);
	}
}
void ghiFile(EngVietDict* root, ofstream& outFile){
		if(root != NULL){
		outFile << root->data.english <<": " << root->data.vietnamese << endl;
		ghiFile(root->left,outFile);
		ghiFile(root->right,outFile);
	}
}
void saveDictToFile(EngVietDict* root, string fileName){
	ofstream outFile(fileName);
	if(!outFile){
		cout << "loi mo file";
	}
	if(root != NULL){
		outFile << root->data.english <<": " << root->data.vietnamese << endl;
		ghiFile(root->left,outFile);
		ghiFile(root->right,outFile);
	}
	cout << "ghi xok file";
}
int countAfterAWord(EngVietDict* root, string word){
	if(root != NULL){
		if(root->data.english <= word){
			return 1 + countAfterAWord(root->left,word) + countAfterAWord(root->right,word);
		}
		else {
			return countAfterAWord(root->left,word) + countAfterAWord(root->right,word);
		}
	}
	return 0;
}

int main() {
	EngVietDict *a = NULL;
	insertWord (a,{"english","Tieng Anh"});
	insertWord (a,{"hi","xin chao"});
	readDictFromFile(a,"TuDien.txt");
	inTuDien(a);
	if(findVNofEng(a,"hi").length() == 0){
		cout << "khong ton tai trong tu dien" << endl;
	}
	else {
		cout  << findVNofEng(a,"hi") << endl;
	}
	printWorkH(a);
	cout << "co so tu sau tu xin chao la: " << countAfterAWord(a,"xin chao") << endl;
	saveDictToFile(a,"cuongdz.txt");
    return 0;
}







