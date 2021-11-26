#include <iostream>
#include "Trajet.h"
#include <typeinfo>

using namespace std;

int main() {
    Trajet t1("Paris", "Lyon");
    Trajet t2("Paris", "Lyon");

    cout << typeid(t1).name() << endl;

    t1.afficherTrajet();

    cout << t1.estEgal(t2) << endl;

    return 0;
}