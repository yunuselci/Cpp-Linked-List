#include <iostream>
using namespace std;


class Node{
public:
    Node(const int& data = 0,Node* next = NULL) : data(data),next(next){} // Kurucu Metod
    int data; // Veri
    Node* next; // Verinin adresi
};


class list{
    Node* root; // İlk Elemanımız
    Node* tail;
    Node* findPrev (Node *pos){
        Node* tmp = root;
        Node* stop = end();
        while(tmp != stop && tmp->next != pos)
            tmp = tmp -> next;
        return tmp;
    }
public:
    list() {
        root = new Node();
        tail = root;
        tail -> next = new Node();
    }

    ~list(){
        delete tail->next;
        delete tail;
    }

    Node* begin()const { return root->next; } // ilk elemanımızın adresi

    Node* end()const { return tail->next; } // son elemanızın adresini NULL tutuyoruz

    bool isEmpty()const { return begin () == end(); }

    Node* find(const int& value)const{
        Node *tmp = begin();
        Node* stop = end();
        while(tmp != stop && tmp->data != value)
            tmp = tmp->next;
        return tmp;
    }

    int size()const{ // O(n)
        int counter = 0;
        Node* tmp = begin();
        while(tmp!=end()){
            tmp = tmp->next;
            counter++;
        }
        return counter;
    }

    void push_front(const int& value){
        insert(begin(),value);
    }
    void push_back(const int& value){
        insert(end(),value);
    }

    void insert(Node *pos,const int& value){
        if(pos == end()){
            tail -> next = new Node (value,end());
            tail = tail -> next;
        }else{
            Node* tmp = findPrev(pos);
            if(tmp == end())
                cout << "Verdigin pozisyon listenin elemani degil";
            tmp ->next = new Node (value,tmp->next);
        }
    }

    void erase(Node* pos){
        if(isEmpty())
            cout << "Liste Bos oldugu icin silme islemi gerceklestirilemedi." << endl;
        Node* prev = root;
        if (pos == end() || pos == tail){
            pos = tail;
            prev = findPrev(pos);
            prev->next = pos->next;
            tail = prev;
        }
        else{
            prev = findPrev(pos);
            if(pos == end())
                cout << "Verdiginiz pozisyon listede olmadıgı icin isleminizi gerceklestiremedik" << endl;
            prev->next = pos->next;
        }
        delete pos;
    }

    void pop_front(){
        erase(begin());
    }

    void pop_back(){
        erase(end());
    }

    int front()const{ // listedeki ilk elamanın değeri
        if(isEmpty())
            cout << "Liste Bos Oldugu Icin ilk Elemanini Cagiramassiniz.!" << endl;
        return begin()->data;
    }

    int back()const{ // listedeki son elamanın değeri
        if(isEmpty())
            cout << "Liste Bos Oldugu Icin Son Elemanini Cagiramassiniz.!" << endl;
        return tail->data;
    }
    void print(){
        Node* tmp = begin();
        while(tmp != end()){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main() {
        return 0;
}