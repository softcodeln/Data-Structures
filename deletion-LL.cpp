//
// Created by HP on 27-Jan-18.
//
//
// Created by HP on 25-Jan-18.
//

#include <iostream>
using namespace std;
struct node
{
    int info ;
    struct node *link ;
}*start , *loc ;

void createlist(int data) ;
void display() ;
void delete_first();
void delete_last();
struct node* search_loc(int );
void delete_loc( struct node * );
int main(void)
{
    int i , data , n ,ch;
    start = NULL ;
    cout << "--> Enter the number of nodes\n" ;
    cin >> n ;
    for(i = 1 ; i <= n ; i++)
    {
        cout << "--> Enter data to node "<< i <<"\n" ;
        cin >> data ;
        createlist(data) ;
    }
    cout << "--> list is is given below\n" ;
    display() ;
    label:
    if( start != NULL ) {
        cout << "## enter 1 to delete header node\n";
        cout << "## enter 2 to delete last node\n";
        cout << "## enter 3 to delete a node at given location\n";
        cout << "## enter any other key to exit\n";
    }

   else
       cout << "## list is empty , so enter number greater then 4 to Quit the program\n" ;

    cin >> ch ;
    switch(ch){
        case 1:
            delete_first();
            goto label;
        case 2:
            delete_last();
            goto label;
        case 3:
            cout << "\nenter data you want to delete at given location\n" ;
            cin >> data ;
            loc = search_loc( data );

            delete_loc( loc );

            goto label;
        default:
            return 0;
    }
}

void delete_last()
{
    struct node *ptr;
    if(start == NULL)
      cout << "underflow condition\n";
    else {
        ptr = start;
        while (ptr->link->link != NULL)
            ptr = ptr->link;
        ptr->link = NULL;
        cout << "--> list after deletion of last node\n " ;
        display();
    }
}

struct node* search_loc( int data ){
    struct node *ptr ;
    if(start == NULL)
    {    cout << "list is empty \n" ;  return start; }
   else {
        ptr = start;
        while ( ptr != NULL && ptr->info != data )
            ptr = ptr->link;
           if( ptr != NULL )
             return ptr;
        if( ptr == NULL )
            return ptr ;
    }
}

void delete_loc(struct node *loc ){
        struct node *ptr ;

    if( start == loc )
        start = start -> link ;

    else if( loc == NULL)
        cout << "element  not found\n";
    else if ( start != loc && loc != NULL )
    {
        ptr = start;
        while (ptr->link != loc)
            ptr = ptr->link;
        ptr->link = ptr->link->link;
    }
    cout <<"--> list after deletion\n";
    display();
}

void delete_first(){
    struct node *ptr;
    if(start == NULL)
        cout << "underflow condition\n" ;

    ptr = start -> link;
    start = ptr ;
    cout <<"--> list after deletion at head\n";
    display();
}

void createlist(int data)
{
    struct node *temp , *q ;
    temp = new(struct node) ;
    temp -> info = data ;
    temp -> link = NULL ;
    if(start == NULL)
    {
        start = temp ;
    }
    else
    {
        q = start ;
        while(q -> link != NULL)
        {
            q = q -> link ;
        }
        q -> link = temp ;
    }
}

void display()
{
    struct node *q ;
    if(start == NULL)
    {
        cout << "List is empty!!!! \n" ;
    }
    q = start ;
    while(q != NULL)
    {
        cout << q -> info << " ";
        q = q -> link ;
    }
    cout << "\n" ;
}