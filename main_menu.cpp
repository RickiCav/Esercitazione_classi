#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

#define MAX_SHAPES 10

void printMenu();
void printPoligonList(Shape** poligons, int nP);

int readInt();

int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    int selected = 0;

    bool run = true;

    shapes[1]->Dump();

    while (run) {
        printMenu();
        selected = readInt();

        switch (selected) {
            case 1:
                printPoligonList(shapes, nShapes);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 0:
                run = !run;
                break;
            default:
                cout << "Operazione non valida, inserire un valore tra quelli disponibili" << endl;
        }
        

    }









/*

    // 1. Creazione figure
    shapes[nShapes++] = new Rectangle(0, 0, 10, 5);
    shapes[nShapes++] = new Rhombus(2, 2, 10, 6);
    shapes[nShapes++] = new IsoscelesTriangle(1, 4, 8, 2);


    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[2]->SetText("triangolo isoscele");

    // 3. Dump polimorfico
    cout << endl << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }
    
    // 4. Scalamento figure
    cout << endl << "===== SCALAMENTO =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Scale(2);
    }

    cout << endl << "===== DUMP FIGURE SCALATE =====" << endl;
    
    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }

    // Distruzione figure

    for (int i = 0; i < nShapes; i++) {
        if(shapes[i]!=NULL)
        {
            delete shapes[i];
        }
    }

    cout << endl << "===== FINE TEST =====" << endl;

    return 0;

*/

}

void printMenu() 
{
    cout << endl << "===== MENU' =====" << endl << endl;

    cout << "[1] Visualizza tutti i poligoni" << endl;
    cout << "[2] Modifica le proprietà di un poligono" << endl;
    cout << "[3] Sposta un poligono sulla griglia" << endl;
    cout << "[4] Inserisci un nuovo poligono" << endl;
    cout << "[5] Cancella un poligono" << endl;
    cout << "[6] Cancella tutti i poligoni" << endl;

    cout << endl << "[0] Esci" << endl;

    cout << endl << "Quale operazione si vuole eseguire?" << endl;

    return;
}

void printPoligonList(Shape** poligons, int nP)
{
    int selected = 0;
    cout << endl << "===POLIGONI===" << endl << endl;
    cout << "\t\tTipo\t\t\t|Posizione|Larghezza|Altezza" << endl;
    for (int i = 0; i < nP; i++) {
        cout << "Poligono " << i << " :\t";
        poligons[i]->DumpType();
        cout << "\t\t( " << poligons[i]->GetX() << " , " << poligons[i]->GetY() << " )\t" << poligons[i]->GetWidth() << "\t" << poligons[i]->GetHeight() << endl;
    }
    cout << endl << "[numero poligono] Per vedere piu' dettagli del poligono" << endl;
    cout << "[-1] Ritorna al menu" << endl << endl;

    cout << "Quale operazione si vuole eseguire?" << endl;
    while(1) 
    {
        selected = readInt();

        if (selected == -1)
            return;

        if (selected >= 0 && selected < nP) {
            poligons[selected]->Dump();
            return;
        }
        else {
            cout << "Operazione non valida, inserire un valore tra quelli disponibili" << endl;
        }
    }
    
}

int readInt()
{
    bool read = true;
    int integer = 0;
    while (read) {
        cin >> integer;
        if (cin.fail()) {
            cout << "Valore inserito non valido, riprova." << endl;
        }
        else 
            read = false;
    }
    return integer;
}