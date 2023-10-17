#include <iostream>

using namespace std;
class node{
    public:
    int data;
    node* next;
    //constructor
    node(int data ){
        this->data = data;
        this->next=NULL;
    }
    //for deleting memory we need to call distructor
    ~node(){
        int value=this->data;
        //memeory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
            
        }
        cout<<"memeory is free for node with data"<<value <<endl;
    }
};
void insertattail(node * &tail , int d){
    node *temp=new node(d);
    tail->next=temp;
    tail=temp;
}
void insertathead(node* &head , int d){
    // new node
    node *temp=new node(d);
    temp->next=head;
    head=temp;
}
void insertatposition(node * &head,node * &tail,int position, int d){
    //insert at start postion;
    if(position ==1){
        insertathead(head , d);
        return;
    }
// for triversing to any position
    node *temp=head;
    int count=1;
    while(count <position-1){
        temp=temp->next;
        count++;
    }
    //inserting at tail
    if(temp->next == NULL){
        insertattail(tail,d);
        return;
    }
    // create node for d;
    node *toinsert= new node(d);
    toinsert->next=temp->next;
    //change of pointing type
    temp->next=toinsert;
}
void deletenode(int position ,node * &head ){
    //deleting start node
    if(position==1){
        node *temp=head;
        head=head->next;
        //memeory free;
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        node *current=head;
        node*previous=NULL;
        int count=1;
        while(count<position){
            previous=current;
            current=current->next;
            count++;
        }
        previous->next=current->next;
        current->next=NULL;
        delete current;
        
    }
}
void print(node * &head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        // temp ko aage bada do
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    //dynamic memeory allocation
    //create node
    node *node1=new node(10);
  //  cout<< node1->data<<endl;
    //cout<<node1->next<<endl;
    
    // head point to node 1
    node* head=node1;
    //tail point to node 1
    node *tail=node1;
    //before inserting
    print(head);
    insertattail(tail,12);
     //after  inserting
    print(head);
    //after  inserting
insertattail(tail,15);
print(head);

// insert at position-1
insertatposition(head,tail,4,56);
print(head);
cout<<head->data<<endl;
cout<<tail->data<<endl;
deletenode(3,head);
print(head);
//checking that the tail and haed pointer are at right position or not
cout<<head->data<<endl;
cout<<tail->data<<endl;

    return 0;
}
