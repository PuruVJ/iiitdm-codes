// Keshav Saraf Cs20b1062
#include<iostream>
using namespace std;
class node
{//Creating a Node class
public:
int data;
node * next;
public:
node()
{
    data = 0;
    next = NULL;
}
node* insertNode(node * head,int num) // To insert Node in end
{
    node * temp = new node();
    temp->data = num;
    temp->next = NULL;
    if(head==NULL)//Inserting beginning Node
    {
        head = temp;
        return head;
    }
    else
    {
        node *save = head;
        for(save=head;save->next!=NULL;save=save->next);
        save->next=temp;
        return head;
    }
}
node* insertNode(node * head,int num,int k) // To insert Node in kth Position
{
    if(k<1)
    {
        cout<<"Please Enter a valid Position.\n";
        return head;
    }
    node * temp = new node();
    temp->data = num;
    temp->next = NULL;
    if(head==NULL && k==1)//Inserting beginning Node
    {
        head = temp;
        return head;
    }
    else if(head==NULL && k!=1)
    {
      cout<<"List is not that large.\n";  
    }
    else if(head!=NULL && k==1)//inserting at 1st Position
    {
        temp->next=head;
        return temp;
    }
    else// Inserting in the last or within list
    {
        int i;
        node *save = head;
        for(save=head,i=2;save->next!=NULL && i<k;i++,save=save->next);
        if(i<=k-1)
        cout<<"List is not that large.\n";
        else
        {
            temp->next=save->next;
            save->next=temp;    
        }
        
        return head;
    }
}

node*  deleteNode(node *head,int k)//Deleting the Node
{
    if(head==NULL)
    {
        cout<<"List is Empty.\n";
        return head;
    } 

    else if(head->next==NULL)//Deleting the only element present
    {
        if(k==1)
        {
            head=NULL;
            return head;
        }
        else
        {
            cout<<"The node is not in the list.\n";
            return head;
        }
    } 
    else if(k==1)// Deleting the first element
    {
        head=head->next;
        return head;
    }
    else// Deleting at specific kth position
    {
        node * save = head;
        node * delNode=NULL;
        int i=1;
        while(head->next!=NULL && i<=k)
        {
        
            if(i==k-1)
            delNode=head;
            head = head->next;
            i++;
            

        }
        if(i<k)// position is out of list
        {
            cout<<"The node is not in the list.\n";
        }
        else
        {
    
            delNode->next=delNode->next->next;
        }
        return save;
    } 
}

node*  deleteNode(node *head)//Deleting the last Node
{
    if(head==NULL)
    {
        cout<<"List is Empty.\n";
        return head;
    }
    else if(head->next==NULL)//if list has only 1 element.
    return NULL;
    else
    {
        node * save;
        for(save=head;save->next->next!=NULL ;save=save->next);
        save->next=NULL;
        return head;
    }
    
     
}



void display(node * head)// Displaying elements
{
    cout<<"The list is: ";
    if(head==NULL)
        cout<<"Empty.\n";
    for(node * save=head; save!=NULL; save=save->next)
    {
        cout<<save->data<<" ";
    }
    cout<<"\n";
}
 
};

int main()
{
    node * head1=NULL;
    int c=0,i=0;

    while(1)
    {
        cout<<"1.Insert\n2.Insert at End\n3.Delete\n4.Delete at End\n5.Display\n6.Exit\n";
        cin>>c;
        switch(c)
        {
            case 1:
                    
                    cout<<"Enter Number: \n";
                    cin>>c;
                    cout<<"Enter Position:\n";
                    cin>>i;
                    head1=head1->insertNode(head1,c,i);
                    break;
             case 2:
            
                    cout<<"Enter Number: \n";
                    cin>>c;
                    head1=head1->insertNode(head1,c);
                    break;
            case 3:
                    cout<<"Enter Position: \n";
                    cin>>c;
                    head1=head1->deleteNode(head1,c);
                    break; 
            
            case 4:
                    head1=head1->deleteNode(head1);
                    break;
            
            case 5: 
                head1->display(head1);
                break;
            case 6:
            
                exit(1);
                break;
            
            default:
            
                cout<<"Invalid Input.\n";
            


            
        }
    } 

    return 0;
}


