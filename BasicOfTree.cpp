#include<iostream>
using namespace std;
struct tree
{
    int data;
    tree *parent, *left, *right;
};
tree* create_node(int value)
{
    tree* temp = new tree{value, nullptr, nullptr};
    return temp;
}
void add_left(tree* parent, tree* child)
{
    parent->left = child;
}
void add_right(tree* parent, tree* child)
{
    parent->right = child;
}
tree* create_tree()
{
    tree *root = create_node(1), *two = create_node(2), *three = create_node(3);
    add_left(root, two);
    add_right(root, three);
    return root;
}
void traverse_from_root(tree* value)//preorder traversal
{
    cout<<value->data<<" ";
    if(value->left !=nullptr) traverse_from_root(value->left);
    if(value->right !=nullptr) traverse_from_root(value->right);
}
void traverse_to_root(tree* value)//postorder traversal
{
    if(value->left !=nullptr) traverse_to_root(value->left);
    if(value->right !=nullptr) traverse_to_root(value->right);
    cout<<value->data<<" ";
}
void traverse_left_to_right(tree* value)//intorder traversal
{
    if(value->left !=nullptr) traverse_to_root(value->left);
    cout<<value->data<<" ";
    if(value->right !=nullptr) traverse_to_root(value->right);
}
void traverse_right_to_left(tree *value)
{
    if(value->right !=nullptr) traverse_to_root(value->right);
    cout<<value->data<<" ";
    if(value->left !=nullptr) traverse_to_root(value->left);
}
int main()
{
    tree *root = create_tree();
    traverse_from_root(root);
    cout<<"\n";
    traverse_to_root(root);
    cout<<"\n";
    traverse_left_to_right(root);
    cout<<"\n";
    traverse_right_to_left(root);
}
