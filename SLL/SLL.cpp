#include <iostream>

using namespace std;


class SinglyLinkedList
{
  public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void addAtBeginning(int n);
    void addAtEnd(int n);
    void insertIntoSortedList(int n);
    void readAndCreate(bool sorted = false);
    void printOut();
    bool isSorted();
    int getSize();

  private:
    struct Node
    {
      int  value;
      Node *next;
    };

    typedef Node *NodePTR;

  NodePTR m_Head;
};


SinglyLinkedList::SinglyLinkedList()
{
  m_Head = NULL;
}


SinglyLinkedList::~SinglyLinkedList()
{

}



void main()
{
  cout << "Hello! This is an example program for studying linked lists" << endl;
  SinglyLinkedList list;

 

  system("PAUSE");
}

