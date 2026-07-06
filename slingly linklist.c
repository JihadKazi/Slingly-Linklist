#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int x) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

void append(struct Node **head, int x) {
    struct Node *n = newNode(x);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct Node *t = *head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}

int exists(struct Node *head, int x) {
    while (head != NULL) {
        if (head->data == x) return 1;
        head = head->next;
    }
    return 0;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void divideList(struct Node *list1, struct Node **X, struct Node **Y) {
    while (list1 != NULL) {
        if (list1->data > 25 || list1->data % 4 == 0)
            append(X, list1->data);
        else
            append(Y, list1->data);
        list1 = list1->next;
    }
}

struct Node* mergeUnique(struct Node *X, struct Node *list2) {
    struct Node *m = NULL;

    while (X != NULL) {
        if (!exists(m, X->data)) append(&m, X->data);
        X = X->next;
    }

    while (list2 != NULL) {
        if (!exists(m, list2->data)) append(&m, list2->data);
        list2 = list2->next;
    }

    return m;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL, *X = NULL, *Y = NULL, *merged = NULL;
    int n1, n2, x, i;

    printf("Enter number of elements in List 01: ");
    scanf("%d", &n1);
    printf("Enter elements of List 01: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &x);
        append(&list1, x);
    }

    printf("Enter number of elements in List 02: ");
    scanf("%d", &n2);
    printf("Enter elements of List 02: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &x);
        append(&list2, x);
    }

    divideList(list1, &X, &Y);
    merged = mergeUnique(X, list2);

    printf("\nList 01: ");
    display(list1);
    printf("List 02: ");
    display(list2);
    printf("X: ");
    display(X);
    printf("Y: ");
    display(Y);
    printf("Merged Unique List: ");
    display(merged);

    return 0;
}