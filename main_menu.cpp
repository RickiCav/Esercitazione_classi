#include <iostream>    // Input/Output standard: cout, cin, endl
#include <cmath>       // Funzioni matematiche: sqrt, pow, etc.

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

#define MAX_SHAPES 10

void printMenu();
void printPoligonList(Shape** poligons, int nP);
void printModifyMenu();
void printPoligonTypeMenu();

void poligonInfo(Shape** poligons, int nP);
void poligonModify(Shape** poligons, int nP);
void poligonMove(Shape** poligons, int nP);
void poligonAdd(Shape** poligons, int &nP, int maxP);
void poligonDelete(Shape** poligons, int &nP);
void deleteAllPoligons(Shape** poligons, int &nP);

bool isValidPosition(float x, float y, float w, float h);

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
                poligonAdd(shapes, nShapes, MAX_SHAPES);
                break;
            case 5:
                poligonDelete(shapes, nShapes);
                break;
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

    // Deallocazione di tutti i poligoni rimasti
    for (int i = 0; i < nShapes; i++) {
        if (shapes[i] != NULL) {
            delete shapes[i];
        }
    }
    nShapes = 0;









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
    cout << "[2] Modifica le proprieta' di un poligono" << endl;
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
    // Stampa lista di poligoni in formato verticale (una per riga)
    // Formato: indice, tipo, posizione, larghezza, altezza, testo
    
    cout << endl << "==================== LISTA POLIGONI ====================" << endl << endl;
    
    for (int i = 0; i < nP; i++) {
        char type[TYPESIZE];
        char text[TEXTSIZE];
        
        // Ottiene i dati dal poligono tramite i getter della classe Shape
        poligons[i]->GetType(type);
        poligons[i]->GetText(text);
        
        // Stampa ogni poligono su più righe per maggiore leggibilità
        cout << "Poligono " << i << ":" << endl;
        cout << "  Tipo:       " << type << endl;
        cout << "  Posizione:  (" << (int)poligons[i]->GetX() << ", " 
             << (int)poligons[i]->GetY() << ")" << endl;
        cout << "  Larghezza:  " << poligons[i]->GetWidth() << endl;
        cout << "  Altezza:    " << poligons[i]->GetHeight() << endl;
        cout << "  Testo:      " << (text && text[0] != '\0' ? text : "(nessuno)") << endl;
        cout << endl;
    }
    cout << "======================================================" << endl << endl;
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

void printPoligonTypeMenu()
{
    cout << endl << "===== SCEGLI TIPO DI POLIGONO =====" << endl << endl;

    cout << "[1] Rettangolo (Rectangle)" << endl;
    cout << "[2] Rombo (Rhombus)" << endl;
    cout << "[3] Triangolo Isoscele (IsoscelesTriangle)" << endl;

    cout << endl << "[0] Annulla" << endl;

    cout << endl << "Quale tipo vuoi inserire?" << endl;

    return;
}

void poligonInfo(Shape** poligons, int nP)
{
    int selected = 0;

    printPoligonList(poligons, nP);
    cout <<"opzioni visualizzazione:" << endl;
    cout << "-->[numero poligono] Per vedere piu' dettagli del poligono" << endl;
    cout << "-->[-1] Ritorna al menu" << endl << endl;

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
    //case 2
    char textInput[1000];
    //case 3
    float newW = 0;
    //case 4
    float newH = 0;
    int poligon_selected = 0;
    int action_selected = 0;

    printPoligonList(poligons, nP);
    cout <<"opzioni modifica:" << endl;
    cout << "-->[numero poligono] Per modificare il poligono" << endl;
    cout << "-->[-1] Ritorna al menu" << endl << endl;

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
        cout << "Inserire il nuovo testo:" << endl;
        
        cin.ignore();  // Pulisci il buffer
        cin.getline(textInput, 1000);
        poligons[poligon_selected]->SetText(textInput);
        break;

    
    case 3:
    
        
        cout << "Inserire il nuovo valore per larghezza" << endl;
        newW = readFloat();
        // Verifica che la nuova bounding box resti dentro la griglia
        if (isValidPosition(poligons[poligon_selected]->GetX(), poligons[poligon_selected]->GetY(), newW, poligons[poligon_selected]->GetHeight()))
        {
            poligons[poligon_selected]->SetWidth(newW);
        }else
        {
            cout << "Modifica non eseguita: la nuova bounding box esce dalla griglia" << endl;
        }
    
    break;

    case 4:
    
        cout << "Inserire il nuovo valore per altezza" << endl;
        newH = readFloat();
        // Verifica che la nuova bounding box resti dentro la griglia
        if (isValidPosition(poligons[poligon_selected]->GetX(), poligons[poligon_selected]->GetY(), poligons[poligon_selected]->GetWidth(), newH))
        {
            poligons[poligon_selected]->SetHeight(newH);
        }else
        {
            cout << "Modifica non eseguita: la nuova bounding box esce dalla griglia" << endl;
        }
    
    break;

    default:
        cout << "ERRORE (poligonModify): caso non implementato" << endl;
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
    cout <<"opzioni modifica:" << endl;
    cout <<"-->[numero poligono] Per modificare la posizione del poligono" << endl;
    cout << "-->[-1] per ritornare al menu" << endl << endl;

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
            cout <<"Operazione non valida, inserire un valore tra quelli disponibili" << endl;
        }
    }

    cout <<"Inserire il nuovo valore per x" << endl;
    newX = readInt();
    cout << "Inserire il nuovo valore per y" << endl;
    newY = readInt();
    poligons[selected]->SetPosition(newX, newY);
    return;
}

void deleteAllPoligons(Shape** poligons, int &nP)
{
    for (int i = 0; i < nP; i++) {
        if(poligons[i]!=NULL)
        {
            delete poligons[i];
        }
    }
    nP = 0;
    cout << "Tutti i poligoni sono stati eliminati." << endl;
}

bool isValidPosition(float x, float y, float w, float h)
{
    // Controlla se il poligono è completamente dentro la griglia
    // Griglia: 0 <= x,y < 100 e 0 <= width,height < 100
    
    if (x < 0 || y < 0) {
        cout <<"Errore: la posizione non può essere negativa" << endl;
        return false;
    }
    
    if (w <= 0 || h <= 0) {
        cout <<"Errore: larghezza e altezza devono essere positive" << endl;
        return false;
    }
    
    if (x + w > GRID_WIDTH) {
        cout <<"Errore: il poligono esce dai bordi destri della griglia (max x+w = " << GRID_WIDTH << ")" << endl;
        return false;
    }
    
    if (y + h > GRID_HEIGHT) {
        cout << "Errore: il poligono esce dai bordi inferiori della griglia (max y+h = " << GRID_HEIGHT << ")" << endl;
        return false;
    }
    
    return true;
}

void poligonAdd(Shape** poligons, int &nP, int maxP)
{
    if (nP >= maxP) {
        cout <<"Errore: numero massimo di poligoni raggiunto (" << maxP << ")" << endl;
        return;
    }
    
    printPoligonTypeMenu();
    int typeSelected = readInt();
    
    if (typeSelected == 0) {
        cout << "Inserimento annullato." << endl;
        return;
    }
    
    if (typeSelected < 1 || typeSelected > 3) {
        cout << "Tipo non valido." << endl;
        return;
    }
    
    float px, py, w, h;
    
    cout << endl <<"Inserire posizione e dimensioni del nuovo poligono:" << endl;
    cout <<"Posizione X (0-" << GRID_WIDTH << "): ";
    px = readFloat();
    cout <<"Posizione Y (0-" << GRID_HEIGHT << "): ";
    py = readFloat();
    cout <<"Larghezza: ";
    w = readFloat();
    cout <<"Altezza: ";
    h = readFloat();
    
    if (!isValidPosition(px, py, w, h)){
        return;
    }
    
    switch (typeSelected) {
        case 1:
            poligons[nP++] = new Rectangle(px, py, w, h);
            cout << "Rettangolo aggiunto con successo!" << endl;
            break;
        case 2:
            poligons[nP++] = new Rhombus(px, py, w, h);
            cout << "Rombo aggiunto con successo!" << endl;
            break;
        case 3:
            poligons[nP++] = new IsoscelesTriangle(px, py, w, h);
            cout << "Triangolo isoscele aggiunto con successo!" << endl;
            break;
    }
}

void poligonDelete(Shape** poligons, int &nP)
{
    bool read = true;
    int selected = 0;

    printPoligonList(poligons, nP);
    
    cout << "[numero poligono] Per eliminare il poligono" << endl;
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
    
    cout << "Sei sicuro di voler eliminare questo poligono? (1->si 0->no)" << endl;
    bool sure = (bool) readInt();
    
    if (sure) {
        if(poligons[selected] != NULL) {
            delete poligons[selected];
        }
        
        //Sposto gli elementi successivi indietro di uno
        for (int i = selected; i < nP - 1; i++) {
            poligons[i] = poligons[i + 1];
        }
        nP--;
        
        cout << "Poligono eliminato con successo!" << endl;
    }
}

int readInt()
{
    bool read = true;
    int integer = 0;
    while(read){
        cin >> integer;
        //se il .fail() = true se in questo caso il cin fallisce
        if (cin.fail()){
            cout << "Valore inserito non valido, riprova." << endl;
        }
        else 
            read = false;//se il cin non fallisce allora esce dal ciclo
    }
    return integer;
}

float readFloat()
{
    bool read = true;
    float floatNum = 0;
    //concetto ugaule a readInt() ma con float invece di int
    while (read){
        cin >> floatNum;
        if (cin.fail()) {
            cout << "Valore inserito non valido, riprova." << endl;
        }
        else 
            read = false;
    }
    return floatNum;
}