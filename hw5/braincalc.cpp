#include <iostream>
#include <string>
#include <cstdlib>
#include "AbstractStack.h"
using namespace std;
#ifndef BRAINCALC_CPP
#define BRAINCALC_CPP


template < typename T>
class myStack : public AbstractStack<int>
{ 
 private:
   T m_data;
   myStack* m_next=NULL;
 public:
  friend std::ostream& operator<< (std::ostream& out, const myStack<int>& list);
 
  virtual bool isEmpty() const
   {
     return (m_next == NULL);
   }
 
  virtual const T& top() const throw ( Oops )
   {
     string m_msg = "Error - Top of the stack is empty!!";

     if ( m_next != NULL)
       return m_data;
     else
         throw m_msg;
   }
  
  virtual void push(const T& x)
   { 
     myStack* temp = new myStack;
     temp -> m_data = m_data;
     temp -> m_next = m_next;
     m_data = x;
     m_next = temp;
   }
 
  virtual void pop()
   {
    myStack* temp = m_next;
    if ( temp != NULL)
     {
       m_next = temp -> m_next;
       m_data = temp -> m_data;
       delete temp;
     }
   }
  virtual void clear()
   {
     while (m_next != NULL)
      pop();
   }

};



std::ostream& operator<< (std::ostream& out, const myStack<int>& list)
{
  out << "[ ";
  const myStack<int>* temp = &list;
	  while ( temp -> m_next != NULL)
		{
		  out << temp -> m_data;      
		  temp = temp -> m_next;
		  if ( temp -> m_next != NULL)
		  	cout << ", ";
		}
	  out << " ]";
	  return out;
}


int main()
{

  myStack<int> a;
  string s1;
  int x,p1,p2;  

	try
	  {
do
 { 
  cin >> s1;
  x = atoi( s1.c_str() );

if (s1 == "+")
  {
    p1 = a.top();
    a.pop();
    p2 = a.top();
    a.pop();
    x = p1 + p2;
    a.push(x);
  }

else if (s1 == "-")
  {
    p1 = a.top();
    a.pop();
    p2 = a.top();
    a.pop();
    x = p2 - p1;
    a.push(x);
  }
else if (s1 == "/")
  {
    p1 = a.top();
    a.pop();
    p2 = a.top();
    a.pop();
    x = p2 / p1;
    a.push(x);
  }
else if (s1 == "*")
  {
    p1 = a.top();
    a.pop();
    p2 = a.top();
    a.pop();
    x = p1 * p2;
    a.push(x);
  }  
else if ( s1 == "X") 
  {
	cout << a;
  }
else if ( s1 == "C")
  {
    a.clear();
  }
/*else if ( s1 == "S")
  {

      while (! a.isEmpty()) 
       {     cout << "kHI";
         p1 = a.top();
         a.pop();
         p2 = a.top();
         a.pop();
         x = p1 + p2;
         a.push(x);       
       } 
  }
  */
else if ( s1 == "!")
  {
    x=a.top();
    a.pop();
    x=x*-1;
	a.push(x);
  }

else
  {
    a.push(x);
  }


 }
  while (s1 != "$");
  
	  }
	catch (string x)
	  {

	  }
return 0;
}

#endif
