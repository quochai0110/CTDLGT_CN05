#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Order {
    int id;
    char customer[100];
    int status;
    char total[100];
}Order;
typedef struct SNode {
    Order data;
    struct SNode *next;

}SNode;
typedef struct DNode {
    Order data;
    struct DNode *next;
    struct DNode *prev;
};
int nextId = 1;

SNode* addOrder(SNode* head) {
    Order order;
    order.id = nextId++;
    printf("");
}
int main() {
    int choice;
}