#ifndef PACKAGE2D_H
#define PACKAGE2D_H

#include "AbstractPackage.h"
#include <iostream>
#include <string>

using namespace std;


class Package2D : public AbstractPackage
{
  private:
  	float cost, area;
  public:
	Package2D(string f, string t) : AbstractPackage(f,t)
	{
	  
        }   
   	virtual float getCharge() const;
  	virtual const string& getFrom() const; 	
	virtual const string& getTo() const;	
	void Area(float length, float width);
	~Package2D(){}
};

#endif
