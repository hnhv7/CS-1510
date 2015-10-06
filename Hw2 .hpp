
#include <iostream>
using namespace std;

template <typename T>
	ArrayList<T>::~ArrayList()
	{
	  delete m_data[];
	  m_data=NULL;
	} 

template <typename T>
	ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
	{
	  if(this != &rhs)
	    clear();
	    m_size=rhs.m_size;
	    m_max=rhs.m_max;
	    m_data= new T[m_max];
	    for (int i = 0; i < m_size; i++)
            m_data[i] = rhs[i];
	  return *this;
	}

template <typename T>
	ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
	{
	   m_size = cpy.m_size;
    m_max = cpy.m_max;
    m_data = new T[m_max];
    for (int i = 0; i < m_size; i++)
        m_data[i] = cpy[i]; 
	}

/* ----- Basic Accessor Operations ----- */

template <typename T>  // Array Size
	int ArrayList<T>::size() const
	{
	  return m_size;
	}

template <typename T> // Array's First Element
		const T& ArrayList<T>::first() const
		{
		  if (m_data > 0)
		    return m_data[0];
		  else
		  {
		    cout <<"!-- ERROR : PANIC in ARRAYLIST.first()!!";
		    return m_errobj;
		  }
		    
		    
		}
template <typename T>
	T& ArrayList<T>::operator[](int i)
	{
	  if (i>=0 && i<m_size)
	    return m_data[i];
	   cout <<"!-- ERROR : PANIC in ARRAYLIST.operation[]!!";
		    return m_errobj;	
	}

template <typename T>
	const T& ArrayList<T>::operator[](int i) const
	{
	  if (i>=0 && i<m_size)
	    return m_data[i];
	   cout <<"!-- ERROR : PANIC in ARRAYLIST.operation[] const!!";
		    return m_errobj;	  
	}

template <typename T>
	int find(const T& x)
	{
	  for (int i; i< m_size; i++ )
		if (x==m_data[i])
		  return i;
	  return -1;
	}

/* ----- Basic Mutator Operations -----  */

template <typename T>
	void ArrayList<T>::clear()
	{
	  delete m_data[];
	  m_data=NULL;
	  m_size=0;
	  m_max=0;		
	}

template <typename T>
	 void ArrayList<T>::insert_back(const T& x)
	 {
	   insert(x, m_size);
		 
	 }

template <typename T>
	void ArrayList<T>::insert(const T& x, int i)
	{
	  if (i<0 || i>m_size)
	  {
	    cout <<"!-- ERROR : PANIC in ARRAYLIST.insert()!!";
		    return m_errobj;
      }
	  if(m_size==m_max)
	    {
	      T* tmp = new T[m_max*2];
		  m_max=m_max*2;
		  for (int k=0; k<m_size; k++)
		    tmp[k]=m_data[k];
		  delete m_data[];
		  m_data=tmp;		
		}
   	  for (int i=0; i<m_size; i--)
   	   m_data[i]=m_data[i-1];
      m_data[i]=x;
	  m_size++;		
	}

template <typename T> // Removes an element
	void remove(int i)
	{
	  if (i<0 || i>m_size)
	   {
	    	cout <<"!-- ERROR : PANIC in ARRAYLIST.remove()!!";
		    return m_errobj;
	   }
       if(m_size==(m_max/4))
         {
           T* tmp = new T[m_max/2];
		   m_max=m_max/2;
		   for (int k=0; k<m_max; k++)	
         	 tmp[k]=m_data[k];
           delete m_data[];
           m_data=tmp;
		 }
	   for (int k=0; k<m_size; k++)
	     m_data[k]=m_data[k+1];
	   m_size--;
	}

/* ----- Complex Mutator Operations ----- */

template <typename T>
	void ArrayList<T>::swap(int i, int k)
	{
	  if (i>0 && k>0 && i<m_size && k<m_size)
	  {
		  T s=0;
		  s=m_data[i];
		  m_data[i]=m_data[k];
		  m_data[k]=s;
	  }
	  else 
	    cout <<"!-- ERROR : PANIC in ARRAYLIST.swap()!!";
		    return m_errobj;
	  
	}

template <typename T>
	void ArrayList<T>::append(const ArrayList<T>& alist)
	{
	  for (int i=0; i<alist.m_size;i++)
	    insert_back(alist[i]);
	}

template <typename T>
	void ArrayList<T>::purge()
	{
	  for (int i =0; i<m_size; i++)
		for (int j=i+1; j<m_size; j++)
		  if (m_data[i]==m_data[j])
		    remove(j);
	}
