#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node *next;
};

// Create a new node helper
static struct node *create_node(int coef, int exp) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (!temp) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}

// Insert in descending order of exponents
static void insert_sorted(int coef, int exp, struct node **head) {
    if (coef == 0) return;

    struct node *temp = create_node(coef, exp);

    if (*head == NULL || (*head)->exp < exp) {
        temp->next = *head;
        *head = temp;
        return;
    }

    struct node *curr = *head;
    while (curr->next != NULL && curr->next->exp >= exp) {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
}

static struct node *search(struct node *head, int exp) {
    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->exp == exp) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

static void read_poly(struct node **head, int n) {
    for (int i = 0; i < n; i++) {
        int coef, exp;
        printf("Enter term %d (coefficient exponent): ", i + 1);
        scanf("%d %d", &coef, &exp);
        insert_sorted(coef, exp, head);
    }
}

static void print_poly(struct node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->coef != 0) {
            printf("%dx^%d", ptr->coef, ptr->exp);
            if (ptr->next != NULL && ptr->next->coef != 0) {
                printf(" + ");
            }
        }
        ptr = ptr->next;
    }
    printf("\n");
}

static void multiply(struct node *head1, struct node *head2, struct node **head3) {

    //using for loop to reduce time complexity
    for (struct node *p = head1; p != NULL; p = p->next) {
        for (struct node *q = head2; q != NULL; q = q->next) {
            int coef = p->coef * q->coef;
            int exp = p->exp + q->exp;

            struct node *found = search(*head3, exp);
            if (found != NULL) {
                found->coef += coef;
            } else {
                insert_sorted(coef, exp, head3);
            }
        }
    }
}

static void free_poly(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        struct node *next = curr->next;
        free(curr);
        curr = next;
    }
}

int main(void) {
    int n, m;
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    struct node *poly3 = NULL;

    printf("Enter number of terms for Polynomial 1: ");
    scanf("%d", &n);
    read_poly(&poly1, n);
    printf("\n---------------- POLYNOMIAL 1 -----------------\n");
    print_poly(poly1);

    printf("\nEnter number of terms for Polynomial 2: ");
    scanf("%d", &m);
    read_poly(&poly2, m);
    printf("\n---------------- POLYNOMIAL 2 -----------------\n");
    print_poly(poly2);

    multiply(poly1, poly2, &poly3);
    printf("\n---------------- MULTIPLIED RESULT ------------\n");
    print_poly(poly3);

    free_poly(poly1);
    free_poly(poly2);
    free_poly(poly3);

    return 0;
}