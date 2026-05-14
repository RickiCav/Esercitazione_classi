/*! \file CRhombus.cpp
    \brief implementation of class Rhombus
    \author Riccardo Cavagnaro Alessandro Fontanazzi
*/

#include "CRhombus.h"
#include <iostream>
#include <cmath>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
Rhombus::Rhombus() : Shape()
{
    cout << "Rhombus - default constructor" << endl;
}

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
Rhombus::Rhombus(float px, float py, float w, float h) : Shape(px, py, w, h)
{
    cout << "Rhombus - constructor" << endl;
}

/// @brief copy constructor
/// @param r reference to the object to be copied
Rhombus::Rhombus(const Rhombus &r) : Shape(r)
{
    cout << "Rhombus - copy constructor" << endl;
}

/// @brief destructor
Rhombus::~Rhombus()
{
    cout << "Rhombus - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
Rhombus& Rhombus::operator=(const Rhombus &r)
{
    if (this != &r) 
        Shape::operator=(r);

    return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two bounding boxes have the same width and the same length  
bool Rhombus::operator==(const Rhombus &r)
{
    return Shape::operator==(r);
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void Rhombus::Init()
{
    Shape::Init();
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Rhombus::Init(const Rhombus &r)
{
    Shape::Init(r);
}

/// @brief total reset of the object  
void Rhombus::Reset()
{
    Shape::Reset();
}

/* ----------------------------
   GETTERS
   ---------------------------- */

/// @brief to get the side of the Rhombus
/// @return width
float Rhombus::GetSide()
{
    return (float) sqrt(pow(height/2, 2) + pow(width/2, 2));
}

/// @brief computes the area of the Rhombus
/// @return area 
float Rhombus::GetArea()
{
    return (width * height) / 2;
}

/// @brief computes the perimeter of the Rhombus
/// @return perimeter 
float Rhombus::GetPerimeter()
{
    return GetSide() * 4;
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void Rhombus::Dump()
{
    cout << endl <<  "----------------------" << endl;
    cout << "Rhombus Dump:" << endl << endl;
	
	Shape::Dump();
	
    
    cout << "  Figure area:         " << GetArea() << endl;
    cout << "  Figure perimeter:    " << GetPerimeter() << endl;
    cout << "  Text:                " << (text ? text : "(null)") << endl;
	cout << endl;
}