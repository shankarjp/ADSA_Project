#include <iostream>
using namespace std;

int maxim = 10;        

int size = 0;         
 
struct node
{
  int key;
  int value;
  struct node *left;
  struct node *right;
};

struct binarytree
{
  struct node *head; 
};
 
struct binarytree *arr; // array of trees 
 
void insert_element(struct node *tree, struct node *item);
 
struct node* find(struct node *tree, int key);
 
struct node* remove_element(struct node *tree, int key);
 
void display_tree(struct node *tree); 

int HASHING( int key )
{
  return ( key % maxim );
}
 
void add(int key, int value)
{
  int index = HASHING(key);

  struct node *tree = (struct node*) arr[index].head; // obtain binary tree at specific index of array

  struct node *new_node = (struct node*) malloc(sizeof(struct node));
 
  new_node->key = key;
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
 
  if (tree == NULL)   // binary tree at index has not been created yet 
  {
    cout << "Inserting " << key << " and " << value << endl;
    arr[index].head = new_node;
    size++;
  }
 
  else
  {
 
    struct node *temp = find(tree, key); //returns address of node containing key if present 
 
    if (temp == NULL)  //key is not present in tree 
    {
      cout << "Inserting " << key << "and" << value << endl;
 
      insert_element(tree, new_node);
      size++;
    }
 
    else // key is present , updating value 
    {
      temp->value = value;
    }
  }
}

struct node* find(struct node *tree, int key)   // performing bst
{
  if (tree == NULL)
  {
    return NULL;
  }
  if (tree->key == key)
  {
    return tree;
  }
  else if (key < tree->key)
  {
    return find(tree->left, key);
  }
  else
  {
    return find(tree->right, key);
  }
}
 

void insert_element(struct node *tree, struct node *val)
{
 
  if (val->key < tree->key)
  {
    if (tree->left == NULL)
    {
      tree->left = val;
      return;
    }
    else
    {
      insert_element(tree->left, val);
      return;
    }
  }
 
  else if (val->key > tree->key)
  {
    if (tree->right == NULL)
    {
      tree->right = val;
      return;
    }
    else
    {
      insert_element(tree->right, val);
      return;
    }
  }
}
void preorder(struct node *tree) // performing a preorder traversal 
{
 
  if (tree == NULL)
  {
    return;
  }
 
  cout << tree->key << " and " << tree->value << "   ";
 
  if (tree->left != NULL)
  {
    preorder(tree->left);
  }
   
  if (tree->right != NULL)
  {
    preorder(tree->right);
  }
}
 

void disp()
{
  int i = 0;
  for(i = 0; i < maxim; i++)
  {
    struct node *tree = arr[i].head;
    if (tree == NULL)  // no binary tree at that index
    {
      cout << "arr[ " << i << " ] has no elements" << endl;
    }
    else              // binary tree present
    {
      cout << "arr[ " << i << " ] has elements    : ";
      preorder(tree);
      cout<<"\n";
    }
  }
} 

void del(int key)  // removing a key
{
  int index = HASHING(key);
  struct node *tree = (struct node*)arr[index].head;
  if (tree == NULL)
  {
    cout << key << " Key not present" << endl;
  }
 
  else
  {
    struct node *temp = find(tree, key);
    if (temp == NULL) 
    {
      cout << key << " is not present";
    }
    else
    {
      tree = remove_element(tree, key);
      cout << key << " has been removed form the hash tree" << endl;
    }
  }
}
 
struct node* remove_element(struct node *tree,  int key)
{
 
  if (tree == NULL)
  {
    return NULL;
  }
 
  if (key < tree->key)
  {
    tree->left = remove_element(tree->left, key);
    return tree;
  }
 
  else if (key > tree->key)
  {
    tree->right = remove_element(tree->right, key);
    return tree;
  }
 
  else
  {
     
    /* reached the node */
    if (tree->left == NULL  &&  tree->right == NULL)
    {
      size--;
      return tree->left;
    }
 
    else if (tree->left != NULL  &&  tree->right == NULL)
    {
      size--;
      return tree->left;
    }
     
    else if (tree->left == NULL  &&  tree->right != NULL)
    {
      size--;
      return tree->right;
    }
 
    else
    {
      struct node *left_one = tree->left;
      while (left_one->right != NULL)
      {
        left_one = left_one->right;   // finding its inorder predecessor 
      }
 
      tree->key = left_one->key;
      tree->value = left_one->value;
      tree->left = remove_element(tree->left, tree->key);
      return tree;
    }
  }
}
 

int main()
{
  int choice, key, value, n;
  char ch;
  arr = (struct binarytree*) malloc( maxim * sizeof(struct binarytree*));
  int i = 0;
  for(i = 0; i < maxim; i++)
  {
    arr[i].head = NULL;
  }
  do
  {
    cout << "Implementation of Hash Tree" << endl;
    cout << "MENU-: \n1.Insert an item in the Hash Tree"
      "\n2.Remove an item from the Hash Tree"
      "\n3.Check the size of Hash Tree"
      "\n4.Display Hash Tree"
      "\n\n Please enter your choice-:";
     
    cin >> choice;
    switch(choice)
    {
       
      case 1:
        cout << "Inserting element in Hash Tree" << endl;
        cout << "Enter key and value-:    ";
        cin >> key >> value;
        add(key, value);
        break;
         
      case 2:
        cout << "Deleting item from Hash Tree \n Enter the key to delete-:";
        cin >> key;
        del(key);
        break;
         
      case 3:
        cout << "Size of Hash Tree is-:" << size << endl;
        break;
         
      case 4:
        disp();
        break;
         
      default:
        cout << "Wrong Input" << endl;
    }
    cout << "\n Do you want to continue -: (Y/N) ";
    cin >> ch;
 
  }while(ch == 'y' || ch =='Y');
  return 0;
}
