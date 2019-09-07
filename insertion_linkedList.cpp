//
// Created by lucky on 25-Jan-18.
//

#include <iostream>
using namespace std;

struct node
{
    int info ;
    struct node *link ;
}*start  ;

void createlist( int data ) ;
void display() ;
void insertFirst( int );
void insertEnd( int );
void insert_Before_node( int  , int );
void insert_After_node( int , int );

int main(void)
{
    int i , data1 , data2 , n ;
    start = NULL ;
    cout << "--> Enter the number of nodes\n" ;
    cin >> n ;
    for(i = 1 ; i <= n ; i++ )
    {
        cout << "--> Enter data to node "<< i <<"\n" ;
        cin >> data1 ;
        createlist( data1 ) ;
    }
    cout << "--> we have below given list\n";
    display() ;
    label:
              cout << "## enter 1 to insert a node at begin\n";
              cout << "## enter 2 to insert a node at end\n";
              cout << "## enter 3 to insert a node at after given location\n";
              cout << "## enter 4 to insert a node at before given location\n";
              cout << "## enter any other key to quite the program\n" ;
    cin >> n ;
    switch( n ){
        case 1:
            cout << "==> enter data you want to insert at begin\n " ;
            cin >> data2 ;
            insertFirst( data2 );
            goto label;
        case 2:
            cout << "==> enter data you want to insert at end\n" ;
            cin >> data2 ;
            insertEnd( data2 );
            goto label;
        case 3:
            cout << "==> enter data after which you want to insert a node\n" ;
            cin >> data1 ;
            cout << "==> enter data which you want to insert after "<< data1 <<"\n " ;
            cin >> data2 ;
            insert_After_node(data1 , data2 );
            goto label;
        case 4:
            cout << "==> enter data before which you want to insert a node\n" ;
            cin >> data1 ;
            cout << "==> enter data which you want to insert\n " ;
            cin >> data2 ;
            insert_Before_node( data1 , data2 );
            goto label;
        default:
            cout << "BYE BYE , program is end\n" ;
            return 0;
    }
}

void  insert_After_node( int data1 ,int data2 ){
    struct node *temp , *ptr ;
    temp = new( struct node ) ;
    temp -> info = data2 ;
    temp -> link = NULL ;
    if( start == NULL )
     cout << "--> list is empty , so element can't insert \n " ;

    else {
        ptr = start;
        while (ptr->info != data1)
            ptr = ptr->link;
        temp->link = ptr->link;
        ptr->link = temp;
    }
    cout << "-->list when insertion is done , after a given location \n " ;
    display();
}


void insert_Before_node( int data1 ,int data2 ){
        struct node *temp , *ptr ;
        temp = new( struct node ) ;
        temp -> info = data2 ;
        temp -> link = NULL ;
        if( start == NULL )
        { cout << "--> list is empty , so element can't insert \n " ; }
    else {
        ptr = start;
        while (ptr -> link -> info != data1)
            ptr = ptr -> link;
        temp -> link = ptr -> link ;
        ptr -> link = temp;
    }
    cout << "--> list when insertion is done , before a given location \n " ;
    display() ;
}


void insertFirst(int data2){
    struct node *temp;
    temp = new(struct node) ;
    temp -> info = data2;
    temp -> link = start;
    start = temp;
    cout << "--> list when insertion is done , at begin \n " ;
    display();
}

void insertEnd( int data2 ){
    struct node *temp , * ptr ;

    temp = new( struct node ) ;
    temp -> info = data2 ;
    temp -> link = NULL ;

    if( start == NULL )
        start = temp ;

    else{
       ptr = start ;
        while ( ptr -> link != NULL )
            ptr = ptr -> link ;
        ptr -> link = temp ;
    }cout << "--> list when insertion is done , at end \n " ;
    display() ;
}

void createlist(int data2)
{
    struct node *temp , *q ;
    temp = new(struct node) ;
    temp -> info = data2 ;
    temp -> link = NULL ;
    if(start == NULL )
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
        cout << "List is empty \n" ;
    }
    q = start ;
    while(q != NULL)
    {
        cout << q -> info <<" ";
        q = q -> link ;
    }
    cout << "\n" ;
}