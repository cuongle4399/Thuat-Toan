#include <bits/stdc++.h>
#define nullptr NULL
using namespace std;
struct Node{
    int index;
    int value;
    Node* next;
};
void printSpareVector(Node* head)
{
    while (head != nullptr)
    {
        cout << "Index: " << head->index  << " value: " << head->value << endl;
        head = head->next;
    }
}
void insertFirst(Node* &head, int index, int value)
{
    Node* newNode = new Node;
    newNode->index = index;
    newNode->value = value;
    newNode->next = nullptr;
    head = newNode;
}
// insert v? trí cu?i cùng - hàm tr? v? node cu?i cùng
Node* insertLast(Node *p,int index, int value)
{
    Node* newNode = new Node;
    newNode->index = index;
    newNode->value = value;
    newNode->next = nullptr;
    if (p != nullptr) // loai tru th phan tu dau
        p->next = newNode;
    return newNode;
}
// Chuy?n m?t vector thành vector thua
Node* convertSparseVector(vector<int> a)
{
    Node* result = nullptr;
    Node* last = nullptr;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
            last = insertLast(last, i, a[i]);
        if (result == nullptr && last != nullptr)
            result = last;
    }
    return result;
}
// C?ng hai véc to
Node* sumOfSVector(Node* a, Node* b)
{
    Node* result = nullptr;
    Node* last = nullptr;
    while (a != nullptr && b != nullptr)
    {
        if (a->index > b->index)
        {
            last = insertLast(last, b->index, b->value);
            b = b->next;
        }
        else if (a->index < b->index)
        {
            last = insertLast(last, a->index, a->value);
            a = a->next;
        }
        else
        {
            if (a->value + b->value != 0)
                last = insertLast(last, a->index, a->value + b->value);
            a = a->next;
            b = b->next;
        }
        if (result == nullptr)
            result = last;
    }
    return result;

}
// Nhân m?t s? v?i m?t véc to
void multiNumOfVector(Node* head, int x)
{
    while (head != nullptr)
    {
        
        head->value = head->value * x;
        head = head->next;
    }
}
//Tích vô hu?ng c?a hai véc to

int multiVector (Node* a, Node* b)
{
    int result = 0;
    while (a != nullptr && b != nullptr)
    {
        if (a->index > b->index)
        {
            b = b->next;
        }
        else if (a->index < b->index)
        {
            a = a->next;
        }
        else
        {
            result += a->value * b->value;
            a = a->next;
            b = b->next;
        }

    }
    return result;
}
//Tính mô dun c?a m?t véc to
double moduleOfVector(Node *head)
{
    int sum = 0;
    while (head != nullptr)
    {
        sum += head->value * head->value;
        head = head->next;
    }
    return sqrt(sum);
}
// Chuy?n t? m?t vector thua thành vector
vector<int> convertToVector(Node *head)
{
    int lastIndex = 0;
    vector<int> result;
    if (head->index != 0)
        result.push_back(0);
    while (head != nullptr)
    {
        for (int i = 1; i <= (head->index -1) - lastIndex  ; i++)
        {
            result.push_back(0);
        }
        result.push_back(head->value);
        lastIndex = head->index;
        head = head->next;
    
    }
    return result;
}
int main()
{
    vector<int> a{0, 0, 0, 2, 0, 5};
    vector<int> b{0, 1, 0, -2, 9, 10};
    Node* sv_a = convertSparseVector(a);
    Node* sv_b = convertSparseVector(b);
    printSpareVector(sumOfSVector(sv_a, sv_b));
    cout << "Tich vo huong a va b la:" << multiVector(sv_a, sv_b) << endl;
    cout << "Module vector a la:" << moduleOfVector(sv_a) << endl;
    for (int x: convertToVector(sv_a))*
    {
        cout << x << " ";
    }
}
