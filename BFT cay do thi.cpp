#include<iostream>
#include<cmath>
using namespace std;
struct Person {
	string name;
	int yearOfBirth;
};
struct BFT{
	Person Data;
	BFT *left, *right;
};
BFT *createNode(Person nguoi, BFT *left, BFT *right){
	BFT *b1 = new BFT;
	b1->Data = nguoi;
	b1->left = left;
	b1->right = right;
	return b1;
}
BFT *createBFT(){
	BFT *n1, *n2,*n3,*n4,*n5,*n6;
	n1 = createNode({"Nguyen Van F", 1970}, NULL,NULL);
	n2 = createNode({"Nguyen Van E", 1965}, NULL,NULL);
	n3 = createNode({"Nguyen Van D", 1960}, NULL,NULL);
	n4 = createNode({"Nguyen Van C", 1930}, n2,n1);
	n5 = createNode({"Nguyen Van B", 1935}, NULL,n3);
	n6 = createNode({"Nguyen Van A", 1900}, n4,n5);
	return n6;
}
void in(BFT *b1){
	if(b1 != NULL){
		cout << b1->Data.name << " " << b1->Data.yearOfBirth<< endl;
		in(b1->left);
		in(b1->right);
	}
}
int countPeopleInTree(BFT *b1){
	if(b1 != NULL){
		return 1+ countPeopleInTree(b1->left) + countPeopleInTree(b1->right);
	}
	return 0;
}
int generation(BFT *b1){
	if(b1!= NULL){
		return 1 + max(generation(b1->left), generation(b1->right));
	}
	else {
		return 0;
	}
}
int countPeopleYearOfBirthBeforeX(BFT *b1, int x){
	if(b1 != NULL){
		if(b1->Data.yearOfBirth <= x){
			return 1+ countPeopleYearOfBirthBeforeX(b1->left,x) + countPeopleYearOfBirthBeforeX(b1->right,x);
		}
		else {
			return 0;
		}
	}
	return 0;
}
BFT *findPeopleWithNameX(BFT *b1, string x){
	if(b1 != NULL){
	  if(b1->Data.name == x){
		 return b1;
	    }
	    BFT* left = findPeopleWithNameX(b1->left,x);
	    if(left != NULL){
	    	return left;
		}
		return findPeopleWithNameX(b1->right,x);
	}
	return NULL;
}
bool checkChild(BFT *b1, string x, string y){
	BFT *b2 = findPeopleWithNameX(b1,x);
	if(b2 == NULL){
		return false;
	}
	if(b2->left->Data.name == y || b2->right->Data.name == y){
		return true;
	}
	else {
		return false;
	}
}
int generationOFX(BFT *b1, BFT *b2){
	if(b1 != NULL){
		if(b1 == b2){
			return 0;
		}
		else {
			return 1 + max(generationOFX(b1->left,b2) , generationOFX(b1->right,b2));
		}
	}
	return 0;
}
BFT *checckOffspring(BFT *b1, string y){
	if(b1 != NULL){
		if(b1->Data.name == y){
			return b1;
		}
		BFT *left = checckOffspring(b1->left,y);
		if(left != NULL){
			return left;
		}
		return checckOffspring(b1->right,y);
	}
	return NULL;
}
void ListOfspring(BFT *b1){
	if(b1 != NULL){
		in(b1->left);
		in(b1->right);
	}	
}
void setPerson(BFT* root, string x, Person p)
{
	if(root != NULL){
		if(root->Data.name == x){
			root->Data = p;
			return;	
		}
		setPerson(root->left,x,p);
		setPerson(root->right,x,p);
	}

}
bool isSibling(BFT* root, string x, string y){
	if(root != NULL){
		if(root->left != NULL && root->right != NULL){
			if((root->left->Data.name == x && y == root->right->Data.name)
			||(root->left->Data.name == y && x == root->right->Data.name)){
				return true;
			}
		}
		if(isSibling(root->left,x,y)){
			return true;
		}
		return isSibling(root->right,x,y);
	}
	return false;
}

int levelOfPerson(BFT* root, string name){
	if(root == NULL) return 0;

	if(root->Data.name == name){
		return 1;
	}

	int left = levelOfPerson(root->left, name);
	if(left != 0){
		return left + 1;
	}

	int right = levelOfPerson(root->right, name); 
	if(right != 0){
		return right + 1;
	}

	return 0;
}


int main (){
	BFT *Family = createBFT();
	in(Family);
	cout << "so nguoi trong cay: " << countPeopleInTree(Family)<< endl;
	cout << "so the he cua cay: "<< generation(Family) <<endl;
	cout << "so nguoi co nam sinh truoc x: "<< countPeopleYearOfBirthBeforeX(Family,1930) <<endl;
	if(findPeopleWithNameX(Family,"Nguyen Van A") != NULL){
		cout <<"Da tim thay: "<<findPeopleWithNameX(Family,"Nguyen Van A")->Data.name << " " <<
		findPeopleWithNameX(Family,"Nguyen Van A")->Data.yearOfBirth <<endl;
	}
	else {
		cout <<"Khong ton tai nguoi can tim" << endl;
	}
	if(checkChild(Family,"Nguyen Van C","Nguyen Van E")){
		cout << "E là con cua C"<< endl;
	}
	else {
		cout << "E khong phai con" << endl;
	}
	BFT *peopleX = findPeopleWithNameX(Family,"Nguyen Van B");
	cout << "The he cua Nguyen Van B la: " << generationOFX(Family, peopleX)<< endl;
	BFT *k1 = findPeopleWithNameX(Family,"Nguyen Van A");
	if(checckOffspring(k1,"Nguyen Van D") != NULL){
		cout << "D la con hoac chau cua A" <<endl;
	}
	else {
		cout << "D khong phai la con hoac chau cua A" <<endl;
	}
	cout << "tat ca con chau cua Nguyen Van B"<< endl;
	BFT *peoplex = findPeopleWithNameX(Family,"Nguyen Van B");
	ListOfspring(peoplex);
	cout << "Thay the nguoi trong gia pha " << endl;
	setPerson(Family,"Nguyen Van B", {"dai ca Cuong",2018});
	in(Family);
	cout << "kiem tra xem Nguyen Van B va Nguyen van C co la anh em khong" << endl;
	if(isSibling(Family,"Nguyen Van C","Nguyen Van B")){
		cout << "co ho la ae voi nhau" << endl;
	}
	else {
		cout << "ho khong phai la ae voi nhau" <<endl;
	}
	cout << "the he cua Nguyen Van A: " <<levelOfPerson(Family,"Nguyen Van A") << endl;
	return 0;
}
