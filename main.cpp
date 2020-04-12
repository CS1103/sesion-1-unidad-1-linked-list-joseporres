#include "linked_list.h"


int main() {
    //pushfront en una lista que comienza con 0 elementos
    utec::linked_list_t pushfront;
    for (int j = 0; j < 10; ++j) {
        pushfront.push_front(9);
    }
    cout<<"Elementos agregados con push_back: ";
    for (int i = 0; i < pushfront.size() ; ++i) {
        cout<<pushfront.item(i)<< "  ";
    }

    cout<<endl;

    //pushback en una lista que comienza con 0 elementos
    utec::linked_list_t pushback;
    for (int j = 0; j < 10; ++j) {
        pushback.push_back(8);
    }
    cout<<"Elementos agregados con push_front:  ";
    for (int i = 0; i < pushfront.size() ; ++i) {
        cout<<pushback.item(i)<< "  ";
    }
    cout<< endl;

    //insert en una lista que comienza con 0 elementos

    utec::linked_list_t insert;
    for (int l = 0; l <10; ++l) {
        insert.push_back(5);
    }
    //insertando un 3 en lista de 7s
    insert.insert(7,3);
    cout<<"El numero 3 agaregado con insert en la posicion 7: ";
    for (int k = 0; k < insert.size() ; ++k) {
        cout<<insert.item(k)<<"  ";
    }

    cout<<endl;

    //Usando el pop_front, pop_back;
    utec::linked_list_t elementos;

    elementos.push_front(781);
    for (int j = 0; j < 10; ++j) {
        elementos.push_back(8);
    }
    elementos.push_back(781);
    elementos.insert(6,781);
    cout<<"Elementos:  ";
    for (int i = 0; i < elementos.size() ; ++i) {
        cout<<elementos.item(i)<< "  ";
    }
    elementos.pop_front();
    cout<< endl;
    cout<<"Usando el pop_front en la lista de elementos: ";
    for (int i = 0; i < elementos.size() ; ++i) {
        cout<<elementos.item(i)<< "  ";
    }
    elementos.push_front(781);
    cout<< endl;
    elementos.pop_back();
    cout<<"Usando el pop_back en la lista de elementos: ";
    for (int i = 0; i < elementos.size() ; ++i) {
        cout<<elementos.item(i)<< "  ";
    }
    elementos.push_back(781);
    cout<<endl;
    elementos.insert(6,781);
    cout<<"Insertando con insert en la posicion 6 de la lista de elementos: ";
    for (int i = 0; i < elementos.size() ; ++i) {
        cout<<elementos.item(i)<< "  ";
    }
    elementos.erase(6);
    cout<<endl;
    cout<<"Eliminando el elemento de la posicion 6 de la lista de elementos: ";
    elementos.erase(6);
    for (int i = 0; i < elementos.size() ; ++i) {
        cout<<elementos.item(i)<< "  ";
    }





    return 0;
}
