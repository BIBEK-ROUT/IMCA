#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    float coffe;
    int expo;
    struct polynomial *next;
} poly;

void create_sorted(poly **head, int expo, float coffe)
{
    poly *temp = *head, *node, *prev = NULL;
    node = (poly *)malloc(sizeof(poly));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->coffe = coffe;
    node->expo = expo;
    node->next = NULL;

    // Empty list
    if (*head == NULL) {
        *head = node;
        return;
    }

    // Insert at head
    if (expo > (*head)->expo) {
        node->next = *head;
        *head = node;
        return;
    }

    // Same exponent as head
    if (expo == (*head)->expo) {
        (*head)->coffe += coffe;
        free(node);
        return;
    }

    // Traverse to insert
    while (temp->next != NULL && temp->expo>=expo) {
        prev = temp;
        temp = temp->next;
    }

    // Check for duplicate exponent
    if (temp->expo == expo) {
        temp->coffe += coffe;
        free(node);
        return;
    }
    else if (temp->expo < expo) {
        // Insert before temp
        if (prev != NULL) {
            prev->next = node;
            node->next = temp;
            return;
        } 

    }
    // Insert node
    node->next = temp->next;
    temp->next = node;
}
poly * add(poly *p1,poly *p2)
{
    poly *p3=NULL,*node=NULL;
    
    while(p1!=NULL || p2!=NULL)
    {
        node=(poly *)malloc(sizeof(poly));
         if(node==NULL)
        {
            printf("memory allocation failed!!!");
            exit(1);
        }
        if(p1->expo==p2->expo)
        {
            node->coffe=p1->coffe+p2->coffe;
            node->expo=p1->expo;
            node->next=NULL;
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->expo>p2->expo)
        {
            node->coffe=p1->coffe;
            node->expo=p1->expo;
            node->next=NULL;
            p1=p1->next;
        }
        else if(p1->expo<p2->expo)
        {
            node->expo=p2->expo;
            node->coffe=p2->coffe;
            p2=p2->next;
        }
        if(p3==NULL)
            {
                p3=node;
            }
        else
            {
            poly *temp=p3;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=node;
            }
    }
    return p3;
}

void print(poly *head)
{
    while (head != NULL) {
        printf("(%.1fx^%d)", head->coffe, head->expo);
        if (head->next != NULL)
            printf("+");
        else
            printf("\n");
        head = head->next;
    }
}

void get_info(poly **head)
{
    int n, expo;
    float coffe;

    printf("Please enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter exponent of term %d: ", i);
        scanf("%d", &expo);
        printf("Enter coefficient of term %d: ", i);
        scanf("%f", &coffe);
        create_sorted(head, expo, coffe);
    }
}

int main()
{
    poly *head = NULL;
    poly *head1 = NULL;

    get_info(&head);
    print(head);

    get_info(&head1);
    print(head1);
    printf("Additon of polynomials is:");
    print(add(head,head1));
    return 0;
}
