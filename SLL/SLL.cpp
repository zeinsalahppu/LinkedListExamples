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


void SinglyLinkedList::addAtBeginning(int n)
{
  NodePTR x = new Node;
  x->value = n;
  x->next = m_Head;
  m_Head = x;
}


void SinglyLinkedList::addAtEnd(int n)
{
  NodePTR x = new Node;
  x->value = n;
  x->next = NULL;

  if (m_Head == NULL)
    m_Head = x;
  else
  {
    NodePTR t = m_Head;
    while (t->next != NULL)
      t = t->next;

    t->next = x;
  }
}


void SinglyLinkedList::printOut()
{
  NodePTR x = m_Head;
  cout << "\n";
  while (x != NULL)
  {
    cout << x->value << "  ";
    x = x->next;
  }
}


void main()
{
  cout << "Hello! This is an example program for studying linked lists" << endl;
  SinglyLinkedList list;

  list.addAtBeginning(5);
  list.addAtBeginning(8);
  list.addAtBeginning(12);

  list.addAtEnd(15);
  list.addAtEnd(16);
  list.addAtEnd(17);
  list.addAtEnd(18);

  list.printOut();

  system("PAUSE");
}

