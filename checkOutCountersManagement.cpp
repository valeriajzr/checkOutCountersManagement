#include <iostream>
#include <cstring>
using namespace std;

void callMenuQueue();
void removeElementQueue();

struct QUEUE {
    char name[15];
    struct QUEUE* prev;
};

//puntero raiz
struct QUEUE* checkoutCounterNode = NULL;

//Abajo declaro que mi arreglo sea global
struct QUEUE** checkoutArray;
int element;

//crear el arreglo dinamico que representa las distintas cajas que existen
void createArray() {
    int checkoutCounterNumber;
    cout << "How many checkout counters are there?" << endl;
    cin >> checkoutCounterNumber;

    checkoutArray = new struct QUEUE* [checkoutCounterNumber]; //le pongo a mi arreglo el tamaño que indica el usuario

    //Pongo en null todos los elementos del arreglo para poder trabajar con colas posteriormente
    for (int i = 0; i < checkoutCounterNumber; i++) {
        checkoutArray[i] = NULL;
    }
}

void selectCheckoutCounter() {
    cout << "Select the checkout counter to manage: " << endl;
    cin >> element;
    checkoutCounterNode = checkoutArray[element];
    callMenuQueue();
}

void addElementQueue() {
    struct QUEUE* customer = new QUEUE;
    cout << "Name of the customer: ";
    cin >> customer->name;
    customer->prev = NULL;

    if (checkoutCounterNode == NULL) {
        checkoutCounterNode = customer;
    }
    else {
        struct QUEUE* aux = checkoutCounterNode;
        while (aux->prev != NULL) aux = aux->prev;
        aux->prev = customer;

    }

    checkoutArray[element] = checkoutCounterNode;

    callMenuQueue();
}

void showQueue() {
    cout << endl << "Customers waiting on counter: " << endl;
    struct QUEUE* aux = checkoutCounterNode;
    for (int i = 1; aux; i++) {
        cout << "Customer " << i << ": " << aux->name << endl;
        aux = aux->prev;
    }
    callMenuQueue();
}

void callMenuQueue() {
    int option;
    do {
        cout << endl << "Managing checkout counter " << element << endl;
        cout << "Select an option: " << endl;
        cout << "1. Show queue" << endl;
        cout << "2. Add customer to queue" << endl;
        cout << "3. Serve customer" << endl;
        cout << "4. Select another checkout counter" << endl;
        cout << "5. Exit" << endl;
        cin >> option;
    } while (option < 1 || option > 4);

    switch (option) {
    case 1: showQueue();
        break;
    case 2: addElementQueue();
        break;
    case 3: removeElementQueue();
        break;
    case 4: 
        checkoutArray[element] = checkoutCounterNode;
        selectCheckoutCounter();
        break;
    case 5: break;
    }
}

void removeElementQueue() {
    if (checkoutCounterNode) {
        cout << "Customer " << checkoutCounterNode->name << " was served." << endl;
        struct QUEUE* aux = new QUEUE[1];
        aux = checkoutCounterNode;
        checkoutCounterNode = checkoutCounterNode->prev;
        aux->prev = NULL;
        aux = NULL;
        delete[] aux;
    }

    checkoutArray[element] = checkoutCounterNode;
    callMenuQueue();
}

int main()
{
    //arreglo dinamico
    createArray();
    selectCheckoutCounter();
    return 0;
}
