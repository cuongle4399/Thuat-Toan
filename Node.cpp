#include<iostream>
#include<cmath>
using namespace std;
struct Node{
	int heSo;
	int mu;
	Node* next;
};
Node* makeNode(int heSo, int mu){
	Node* nodeNew = new Node;
	nodeNew->heSo = heSo;
	nodeNew->mu = mu;
	nodeNew->next = NULL;
	return nodeNew;
}
Node* themMotToanHangDau(Node* &node, int heSo, int mu){
	Node* newNode = makeNode(heSo,mu);
	newNode->next = node;
	node = newNode;
	return node;
}
void printNode(Node* node){
	int i = 0;
	while(node != NULL){
		if(node->heSo > 0 && i == 0){
			cout << node->heSo;
		}
		else if(node->heSo > 0){
			cout << "+ " << node->heSo;
		}
		else {
			cout << "-" << abs(node->heSo);
		}
		cout << "x^" << node->mu;
		node = node->next;
		i++;
	}
	cout << endl;
}
int soSanhNode(Node * node1, Node* node2){
	if(node1->mu > node2->mu){
		return 0;
	}
	else if(node1->mu < node2->mu){
		return 1;
	}
	else {
		return 2;
	}
}
double tinhXDaThuc(Node* head, double x){

	double result = 0;
	while(head != NULL){
		result += head->heSo * pow(x,head->mu);
		head = head->next;
	}
	return result;
}
Node* congHaiDaThuc(Node * node1, Node* node2){
	Node* result = NULL;
	if(node1 == NULL){
		return node2;
	}
	else if(node2 == NULL){
		return node1;
	}
	else {
		while(node1 != NULL){
			if(soSanhNode(node1,node2) == 0){
			if(result == NULL){
				result == node1;
			}
			else {
				result->next = node1;
			}
			node1= node1->next;
		}
		else if(soSanhNode(node1,node2) == 1){
			if(result == NULL){
				result = node2;
			}
			else {
				result->next = node2;
			}
			node2= node2->next;
		}
		else {
			if(result == NULL){
				
				result = makeNode(node1->heSo + node2->heSo,node1->mu);
			}
			else {
				result->next = makeNode(node1->heSo + node2->heSo,node1->mu);
			}
			node1= node1->next;
			node2= node2->next;
		}
		}
		while(node2 != NULL){
			result->next = node2;
			node2 = node2->next;
		}
		return result;
		
	}
}
Node* tinhDaoHam(Node* node){
	if(node == NULL){
		return NULL;
	}
	Node* result = NULL;
	Node* tmp = NULL;
	Node* last = new Node;
	int i= 0;
	while(node!= NULL && node->mu == 0 ){
		node = node->next;	
	}	
	while(node != NULL){
		
		Node* last = new Node;
		last->heSo = node->heSo*node->mu;
		last->mu = node->mu -1;
		last->next = NULL;
		
		if(result == NULL){
			result = last;
			tmp = last;
		}
		else {
			tmp->next = last;
			tmp = tmp->next;
		}	
        node = node->next; 
	}	

	return result;
}
Node* nhanHaiDaThuc(Node* node1, Node* node2) {
	Node* nodeResult = NULL;
	Node* nodeTmp = NULL;
	Node* nodeReset = node2;
	while(node1 != NULL){
		node2 = nodeReset;
		while(node2 != NULL){
			Node* nodeNew = new Node;
			nodeNew->heSo = node1->heSo * node2->heSo;
			nodeNew->mu = node1->mu + node2->mu;
			nodeNew->next = NULL;
			
			if(nodeResult == NULL){
				nodeResult = nodeNew;
				nodeTmp = nodeNew;
			}
			else {
				nodeTmp->next = nodeNew;
				nodeTmp = nodeTmp->next;
			}
			node2 = node2->next;
		}
		
		node1 = node1->next;
	}
	return nodeResult;
}
Node* rutGonDaThuc(Node* node1){
	Node* result = NULL;
	Node* result2 = NULL;
	if(node1 == NULL){
		return NULL;
	}
	while(node1 != NULL){
		int tong = 0;
		int muDau = node1->mu;
		// cong cac node cung mu
			while(node1 != NULL &&muDau == node1->mu){
			tong += node1->heSo;
			node1 = node1->next;
		   }
		
		   Node* nodeNew = new Node;
		   nodeNew->heSo = tong;
		   nodeNew->mu = muDau;
		   nodeNew->next= NULL;
		   
		   if(result == NULL){
		   	result = nodeNew;
		   	result2 = nodeNew;
		   }
		   else {
		   	result2->next = nodeNew;
		   	result2 = result2->next;
		   }
	}
	return result;
}
int main (){
	Node* node1 = NULL;
	node1 = makeNode(2, 2);
	Node* node2 = NULL;
	node2 = makeNode(4, 3);
	themMotToanHangDau(node1,1,3);
	themMotToanHangDau(node1,2,3);
	themMotToanHangDau(node1,1,4);
	cout << "in da thuc: " << endl;
	printNode(node1);
	cout << "in da thuc: " << endl;
	printNode(node2);
	//cout << "tinh da thuc voi x bang 1 : " << tinhXDaThuc(node1,1) << endl;
	//Node* node2 = NULL;
	//node2 = makeNode(2, 3);
	//printNode(node2);
	//Node* node3 = congHaiDaThuc(node1, node2);
	//printNode(node3);
	//Node* node4 = tinhDaoHam(node1);
	//cout << "dao ham duoc tinh la : " <<endl;
//	printNode(node4);
	Node* node5 = nhanHaiDaThuc(node1,node2);
	cout << "Nhan hai da thuc: "<< endl;
	printNode(node5);
	Node* node6 = rutGonDaThuc(node5);
	cout << "rut gon da thuc da thuc: "<< endl;
	printNode(node6);
	return 0;
}
