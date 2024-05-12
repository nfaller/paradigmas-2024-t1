#include "lista.h"
#include <stdlib.h>

// Estrutura para um nó da lista encadeada
typedef struct _node {
    void* data; // Ponteiro para os dados
    struct _node* next; // Ponteiro para o próximo nó
} Node;

// Estrutura para a lista encadeada
struct _lista {
    Node* head; // Ponteiro para o primeiro nó da lista
    int data_size; // Tamanho dos dados a serem armazenados
    void (*free_data)(void*); // Função para liberar a memória dos dados
};

// Inicializa a estrutura da lista
void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    lista->head = NULL;
    lista->data_size = data_size;
    lista->free_data = free_data;
}

// Libera memória utilizada pela lista, e a reinicializa
void Lista_delete(Lista* lista) {
    while (lista->head != NULL) {
        Node* temp = lista->head;
        lista->head = lista->head->next;
        if (lista->free_data != NULL) {
            lista->free_data(temp->data);
        }
        free(temp);
    }
}

// Retorna 0 (zero) se a lista possuir elementos, e 1 se estiver vazia
int Lista_isEmpty(Lista* lista) {
    return lista->head == NULL;
}

// Retorna o número de elementos armazenados na lista
int Lista_size(Lista* lista) {
    int size = 0;
    Node* current = lista->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

// Insere um novo valor no início da lista
void Lista_pushFront(Lista* lista, void* valor) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = malloc(lista->data_size);
    newNode->next = lista->head;
    memcpy(newNode->data, valor, lista->data_size);
    lista->head = newNode;
}

// Insere um novo valor no final da lista
void Lista_pushBack(Lista* lista, void* valor) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = malloc(lista->data_size);
    newNode->next = NULL;
    memcpy(newNode->data, valor, lista->data_size);

    if (lista->head == NULL) {
        lista->head = newNode;
    } else {
        Node* current = lista->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Procura na lista por um elemento associado com a chave
int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*,void*)) {
    Node* current = lista->head;
    while (current != NULL) {
        if (cmp(current->data, chave) == 0) {
            memcpy(dest, current->data, lista->data_size);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Ajusta o 'elemento atual' da lista para o primeiro elemento
void Lista_first(Lista* lista) {
    // Não é necessário implementar para esta lista simplesmente encadeada
}

// Ajusta o 'elemento atual' da lista para o último elemento
void Lista_last(Lista* lista) {
    // Não é necessário implementar para esta lista simplesmente encadeada
}

// Ajusta o 'elemento atual' da lista para próximo elemento
int Lista_next(Lista* lista) {
    // Não é necessário implementar para esta lista simplesmente encadeada
    return 0;
}

// Retorna o valor do 'elemento atual' em 'dest'
void Lista_current(Lista* lista, void* dest) {
    // Não é necessário implementar para esta lista simplesmente encadeada
}

// Remove um elemento da lista
void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*,void*)) {
    Node* current = lista->head;
    Node* prev = NULL;
    while (current != NULL) {
        if (cmp(current->data, chave) == 0) {
            if (prev == NULL) {
                lista->head = current->next;
            } else {
                prev->next = current->next;
            }
            if (lista->free_data != NULL) {
                lista->free_data(current->data);
            }
            free(current->data);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Insere um novo elemento na lista após o 'elemento atual'
void Lista_insertAfter(Lista* lista, void* dado) {
    // Não é necessário implementar para esta lista simplesmente encadeada
}
