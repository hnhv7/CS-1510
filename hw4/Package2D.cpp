#include "Package2D.h"
#include <string>
#include <iostream>
using namespace std;

virtual float Package2D::getCharge() const
{
  return cost;
}

virtual const string& Package2D::getFrom() const
{
  return m_from;
}

virtual const string& Package2D::getTo() const
{
  return m_to;
}

void Package2D::Area(float a, float b)
{
  int length = a;
  int width = b;
  area=length*width;	
  area = area * .05;
}
