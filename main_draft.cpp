#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CIsoscelesTriangle.h"

using namespace std;

#define MAX_SHAPES 10

int main()
{
    Shape* shapes[MAX_SHAPES];
    int nShapes = 0;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

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
}