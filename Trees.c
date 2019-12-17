#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * Input(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

struct node * Insert(struct node *root,int value)
{
    if(root==NULL)
    {
        root=Input(value);
        return root;
    }

    if(value <= root -> data)
        root -> left= Insert(root -> left, value);

    else
        root -> right= Insert(root -> right, value);

    return root;
}

void BST (struct node *root)
{
    if (root!=NULL)
    {
        if(root -> left != NULL)
        {
            BST(root -> left);
        }
        printf("%d ",root->data);
        if(root -> right != NULL)
        {
            BST(root -> right);
        }
    }
    else
    {
        printf("Tree is empty.");
    }
}

int maxHeight(struct node *root)         //Function to find the maximum height of a BST.
{
    if(root==NULL)
        return -1;
    else
    {
        int a=maxHeight(root->left);
        int b=maxHeight(root->right);

        if (a>=b)
            return a+1;
        else
            return b+1;
    }
}

int minDepth(struct node *root)         //Function to find the minimum depth of a BST.
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    if(!root->left)
        return minDepth(root->right) + 1;
    if(!root->right)
        return minDepth(root->left) + 1;
    if((minDepth(root->left))<(minDepth(root->right)))
        return minDepth(root->left);
    else
        return minDepth(root->right);

}

int minValue(struct node *root)         //Minimum and Maximum value of BST
{
    struct node* min=root;
    struct node* max=root;
    while(min->left!=NULL)
    {
        min=min->left;
    }
    printf("\nMin value is: %d",min->data);
    while(max->right!=NULL)
    {
        max=max->right;
    }
    printf("\nMax value is: %d",max->data);
}

int main()
{
    struct node *root=NULL;
    int n,value;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        printf("Enter node value: ");
        scanf("%d",&value);
        root=Insert(root,value);
    }
    BST(root);

    printf("\nMax height is: %d",maxHeight(root));
    printf("\nMin depth is: %d",minDepth(root));
    minValue(root);
}