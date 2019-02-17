#include <iostream>

using namespace std;

class Node
{
public:
    Node(const int v) :
        next(nullptr),
        value(v)
    {}
    ~Node()
    {
        if (next)
        {
            delete next;
        }
    }

    Node* next;
    int value;
};

class List
{
public:
    List();
    ~List();
    void add(Node* node);        // dodaje element na koniec listy
    Node* get(const int value);  // zwraca element o wskazanej wartości

private:
    Node* first;
};

List::List() :
    first(nullptr)
{}
List::~List()
{
    if(first)
    {
        delete first;
    }
}
void List::add(Node* node)
{
    if(!first)
    {
        first = node;
    }
    else
    {
        Node* current = first;
        while(current->next)
        {
            current = current->next;
        }
        current->next = node;
    }
}

Node* List::get(const int value)
{
    if(!first)
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    else
    {
        Node* current = first;
        do
        {
            if(current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->next;
            }
        } while(current);
        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

int main()
{
    List lista;
    Node* node4 = new Node(4);
    Node* node7 = new Node(7);
    Node* node1 = new Node(1);
    Node* node3 = new Node(3);
    Node* node5 = new Node(5);


    lista.add(node4);
    lista.add(new Node(2));
    lista.add(node7);
    lista.add(node1);
    lista.add(node3);
    lista.add(node5);
    lista.add(new Node(9));
    auto node = lista.get(1);

    return 0;
}

