#include <stdlib.h>
#include <stdio.h>

// Definición de un nodo de lista enlazada
struct node {
    int value;          // Valor del nodo
    struct node *next;  // Puntero al siguiente nodo
};

int insert_node(int value, struct node **stack ) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        printf("error al aignar memoria.\n");
        exit(1);
    }
    new_node->value = value;

    struct node *tmp = *stack;
    *stack = new_node;
    new_node->next = tmp;


};
int main() {
    struct node *top = malloc(sizeof(struct node)); // Crear nodo inicial (cima de la pila)
    if (!top) { // Verificar asignación de memoria
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        return 1;
    }

    top->value = 5;    // Asignar valor

    top->next = NULL;  // No hay siguiente nodo
    insert_node(6,&top);
    insert_node(7,&top);

    printf("Cima de la pila: %i\n", top->value); // Imprimir valor de la cima


    free(top); // Liberar memoria
    return 0;
}