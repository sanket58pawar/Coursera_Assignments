#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for an atomic element
typedef struct Element {
    char name[20];
    char symbol[3];
    double atomic_weight;
    struct Element* next;
} Element;

// Function to create a new element
Element* createElement(char name[], char symbol[], double atomic_weight) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    if (newElement == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newElement->name, name);
    strcpy(newElement->symbol, symbol);
    newElement->atomic_weight = atomic_weight;
    newElement->next = NULL;
    return newElement;
}

// Function to add a new element to the end of the linked list
void appendElement(Element** head, Element* newElement) {
    if (*head == NULL) {
        *head = newElement;
    } else {
        Element* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

// Function to print the linked list of elements
void printElements(Element* head) {
    printf("Atomic Elements:\n");
    while (head != NULL) {
        printf("Name: %-15s Symbol: %-3s Atomic Weight: %.3f\n", head->name, head->symbol, head->atomic_weight);
        head = head->next;
    }
}

int main() {
    // Create the linked list of elements
    Element* head = NULL;

    // Add the first ten elements of the periodic table
    appendElement(&head, createElement("Hydrogen", "H", 1.008));
    appendElement(&head, createElement("Helium", "He", 4.003));
    appendElement(&head, createElement("Lithium", "Li", 6.941));
    appendElement(&head, createElement("Beryllium", "Be", 9.012));
    appendElement(&head, createElement("Boron", "B", 10.811));
    appendElement(&head, createElement("Carbon", "C", 12.011));
    appendElement(&head, createElement("Nitrogen", "N", 14.007));
    appendElement(&head, createElement("Oxygen", "O", 15.999));
    appendElement(&head, createElement("Fluorine", "F", 18.998));
    appendElement(&head, createElement("Neon", "Ne", 20.180));

    // Print the linked list of elements
    printElements(head);

    // Free memory allocated for elements
    Element* current = head;
    Element* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
