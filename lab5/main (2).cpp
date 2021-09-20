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
node* insertNode(node * head,int num) // To insert Node in Proper Position
{
    node * temp = new node();
    temp->data = num;
    temp->next = NULL;
    if(head==NULL)//Inserting beginning Node
    {
        head = temp;
        return head;
    }
    else if(head->data>num)//Inserting in beginning if number is smaller
    {
        temp->next = head;
        head=temp;
        return head;
    }
    else// Inserting in the last or within list
    {
        node *save = head;
        for(save=head;save->next!=NULL;save=save->next)
        {
            if(save->next->data >num)
            {
                node * tem = save->next;
                save->next = temp;
                temp->next = tem;
                return head;
            }
        }
        save->next=temp;
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
 node* operator+(node &Head1, node &Head2)
{
    node * head1=&Head1;
    node * head2=&Head2;
    int i=0;
node * temp=head2;
    while(head2!=NULL)
    {
        i=temp->data;
        head2=(head2)->deleteNode(head2,1);
        head1=(head1)->insertNode(head1,i);
    }
    return head1;
 }
 
 

int main()
{
    node * head1=NULL;
    node * head2=NULL;
    node * head3=NULL;
    int c=0;
    int i=0;    

    while(1)
    {
        cout<<"1.Insert\n2.Delete\n3.Display\n4.Merge\n5.Exit\n";
        cin>>c;
        switch(c)
        {
            case 1:
            
                cout<<"1.First List\n2.Second List\n";
                cin>>c;
                if(c==1) 
                {
                    cout<<"Enter Number: \n";
                    cin>>c;
                    head1=head1->insertNode(head1,c);
                }
                else if(c==2) 
                {
                    cout<<"Enter Number: \n";
                    cin>>c;
                    head2=head2->insertNode(head2,c);
                }
                else
                {
                    cout<<"Invalid input.\n";
                }
                break;
            
            case 2: 
            
                cout<<"1.First List\n2.Second List\n";
                cin>>c;
                if(c==1) 
                {
                    cout<<"Enter Position: \n";
                    cin>>c;
                    head1=head1->deleteNode(head1,c);
                }
                else if(c==2) 
                {
                    cout<<"Enter Position: \n";
                    cin>>c;
                    head2=head2->deleteNode(head2,c);
                }
                else
                {
                    cout<<"Invalid input.\n";
                }
                break; 
            
            case 3: 
            
                 cout<<"1.First List\n2.Second List\n";
                cin>>c;
                if(c==1) 
                {
                    head1->display(head1);
                }
                else if(c==2) 
                {
                    head2->display(head2);
                }
                else
                {
                    cout<<"Invalid input.\n";
                }
                break;
            
            case 4: 
            head1= *head1+*head2;
            head2=NULL;
                break;
            
            case 5:
            
                exit(1);
                break;
            
            default:
            
                cout<<"Invalid Input.\n";
            


            
        }
    } 

    return 0;
}


