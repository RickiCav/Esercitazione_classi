/*! \file main_menu.cpp
    \brief implementazione del menu principale per la gestione dei poligoni
    \author Riccardo Cavagnaro Alessandro Fontanazzi
*/
#include <iostream>    //Input/Output standard: cout, cin, endl
#include <cmath>       //Funzioni matematiche: sqrt, pow, etc.

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

#define MAX_SHAPES 10

/** @brief Stampa il menu principale con le opzioni disponibili */
void printMenu();

/** @brief Stampa la lista di tutti i poligoni con i loro dati
 *  @param poligons Array di puntatori ai poligoni
 *  @param nP Numero attuale di poligoni nella lista
 */
void printPoligonList(Shape** poligons, int nP);

/** @brief Stampa il menu per la modifica delle proprietà di un poligono */
void printModifyMenu();

/** @brief Stampa il menu per la scelta del tipo di poligono da inserire */
void printPoligonTypeMenu();

/** @brief Visualizza le informazioni dettagliate di un poligono selezionato
 *  @param poligons Array di puntatori ai poligoni
 *  @param nP Numero attuale di poligoni nella lista
 */
void poligonInfo(Shape** poligons, int nP);

/** @brief Modifica le proprietà (dimensioni, testo) di un poligono selezionato
 *  @param poligons Array di puntatori ai poligoni
 *  @param nP Numero attuale di poligoni nella lista
 */
void poligonModify(Shape** poligons, int nP);

/** @brief Sposta un poligono selezionato a una nuova posizione sulla griglia
 *  @param poligons Array di puntatori ai poligoni
 *  @param nP Numero attuale di poligoni nella lista
 */
void poligonMove(Shape** poligons, int nP);

/** @brief Aggiunge un nuovo poligono alla lista
 *  @param poligons Array di puntatori ai poligoni
 *  @param nP Riferimento al numero di poligoni (viene incrementato)
 *  @param maxP Numero massimo di poligoni consentiti
 */
void poligonAdd(Shape** poligons, int &nP, int maxP);

/** @brief Elimina un poligono selezionato dalla lista
 *  @param poligons Array di puntatori ai poligoni
 *  @param nP Riferimento al numero di poligoni (viene decrementato)
 */
void poligonDelete(Shape** poligons, int &nP);

/** @brief Elimina tutti i poligoni dalla lista
 *  @param poligons Array di puntatori ai poligoni
 *  @param nP Riferimento al numero di poligoni (viene settato a 0)
 */
void deleteAllPoligons(Shape** poligons, int &nP);

/** @brief Valida se una posizione e dimensione bounding box sono dentro la griglia
 *  @param x Posizione X
 *  @param y Posizione Y
 *  @param w Larghezza bounding box
 *  @param h Altezza bounding box
 *  @return true se la bounding box è valida e dentro la griglia, false altrimenti
 */
bool isValidPosition(float x, float y, float w, float h);

/** @brief Legge un numero intero dall'input con controllo di validità
 *  @return Il numero intero letto
 */
int readInt();

/** @brief Legge un numero floating-point dall'input con controllo di validità
 *  @return Il numero floating-point letto
 */
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

/**
 * @brief Stampa il menu principale con le opzioni disponibili
 * 
 * Mostra un menu interattivo con 7 opzioni per gestire i poligoni:
 * 1 - Visualizza tutti i poligoni
 * 2 - Modifica le proprietà di un poligono
 * 3 - Sposta un poligono sulla griglia
 * 4 - Inserisci un nuovo poligono
 * 5 - Cancella un poligono
 * 6 - Cancella tutti i poligoni
 * 0 - Esci dal programma
 */
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

/**
 * @brief Stampa la lista di tutti i poligoni con i loro dati in formato verticale
 * 
 * Per ogni poligono visualizza:
 * - Indice nella lista
 * - Tipo di poligono (Rectangle, Rhombus, IsoscelesTriangle)
 * - Posizione sulla griglia (X, Y)
 * - Larghezza della bounding box
 * - Altezza della bounding box
 * - Testo associato (o "(nessuno)" se vuoto)
 * 
 * @param poligons Array di puntatori ai poligoni
 * @param nP Numero attuale di poligoni nella lista
 */
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

/**
 * @brief Stampa il menu per la modifica delle proprietà di un poligono
 * 
 * Mostra le opzioni disponibili per modificare un poligono:
 * 1 - Ridimensiona (scale factor)
 * 2 - Imposta testo
 * 3 - Imposta larghezza
 * 4 - Imposta altezza
 * 0 - Esci dal menu
 */
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

/**
 * @brief Stampa il menu per la scelta del tipo di poligono da inserire
 * 
 * Mostra i tipi di poligoni disponibili:
 * 1 - Rettangolo (Rectangle)
 * 2 - Rombo (Rhombus)
 * 3 - Triangolo Isoscele (IsoscelesTriangle)
 * 0 - Annulla l'inserimento
 */
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

/**
 * @brief Visualizza informazioni dettagliate su un poligono selezionato
 * 
 * La funzione:
 * 1. Stampa la lista di tutti i poligoni
 * 2. Chiede all'utente di selezionare un poligono tramite indice
 * 3. Valida l'indice inserito
 * 4. Stampa le informazioni complete del poligono (tramite Dump)
 * 
 * @param poligons Array di puntatori ai poligoni
 * @param nP Numero attuale di poligoni nella lista
 */
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


/**
 * @brief Modifica le proprietà di un poligono selezionato
 * 
 * La funzione permette di modificare:
 * 1. Ridimensiona - usando Scale factor
 * 2. Imposta testo - assegna nuovo testo al poligono
 * 3. Imposta larghezza - con validazione che resti dentro la griglia
 * 4. Imposta altezza - con validazione che resti dentro la griglia
 * 
 * Dopo ogni modifica di dimensioni, controlla che la bounding box
 * rimanga completamente dentro la griglia usando isValidPosition().
 * 
 * @param poligons Array di puntatori ai poligoni
 * @param nP Numero attuale di poligoni nella lista
 */
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

/**
 * @brief Sposta un poligono selezionato a una nuova posizione sulla griglia
 * 
 * La funzione:
 * 1. Stampa la lista di poligoni
 * 2. Chiede al'utente di selezionare un poligono tramite indice
 * 3. Chiede le nuove coordinate X e Y
 * 4. Valida che il poligono rimanga dentro la griglia usando SetPosition()
 * 
 * Se la nuova posizione è invalida, SetPosition() rifiuta il movimento
 * e mostra un messaggio di avvertimento.
 * 
 * @param poligons Array di puntatori ai poligoni
 * @param nP Numero attuale di poligoni nella lista
 */
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

/**
 * @brief Elimina tutti i poligoni dalla lista e libera la memoria
 * 
 * Itera su tutti i poligoni presenti nell'array, li dealloca
 * usando delete, e imposta il contatore a 0.
 * 
 * @param poligons Array di puntatori ai poligoni
 * @param nP Riferimento al numero di poligoni (viene settato a 0)
 */
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

/**
 * @brief Valida se una posizione e dimensione bounding box sono all'interno della griglia
 * 
 * La funzione effettua i seguenti controlli:
 * - Posizione X e Y non negative
 * - Larghezza e altezza positive
 * - La bounding box non esce dal bordo destro della griglia (x + w <= GRID_WIDTH)
 * - La bounding box non esce dal bordo inferiore della griglia (y + h <= GRID_HEIGHT)
 * 
 * Se qualunque controllo fallisce, stampa un messaggio di errore specifico.
 * 
 * @param x Posizione X del poligono sulla griglia
 * @param y Posizione Y del poligono sulla griglia
 * @param w Larghezza della bounding box
 * @param h Altezza della bounding box
 * @return true se tutti i controlli passano e la bounding box è valida, false altrimenti
 */
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

/**
 * @brief Aggiunge un nuovo poligono alla lista
 * 
 * La funzione:
 * 1. Controlla se c'è spazio per un nuovo poligono
 * 2. Mostra il menu di scelta del tipo di poligono
 * 3. Chiede posizione e dimensioni
 * 4. Valida che la bounding box stia dentro la griglia
 * 5. Crea il nuovo poligono tramite new e lo aggiunge alla lista
 * 
 * @param poligons Array di puntatori ai poligoni
 * @param nP Riferimento al numero di poligoni (viene incrementato)
 * @param maxP Numero massimo di poligoni consentiti
 */
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

/**
 * @brief Elimina un singolo poligono selezionato dalla lista
 * 
 * La funzione:
 * 1. Stampa la lista di poligoni
 * 2. Chiede al'utente di selezionare un poligono tramite indice
 * 3. Chiede conferma prima dell'eliminazione
 * 4. Dealloca il poligono usando delete
 * 5. Riordina l'array spostando gli elementi successivi indietro di uno
 * 6. Decrementa il contatore dei poligoni
 * 
 * @param poligons Array di puntatori ai poligoni
 * @param nP Riferimento al numero di poligoni (viene decrementato)
 */
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

/**
 * @brief Legge un numero intero dall'input con validazione
 * 
 * Questa funzione utilizza un ciclo per leggere l'input e controllare
 * se la conversione a intero è andata a buon fine usando cin.fail().
 * Se la conversione fallisce, richiede all'utente di reinserire il valore.
 * 
 * @return Il numero intero letto e validato
 */
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

/**
 * @brief Legge un numero floating-point dall'input con validazione
 * 
 * Questa funzione utilizza un ciclo per leggere l'input e controllare
 * se la conversione a float è andata a buon fine usando cin.fail().
 * Se la conversione fallisce, richiede all'utente di reinserire il valore.
 * 
 * @return Il numero floating-point letto e validato
 */
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