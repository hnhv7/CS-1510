#include <iostream>
using namespace std;


    
 
template <typename T>
	const LinkedList<T>& LinkedList<T>:: operator= (const LinkedList<T>& rhs)
	  {
	const LinkedList* current = &rhs;
	LinkedList* temp = this;
	while (current != NULL)
	{
	  m_data = current -> m_data;

	  current = current -> m_next;	
	  
	}

return *this;

/*
		LinkedList* tmp;
			  	this -> m_next = tmp;

	  while (m_next != NULL)
	  { cout << "Here" << m_data << endl;
	  LinkedList* temp;
	this -> m_next = temp;
	  	m_data=rhs.m_data;
	  	this -> m_next = temp -> m_next;
delete temp;
	  	
	  }
return *this;*/
	  }
    


template <typename T>
	LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
	 {/*
       LinkedList* temp=this;
	   const LinkedList* source = rhs.m_data;
	   
	   while (temp -> m_next != NULL)
	    { 
	    	         cout << "cpyHere!" << endl;

	   	  temp.m_data = source.m_data;
	   	  temp = temp->m_next;
	   	  source = source -> m_next;
	   	  
		}	 	
	 	*/
	 }



  //  ---- Basic Accessor Operations ---

	  // Size of the Linked List
template <typename T>
    int LinkedList<T>::size () const
    {
      int count=0;
      const LinkedList<T>* temp;
	  temp = this;
      
      while (temp -> m_next != NULL)	
    	{
    	  count++;
    	  temp = temp -> m_next;    		
		}
      return count;
	}
	
   // Determines if the LinkedList is empty
   // Return true if empty, else false
template <typename T>
	bool LinkedList<T>::isEmpty() const
	 {
	   const LinkedList* p = this;
	   if (m_next == NULL)
	     return true;
	   else 
	     return false;	 	
	 }
	 
	 // Finds the value of the first element of the LinkedList
template <typename T>
	LinkedList<T>* LinkedList<T>::getFirstPtr()
	 {
	   LinkedList* p = this;
	   if (m_next == NULL)
	     {
	       cout << "!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list" << endl;
	       return NULL;
	     }
	   else 
	     return this;
	 }
	 
	 // Finds the last element of the LinkedList
template <typename T>
	LinkedList<T>* LinkedList<T>::getLastPtr()
	 {
	   LinkedList* p = this;
	   LinkedList* second = this;

	   if (m_next == NULL)
	     {
	       cout << "!!-- ERROR : PANIC in LINKEDLIST.getLastPtr() - empty list" << endl;
	       return NULL;
	     }
	   else
	   {
	   	p = p -> m_next;
	     while(p -> m_next != NULL)
	       {
	       	 p = p -> m_next;
	       	 second = second -> m_next;
		   }
		return second;
	    }
	 }
	 
	 // Find "i" element of the LinkedList
template <typename T>
	LinkedList<T>* LinkedList<T>::getAtPtr(int i)
	 {
	 	if(i > size())
	 	  {
	 	  	cout << "!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - invalid index" << endl;
	 	  	return NULL;	 	  	
		  }
		  
	   LinkedList* p = this;
	   LinkedList* second = this;
	   int count=0;
	   if (m_next == NULL)
	     return NULL;
	   else
	   {	
         while (count != i)
         {
           count++;
           p = p -> m_next;
         }
	   }
	   return p;
	 }

    // ---- Basic Mutator Operations ---

    // Clears all elements of the LinkedList
template <typename T>
    void LinkedList<T>::clear()
     {
       LinkedList* p=this;	
       while (p-> m_next != NULL )	
     	{
     	  p=this;
		  remove(p);	
		}	
	 }

    //insert element to the front of the array
template <typename T>
	void LinkedList<T>::insert_front(const T& x)
	{
	  LinkedList<T> * temp = new LinkedList(m_data, m_next); 
      m_next = temp;
      m_data = x;
	}

	// Insert element 'x' at position "pos"
template <typename T>	
    void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
      {

      	LinkedList<T> * temp = new LinkedList; // Creates new container
      	temp -> m_data = pos -> m_data;  // The data in pos is now also in temp
      	temp -> m_next = pos -> m_next;  // Temp.m_next points to the same spot as pos.m_next
      	pos -> m_next = temp;  // 
      	pos -> m_data = x;     	
	  }
    
    // Removes an element at position "pos"
template <typename T> 
    void LinkedList<T>::remove(LinkedList<T>* pos)
     {
     	LinkedList* temp = pos -> m_next;
     	pos -> m_data = temp -> m_data;
     	pos -> m_next = temp -> m_next;
     	delete temp;
     	
	 }
	 
	 
    // ---- Basic Mutator Operations ---
    
  /*
template <typename T>
	bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
	  {
	  	LinkedList<T>* first;
	  	LinkedList<T>* second;
	  	
	  	if(size(first) != size(second))
	  	  return false;
	  	
	  	while (first -> m_next != NULL)
	  	  if (first -> m_data != second -> m_data)
	  	    return false;
	  	  else return true;
		  
		  

	  }
    */
    // Checks to see if an element "x" is in the LinkedList
    // If so returns pointer to element "x"
    // Else return NULL
template <typename T>
	LinkedList<T>* LinkedList<T>::find(const T& x)
	  {
	  	LinkedList* temp = this;
	  	while (temp -> m_next != NULL)
	  	  {
	  	    if (temp -> m_data == x)
			  return temp;
			temp = temp -> m_next;	
		  }
		return NULL;  	
	  }
	  
	  
	 
template <typename T>
	void LinkedList<T>::reverse()
	 {
	 	LinkedList* head = getFirstPtr();
	 	LinkedList* current = head;
	 	LinkedList* prev = NULL;
	 	LinkedList* next = NULL;

	 	while(current != NULL)
	 	 { 
	 	   m_next = current -> m_next;
	 	   current -> m_next = prev;
	 	   prev= current;
	 	   current = m_next;
		  }
	 	head -> m_data = prev -> m_data;
	 	
	 }
	 
template <typename T>
	void LinkedList<T>::append(const LinkedList<T>& xlist)
	 {
	 	
	 /*
	 cout << xlist <<endl;
	 cout << "Hello!" <<endl;
	 /*	
	 	   LinkedList* p = this;
	   LinkedList* second = this;
	   T* list;
	   list = &xlist;
	   	p = p -> m_next;
	     while(p -> m_next != NULL)
	       {
	       	 p = p -> m_next;
	       	 second = second -> m_next;
		   }
	    
	 	
	 /
	 	
	 *
	  LinkedList<T>* temp =&this -> m_next;
	  while ( temp != NULL)
	    temp = temp -> m_next;
      temp -> m_next =  &xlist;
	  	*/
	 	
	 }
	 
