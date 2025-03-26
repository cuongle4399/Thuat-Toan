#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    double gpa;
};

void inputStudent(struct Student &s)
{
    cout << "Name: "; getline(cin, s.name);
    cout << "Age: "; cin >> s.age;
    cout << "GPA: "; cin >> s.gpa;
}

void printStudent(struct Student s)
{
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "GPA: " << s.gpa << endl;
}

void inputListOfStudent(struct Student list[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        fflush(stdin);
        inputStudent(list[i]);
    }
}

void printListOfStudent(struct Student list[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printStudent(list[i]);
}
void listOfGoodStudents(struct Student list[], int n)
{
	for(int i = 0;i< n;i++){
		if(list[i].gpa >= 8){
			cout << list[i].name << endl;
		}
	}
}
int appendStudent(struct Student list[], int n, struct Student s)
{
list[n] = s;
return n+ 1;	
}
int countFirstName(struct Student list[], int n)
{
	int count = 0;
	string s = "nguyen";
	for(int i = 0;i < n;i++){
		string ss = list[i].name.substr(0, 6);
		if(ss == s){
			count++;
		}
	}
	return count;
}
string convertName(string name){
	int index = 0;
	for(char i = 0;i < name.length();i++){
		if(name[i] == ' '){
			index = i;
		}
	}
	if(index == 0){
		return name;
	}
	string HoDem = name.substr(0,index);
	string name1 = name.substr(index +1, name.length());
	string result = name1 + ' '+ HoDem;
	return result;
}
void printCoverName(Student list[], int n){
	for(int i = 0;i < n;i++){
		cout << convertName(list[i].name)<< endl;
	}
}
void sortVNName(struct Student list[], int n){
	cout << "Danh sach duoc sap xep: "<< endl;
	for(int i = 0;i < n-1;i++){
		for(int j = i +1 ;j < n;j++){
			if(convertName(list[i].name) > convertName(list[j].name)){
				Student tempt = list[i];
				list[i] = list[j];
				list[j] = tempt;
			}
		}
	}
	for(int i = 0;i < n;i++){
		cout << list[i].name<< endl;
	}
}
int main()
{
    struct Student m[100];
    string name;
    int k;
    inputListOfStudent(m, 2);
    listOfGoodStudents(m,2);
    Student s;
    cout << appendStudent(m,2,s) << endl;
    listOfGoodStudents(m,2);
    printCoverName(m,2);
    fflush(stdin);
    sortVNName(m,2);
}

