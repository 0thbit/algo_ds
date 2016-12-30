#include <iostream>

using namespace std;

class Node{
  public:
    Node* next;
    int data;
};

class linked_list{
  public:
    Node *head;
    
    linked_list(){//constructor
      this->head=NULL;
    }
    
    ~linked_list(){//destructor
      cout<<"Linked list deleted."<<endl;
    }
    
    void push_item(int d){//function to insert item in the linked list :: O(1)
      Node* node = new Node();//pointer to the node instance
      node->data=d;
      node->next=this->head;
      this->head=node;//head will point to last inserted item
    }
    
    void print_list(){
      Node *head = this->head;
      cout<<"Printing Linked list"<<endl;
      while(head!=NULL){//traversing the linked list
	cout<<head->data<<endl;
	head=head->next;
      }
    }
    
};

int main(){
  linked_list l;
  
  l.push_item(7);
  l.push_item(3);
  l.push_item(4);
  l.push_item(9);
  l.print_list();
  l.push_item(3);
  l.push_item(2);
  l.push_item(1);
  cout<<endl;
  l.print_list();
  return 0;
}
