#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }

    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, value, key, n, i;
    do
    {
        printf("\n\n--- BINARY SEARCH TREE ---\n");
        printf("1. Create BST\n");
        printf("2. Search an element\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("How many nodes? \n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
            }
            printf("BST created successfully!\n");
            break;

        case 2:
            printf("Enter element to search: ");
            scanf("%d", &key);

            if (search(root, key) != NULL)
            {
                printf("Element found!\n");
            }
            else
            {
                printf("Element not found!\n");
            }
            break;

        case 3:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 5:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;

        case 6:
            printf("Program terminated.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
