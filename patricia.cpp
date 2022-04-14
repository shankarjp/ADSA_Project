#include <iostream>
using namespace std;

int maxim = 10;        

int size = 0;         
 
struct node
{
  char ch;
  int value;
  struct node *left;
  struct node *right;
  struct node *start;
};
 
struct node *head = (struct node *)malloc(sizeof(struct node));


 
struct node* chain(char str[20] , int value , int i )
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    if(str[i] != '\0')
    {
        temp->right = NULL;
        temp->left = chain(str,value,i+1);        
        temp->value = -1;
        temp->ch = str[i];
    }
    else
    {
        temp->ch = str[i];
        temp->value = value;
        temp->left = NULL;
        temp->right = NULL;
    }
    return temp;
}

void add(char str[20], int value )
{
    if(head == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        struct node *result = chain(str , value , 0 ) ;
        temp ->left = result;
        temp ->right = NULL;
        temp ->value = -1;
        temp ->ch = '-';
        head = temp;
    }
    else
    {
        if(head->left  != NULL && head->left->ch!=str[0] && head->right == NULL)
        {
            struct node *result = chain(str , value , 0 ) ;
            head->right = result;
        }
        else if (head->right != NULL && head->right->ch!=str[0] && head->left == NULL)
        {
            struct node *result = chain(str , value , 0 ) ;
            head->left = result;
        }
        else if (head->right != NULL && head->left  != NULL && head->right->ch!=str[0] && head->left->ch!= str[0])
        {
            cout<<"Only two childs per Node !!\n";
        }
        else 
        {
            struct node *temp = head;
            int i = 0;
            while(true)
            {
                if(temp->left != NULL && str[i] == temp->left->ch )
                {
                    temp = temp->left;
                    i++;
                }
                else if(temp->right != NULL &&str[i] == temp->right->ch )
                {
                    temp = temp->right;
                    i++;
                }
                else if(temp->left == NULL)
                {
                    struct node *result = chain(str , value , i ) ;
                    temp->left = result;
                    break;
                }
                else if(temp->right == NULL)
                {
                    struct node *result = chain(str , value , i ) ;
                    temp->right = result;
                    break;
                }
                else
                {
                    cout<<"Only two childs per Node !!\n";
                    break;
                }

            }
        }
    }
}

void del( char str[30] )
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *q = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    int side = 0;
    temp = head;
    q = temp;
    int flag = 0;
    while(true)
    {
        if(head->left==NULL && head->right == NULL)
        {
                 cout<<"No such Key Found !\n";
                break;
        }
        if(temp->left==NULL && temp->right == NULL && i!=0 && str[i-1] != '\0')
        {
                 cout<<"No such Key Found !\n";
                break;
        }
        if(str[i] == '\0')
        {
            flag = 1;
            break;
        }
        if( temp == NULL )
        {
            cout<<"Empty Trie !\n";
            
            return ;
        }
        if( temp->left != NULL && temp ->right != NULL )
        {
            q = temp;
            
            if( temp ->left->ch == str[i])
            {
                temp = temp->left;
                i++;
                side = 0;
            }
            else if (temp ->right->ch == str[i])
            {
                temp = temp->right;
                i++;
                side = 1;
            }
            else
            {
                 cout<<"No such Key Found !\n";
                break;
            }
        }
        else if(temp->right!=NULL && temp->left == NULL && str[i] == temp->right->ch )
        {
            temp = temp->right;
            i++;
        }
        else if(temp->right!=NULL && temp->left == NULL && str[i] != temp->right->ch )
        {
            cout<<"No such Key Found !\n";
                break;
        }
        else if(temp->left!=NULL && temp->right == NULL && str[i] == temp->left->ch )
        {
           temp = temp->left;
            i++;
        }
        else if(temp->left!=NULL && temp->right == NULL && str[i] != temp->left->ch )
        {
            cout<<"No such Key Found !\n";
            break;
        }
        
        
    }
    if(flag)
    {
        cout<<"Key "<<str<<" is being removed !\n";
        if(!side)
        q->left = NULL;
        else
        q->right = NULL;
    }
    
}

void search(char str[30])
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *q = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    int side = 0;
    temp = head;
    int flag = 0;
    while(true)
    {
        if(head->left==NULL && head->right == NULL)
        {
                 cout<<"No such Key Found !\n";
                break;
        }
        if(temp->left==NULL && temp->right == NULL && i!=0 && str[i-1] != '\0')
        {
                 cout<<"No such Key Found !\n";
                break;
        }
        else if(temp->left==NULL && temp->right == NULL && i!=0 && str[i-1] == '\0')
        {
            flag = 1;
            break;
        }
        if( temp == NULL )
        {
            cout<<"Empty Trie !\n";
            
            return ;
        }
        if( temp->left != NULL && temp ->right != NULL )
        {
            
            if( temp ->left->ch == str[i])
            {
                temp = temp->left;
                i++;
                side = 0;
            }
            else if (temp ->right->ch == str[i])
            {
                temp = temp->right;
                i++;
                side = 1;
            }
            else
            {
                 cout<<"No such Key Found !\n";
                break;
            }
        }
        else if(temp->right!=NULL && temp->left == NULL && str[i] == temp->right->ch )
        {
            temp = temp->right;
            i++;
        }
        else if(temp->right!=NULL && temp->left == NULL && str[i] != temp->right->ch )
        {
            cout<<"No such Key Found !\n";
                break;
        }
        else if(temp->left!=NULL && temp->right == NULL && str[i] == temp->left->ch )
        {
           temp = temp->left;
            i++;
        }
        else if(temp->left!=NULL && temp->right == NULL && str[i] != temp->left->ch )
        {
            cout<<"No such Key Found !\n";
            break;
        }
    }
    if(flag)
    {
        cout<<"Key "<<str<<" is Found and value is "<<temp->value<<" !\n";
    }
}

int main()
{
    head = NULL;
  int choice, key, value, n;
  char ch;
  char str[10];

  do
  {
      if(head != NULL && head->left==NULL && head->right == NULL)
        {
            struct node* temp = head;
            delete temp;
        }
      
    cout << "Implementation of Patricia Trie" << endl;
    cout << "MENU-: \n1.Insert an item in the Trie"
      "\n2.Remove an item from the Trie"
      "\n3.Search Trie"
      "\n\n Please enter your choice-:";
     
    cin >> choice;
    switch(choice)
    {
       
      case 1:
        cout << "Inserting element in Trie" << endl;
        cout << "Enter Key and value-:    ";
        cin >> str >> value;
        add(str, value);
        break;
         
      case 2:
        cout << "Deleting item from Trie\n Enter the Key to delete-:";
        cin >> str;
        del(str);
        break;
         
      case 3:
        cout << "Searching Trie \nEnter Key to Search for "<<endl;
        cin>>str;
        search(str);

        break;
      default:
        cout << "Wrong Input" << endl;
    }
    cout << "\n Do you want to continue -: (Y/N) ";
    cin >> ch;
 
  }while(ch == 'y' || ch =='Y');
  
  cout<<head->left->ch<<" "<<head->left->left->ch<<" "<<head->left->left->left->ch<<" "<<head->left->left->right->ch;
  return 0;
}