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
void printModifyMenu();

void poligonInfo(Shape** poligons, int nP);
void poligonModify(Shape** poligons, int nP);
void poligonMove(Shape** poligons, int nP);
void deleteAllPoligons(Shape** poligons, int nP);

int readInt();
float readFloat();

int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    int selected = 0;

    bool run = true;

    bool sure = false;

    
    shapes[nShapes++] = new Rectangle(0, 0, 10, 5);
    shapes[nShapes++] = new Rhombus(2, 2, 10, 6);
    shapes[nShapes++] = new IsoscelesTriangle(1, 4, 8, 2);

    while (run) {
        printMenu();
        selected = readInt();

        switch (selected) {
            case 1:
                poligonInfo(shapes, nShapes);
                break;
            case 2:
                poligonModify(shapes, nShapes);
                break;
            case 3:
                poligonMove(shapes, nShapes);
                break;
            case 4:
            case 5:
            case 6:
                cout << "Sei sicuro di voler eliminare tutti i poligoni? (1->si 0->no)" << endl;
                sure = (bool) readInt();
                if (sure)
                    deleteAllPoligons(shapes, nShapes);
                break;
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
    cout << endl << "===POLIGONI===" << endl << endl;
    cout << "\t\tTipo\t\t\t|Posizione|Larghezza|Altezza" << endl;
    for (int i = 0; i < nP; i++) {
        cout << "Poligono " << i << " :\t";
        poligons[i]->DumpType();
        cout << "\t\t( " << poligons[i]->GetX() << " , " << poligons[i]->GetY() << " )\t" << poligons[i]->GetWidth() << "\t" << poligons[i]->GetHeight() << endl << endl;
    }
}

void printModifyMenu()
{
    cout << endl << "===== MENU' di MODIFICA =====" << endl << endl;

    cout << "[1] Ridimensiona" << endl;
    cout << "[2] Imposta testo" << endl;
    cout << "[3] Imposta larghezza" << endl;
    cout << "[4] Imposta altezza" << endl;

    cout << endl << "[0] Esci" << endl;

    cout << endl << "Quale operazione si vuole eseguire?" << endl;

    return;
}

void poligonInfo(Shape** poligons, int nP)
{
    int selected = 0;

    printPoligonList(poligons, nP);
    
    cout << "[numero poligono] Per vedere piu' dettagli del poligono" << endl;
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


void poligonModify(Shape** poligons, int nP)
{
    bool read = true;

    int poligon_selected = 0;
    int action_selected = 0;

    printPoligonList(poligons, nP);
    
    cout << "[numero poligono] Per modificare il poligono" << endl;
    cout << "[-1] Ritorna al menu" << endl << endl;

    cout << "Quale operazione si vuole eseguire?" << endl;
    
    while(read) 
    {
        poligon_selected = readInt();

        if (poligon_selected == -1)
            return;

        if (poligon_selected >= 0 && poligon_selected < nP) {
            read = !read;
        }
        else {
            cout << "Operazione non valida, inserire un valore tra quelli disponibili" << endl;
        }
    }

    printModifyMenu();

    read = true;
    while(read) 
    {
        action_selected = readInt();

        if (action_selected == -1)
            return;

        if (action_selected > 0 && action_selected < 5) {
            read = !read;
        }
        else {
            cout << "Operazione non valida, inserire un valore tra quelli disponibili" << endl;
        }
    }
    
    switch (action_selected)
    {
    case 1:
        cout << "Inserire un valore per il ridimensionamento nel formato x.xx dove 1.00 = 100%" << ", maggiore di 0" << endl;
        poligons[poligon_selected]->Scale(readFloat());
        break;
    case 2:
        break;
    case 3:
        cout << "Inserire il nuovo valore per larghezza" << endl;
        poligons[poligon_selected]->SetWidth(readFloat());
        break;
    case 4:
        cout << "Inserire il nuovo valore per altezza" << endl;
        poligons[poligon_selected]->SetHeight(readFloat());
        break;
    default:
        cout << "ERROR (poligonModify): action not defined" << endl;
        break;
    }
}

void poligonMove(Shape** poligons, int nP)
{
    int newX = 0;
    int newY = 0;
    
    bool read = true;

    int selected = 0;

    printPoligonList(poligons, nP);
    
    cout << "[numero poligono] Per modificare la posizione del poligono" << endl;
    cout << "[-1] Ritorna al menu" << endl << endl;

    cout << "Quale operazione si vuole eseguire?" << endl;
    while(read) 
    {
        selected = readInt();

        if (selected == -1)
            return;

        if (selected >= 0 && selected < nP) {
            read = !read;
        }
        else {
            cout << "Operazione non valida, inserire un valore tra quelli disponibili" << endl;
        }
    }

    cout << "Inserire il nuovo valore per x" << endl;
    newX = readInt();
    cout << "Inserire il nuovo valore per y" << endl;
    newY = readInt();
    poligons[selected]->SetPosition(newX, newY);
    return;
}

void deleteAllPoligons(Shape** poligons, int nP)
{
    for (int i = 0; i < nP; i++) {
        if(poligons[i]!=NULL)
        {
            delete poligons[i];
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

float readFloat()
{
    bool read = true;
    float floatNum = 0;
    while (read) {
        cin >> floatNum;
        if (cin.fail()) {
            cout << "Valore inserito non valido, riprova." << endl;
        }
        else 
            read = false;
    }
    return floatNum;
}