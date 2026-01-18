#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void search(struct node* root, int key) {
    if (root == NULL) {
        printf("Key not found\n");
        return;
    }
    if (root->data == key) {
        printf("Key found\n");
        return;
    }
    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

int main() {
    struct node* root = NULL;
    int choice, key, n, data;

    do {
        printf("\nMENU");
        printf("\n1. Create BST");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Search");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = NULL;
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                printf("BST Created\n");
                break;

            case 2:
                if (root == NULL)
                    printf("BST is empty\n");
                else {
                    printf("Inorder: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL)
                    printf("BST is empty\n");
                else {
                    printf("Preorder: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("BST is empty\n");
                else {
                    printf("Postorder: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL) {
                    printf("BST is empty\n");
                } else {
                    printf("Enter key to search: ");
                    scanf("%d", &key);
                    search(root, key);
                }
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}

