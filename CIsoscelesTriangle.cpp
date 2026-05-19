/*! \file CIsoscelesTriangle.cpp
    \brief implementation of class IsoscelesTriangle
    \author Riccardo Cavagnaro Alessandro Fontanazzi
*/

#include "CIsoscelesTriangle.h"
#include <iostream>
#include <cmath>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
IsoscelesTriangle::IsoscelesTriangle() : Shape(IT_TYPE)
{
    cout << "IsoscelesTriangle - default constructor" << endl;
}

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
IsoscelesTriangle::IsoscelesTriangle(float px, float py, float w, float h) : Shape(px, py, w, h, IT_TYPE)
{
    cout << "IsoscelesTriangle - constructor" << endl;
}

/// @brief copy constructor
/// @param r reference to the object to be copied
IsoscelesTriangle::IsoscelesTriangle(const IsoscelesTriangle &r) : Shape(r)
{
    cout << "IsoscelesTriangle - copy constructor" << endl;
}

/// @brief destructor
IsoscelesTriangle::~IsoscelesTriangle()
{
    cout << "IsoscelesTriangle - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
IsoscelesTriangle& IsoscelesTriangle::operator=(const IsoscelesTriangle &r)
{
    if (this != &r) 
        Shape::operator=(r);

    return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two bounding boxes have the same width and the same length  
bool IsoscelesTriangle::operator==(const IsoscelesTriangle &r)
{
    return Shape::operator==(r);
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void IsoscelesTriangle::Init()
{
    Shape::Init(IT_TYPE);
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void IsoscelesTriangle::Init(const IsoscelesTriangle &r)
{
    Shape::Init(r);
}

/// @brief total reset of the object  
void IsoscelesTriangle::Reset()
{
    Shape::Reset();
}

/* ----------------------------
   GETTERS
   ---------------------------- */

/// @brief to get the side of the IsoscelesTriangle
/// @return width
float IsoscelesTriangle::GetSide()
{
    return (float) sqrt(pow(height/2, 2) + pow(width/2, 2));
}

/// @brief computes the area of the IsoscelesTriangle
/// @return area 
float IsoscelesTriangle::GetArea()
{
    return (width * height) / 2;
}

/// @brief computes the perimeter of the IsoscelesTriangle
/// @return perimeter 
float IsoscelesTriangle::GetPerimeter()
{
    return width + (GetSide() * 2);
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void IsoscelesTriangle::Dump()
{
    cout << endl <<  "----------------------" << endl;
    cout << "IsoscelesTriangle Dump:" << endl << endl;
	
	Shape::Dump();
	
    
    cout << "  Figure side:         " << GetSide() << endl;
    cout << "  Figure area:         " << GetArea() << endl;
    cout << "  Figure perimeter:    " << GetPerimeter() << endl;
    cout << "  Text:                " << (text ? text : "(null)") << endl;
	cout << endl;
}