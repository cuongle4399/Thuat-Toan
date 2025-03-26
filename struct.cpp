#include <iostream>
#include <vector>

using namespace std;

#define max1 100

struct Customer {
    string name;
    string address;
    vector<string> phoneNumbers;
};

struct ListOfCustomers {
    Customer arrCustomers[max1];
    int numOfCustomers;
};

void outputCustomer(Customer c)
{
int i;
cout << "Name: " << c.name << endl;
cout << "Address: " << c.address << endl;
cout << "List of phones: " ;
for (i = 0; i < c.phoneNumbers.size(); i++)
cout << c.phoneNumbers[i] << " ";
cout << endl;
}
void inputCustomer(Customer &c) {
    int i, n;
    string phone;
    fflush(stdin);
    cout << "Name: "; getline(cin, c.name);
    cout << "Address: "; getline(cin, c.address);
    cout << "Num of phones: "; cin >> n;
    fflush(stdin);
    for (i = 0; i < n; i++) {
        cout << "Phone number " << i << " : "; 
        getline(cin, phone);
        c.phoneNumbers.push_back(phone);
    }
}

void inputListOfCustomers(ListOfCustomers& list) {
    cout << "Number of customers: "; 
    cin >> list.numOfCustomers;
    for (int i = 0; i < list.numOfCustomers; i++)
        inputCustomer(list.arrCustomers[i]);
}

void outputListOfCustomers(ListOfCustomers list)
{
cout << "Number of customers: " << list.numOfCustomers << endl;
for(int i = 0; i < list.numOfCustomers; i++)
outputCustomer(list.arrCustomers[i]);
}

void insertCustomer(ListOfCustomers& list, Customer customer, int index) {
    if (index < 0 || index > list.numOfCustomers) {
        cout << "Invalid index. Please enter a valid index between 0 and " 
             << list.numOfCustomers << endl;
        return;
    }
    if (list.numOfCustomers == max1) {
        cout << "Cannot insert customer. List is full." << endl;
        return;
    }
    for (int i = list.numOfCustomers; i > index; i--)
        list.arrCustomers[i] = list.arrCustomers[i - 1];
    list.arrCustomers[index] = customer;
    list.numOfCustomers++;
    cout << "Successfully inserted customer at index " << index << endl;
}

void deleteCustomer(ListOfCustomers& list, int index) {
    if (index < 0 || index >= list.numOfCustomers) {
        cout << "Invalid index. Please enter a valid index between 0 and " 
             << list.numOfCustomers - 1 << endl;
        return;
    }
    for (int i = index; i < list.numOfCustomers - 1; i++)
        list.arrCustomers[i] = list.arrCustomers[i + 1];
    list.numOfCustomers--;
    cout << "Successfully deleted customer at index " << index << endl;
}

int findCustomerByName(ListOfCustomers& list, string name) {
    for (int i = 0; i < list.numOfCustomers; i++) {
        if (list.arrCustomers[i].name == name) {
            return i;
        }
    }
    cout << "No customer found with name: " << name << endl;
    return -1;
}
void deleteCustomerByName(ListOfCustomers &list, string name){
for(int i = 0;i < list.numOfCustomers;i++){
    if(list.arrCustomers[i].name == name){
	for(int j = i;j < list.numOfCustomers;j++){
		list.arrCustomers[j] = list.arrCustomers[j+ 1];
	}
   }	
  }
  list.numOfCustomers--;
}
int findCustomerByPhone(ListOfCustomers list, string phone){
	for(int i = 0;i < list.numOfCustomers;i++){
		for(int j = 0;j < list.arrCustomers[i].phoneNumbers.size();j++){
			if(list.arrCustomers[i].phoneNumbers[j] == phone){
				return 1;
			}
		}
	}
	return 0;
}
void deletePhone(ListOfCustomers &list, string phone){
	for(int i = 0;i < list.numOfCustomers; i++){
		for(int j = 0;j < list.arrCustomers[i].phoneNumbers.size();j++){
			if(list.arrCustomers[i].phoneNumbers[j] == phone){
				for(int k = j;k < list.arrCustomers[i].phoneNumbers.size();k++){
					list.arrCustomers[i].phoneNumbers[k] = list.arrCustomers[i].phoneNumbers[k+1];
				}
			}
		}
	}
}
void appendPhone(ListOfCustomers &list, string name, string phone){
	for(int i = 0;i < list.numOfCustomers;i++){
		if(list.arrCustomers[i].name == name){
			for(int j = 0;j < list.arrCustomers[i].phoneNumbers.size();j++){
				list.arrCustomers[i].phoneNumbers.push_back(phone);
			}
		}
	}
}
void mergeCustomer(ListOfCustomers &list, Customer c){
	for(int i = 0;i < list.numOfCustomers;i++){
		if(list.arrCustomers[i].name == c.name && list.arrCustomers[i].address == c.address){
			for(int j = 0 ;i < list.arrCustomers[i].phoneNumbers.size();j++){
				for(int k = 0;k < c.phoneNumbers.size();k++){
					if(list.arrCustomers[i].phoneNumbers[i] != c.phoneNumbers[k]){
						list.arrCustomers[i].phoneNumbers.push_back(c.phoneNumbers[i]);
					}
				}
			}
		}
		else {
			list.arrCustomers[list.numOfCustomers] = c;
		}
	}
}
int main() {
    Customer c;
    ListOfCustomers l;
    string name;
    int k;
    inputListOfCustomers(l);
    outputListOfCustomers(l);

    inputCustomer(c);
    cout << "Index for insert: "; 
    cin >> k;
    insertCustomer(l, c, k);
    outputListOfCustomers(l);

    cout << "Name of customer: "; 
    cin.ignore();
    getline(cin, name);
    k = findCustomerByName(l, name);
    if (k == -1)
        cout << "Not found the customer name: " << name;
    else {
        cout << "Found a customer: ";
        outputCustomer(l.arrCustomers[k]);
    }

    cout << "Index for delete: "; 
    cin >> k;
    deleteCustomer(l, k);
    outputListOfCustomers(l);
    deleteCustomerByName(l,"nam");
    findCustomerByPhone(l,"01010122222");
    deletePhone(l,"0218812");
    appendPhone(l,"cuong","2919");
    mergeCustomer(l,c);
    return 0;
}

