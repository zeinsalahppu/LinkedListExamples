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


void SinglyLinkedList::readAndCreate(bool sorted)
{
  int val;

  cin >> val;
  while (val != 0)
  {
    if (sorted)
      insertIntoSortedList(val);
    else
      addAtEnd(val);

    cin >> val;
  }
}


void SinglyLinkedList::insertIntoSortedList(int val)
{
  NodePTR x = new Node;
  x->value = val;

  if (m_Head == NULL || val <= m_Head->value) // add before head
  {
    x->next = m_Head;
    m_Head = x;
  }
  else  // insert at the correct position after head
  {
    NodePTR t = m_Head;
    while ((t->next != NULL) && (t->next->value <= val))
      t = t->next;

    x->next = t->next;
    t->next = x;
  }
}


int SinglyLinkedList::getSize()
{
  int i = 0;
  NodePTR x = m_Head;
  while (x != NULL)
  {
    x = x->next;
    i++;
  }
  return i;
}


bool SinglyLinkedList::isSorted()
{
  if (m_Head == NULL)
    return true;
  else
  {
    NodePTR a = m_Head;
    NodePTR b = m_Head->next;
    while (b != NULL && b->value >= a->value)
    {
      a = a->next;
      b = b->next;
    }

    if (b == NULL)
      return true;
    else
      return false;
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
  cout << "\n" << list.getSize() << "\n";

  cout << "Sorted: " << list.isSorted() << "\n";

  SinglyLinkedList list2;

  list2.readAndCreate(true);
  list2.printOut();
  cout << "\n" << list2.getSize() << "\n";
  cout << "Sorted: " << list2.isSorted() << "\n";


  
  system("PAUSE");
}

