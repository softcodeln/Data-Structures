//
// Created by HP on 14-Mar-18.
//


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