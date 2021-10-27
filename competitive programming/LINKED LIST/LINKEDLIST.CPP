#include <iostream>
using namespace std;
#include "node.cpp" 
class Pair{
    public :
    node *head;
    node *tail ;
};

Pair reverseLL_2(node *head){
     if (head ==NULL || head->next == NULL){
         Pair ans;
         ans.head =head;
         ans.tail =head;
         return ans;
     }

     Pair smallAns = reverseLL_2(head->next);

     smallAns.tail->next =head;
     head->next =NULL;
     Pair ans;
     ans.head=smallAns.head;
     ans.tail=head;
     return ans;
}

node* reverseLL_Better(node *head){
    return reverseLL_2(head).head;
}

/*------------creating a node (taking input)---------*/
node *takeinput(){
    int data ;
    cin>>data;

    node *head = NULL;
    while(data != -1){
        node *newnode = new node(data);
        if(head == NULL){
            head = newnode;
        }
        else{
            node *temp=head;
            while(temp->next != NULL){
            temp = temp->next;
        }
        temp ->next = newnode;
        }
            cin>>data;
    }
        return head ;

}

/*-----------taking input------------*/

node *takeinput_better(){
    int data;
    cin>>data;

    node *head =NULL;
    node *tail =NULL;
    while(data != -1){
        node *newnode = new node(data);
        if(head == NULL){
            head =newnode;
            tail =newnode;
        }
        else{
            tail->next = newnode;
            tail = tail -> next;
            //or
            // tail = newnode;
        }
        cin >> data;
    } 
    return head;
}

/*------**** INSERTING  A NODE ------******/

node* insertnode(node *head ,int i ,int data){
    node *newnode = new node(data);
    int count =0;
    node*temp = head;

    if(i==0){
        newnode->next=head;
        head = newnode;
        return head;
    }
    while( temp != NULL && count < i-1){
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
    node *a = temp -> next;
    temp->next = newnode;
    newnode ->next=a;
    }
    return head;
}

/*------inserting node recursively------*/

node* Rinsertnode(node *head ,int i,int data){
    if (head==NULL);
    return NULL;
    
    if(i==0){
        node *temp = new node(data);
        temp->next=head;
        return temp;
    }
    if(i==1){
        node *temp = new node (data);
        temp ->next =head->next ;
        head ->next =temp;
        return head;
    }
    {
    node* curr = insertnode (head->next ,i-1,data);
    }
    return head;
}

/*------ Deleting a node --------*/

node* deletenode(node** head ,int key){
    node *temp = *head ,*newnode;

    if(temp != NULL && temp->data == key){
    *head = temp->next;
    free(temp);
    
}
while(temp!=NULL && temp->data != key){
    newnode= temp;
    temp =temp->next;
}
if(temp==NULL){
    newnode->next =temp->next; 
}
delete (temp);
}

/*-----------middle element ---------*/

void middlelement(node *head){
    node *slow =head;
    node *fast =head->next;
    
    if(head != NULL){
        while(fast != NULL && fast -> next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        cout<<"middle element is "<< slow->data <<endl;
    }
}

/*-----------MERGING TWO SORTED ELEMENT-----------*/

node* sortedmerge(node *a ,node*b){
    node*result = NULL;
    if(a==NULL){
        return (b) ;
    }
    else {
        return (a);
    }

    if(a->data <= b->data){
        result = a;
        result->next = sortedmerge(a->next ,b);
    }
    else{
        result = b;
        result ->next =sortedmerge(a,b->next);
    }
    return (result);
}
 
/*------------****displayong a linked list****______*/

void print(node *head){
    // node *temp = head;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    // temp=head;
    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
}

/*--------reversing linked list using recursion ----------*/

node* ReverseLL(node *head){
    if(head == NULL || head->next == NULL) {
        return head;
    }
    node *smallans = ReverseLL(head->next);
    node *temp =smallans;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next =head;
    head->next=NULL;
    return smallans;
}
node* ReverseLL_3(node *head){
    if(head == NULL || head->next == NULL) {
        return head;
    }
    node *smallans = ReverseLL_3(head->next);

   node *tail = head ->next;
    tail->next =head;
    head->next=NULL;
    return smallans;
}

 
int main(){


    node *head = takeinput_better();
    print (head); 
    
//    int i ,data;
//    cin>>i>>data;
//    head = insertnode(head,i,data);
//    print(head);
   
   int i;
   cin>>i;
   head==deletenode(&head,i);
   print (head); 

   /* RECURSIVELY */

  /* int pos ,data;
   cin>>pos>>data;

   head=Rinsertnode(head,pos,data) ;
   print(head); */ 
//    middlelement(head);

  


   

    /* //statically 
    node n1(1); 
    node *head=&n1;
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);

    n1.next =&n2;
    n2.next =&n3;
    n3.next =&n4;
    n4.next =&n5;

    print(head);

    // n1.next= &n2;

    // cout<<n1.data<<" "<<n2.data<<endl;
    // // cout<<head->data<<endl;

    // // dynamically

    // node*n3=new node(10);
    // node *head=n3;

    // node*n4=new node(15);
    // n3->next=n4;
    */

    


    return 0;
}
