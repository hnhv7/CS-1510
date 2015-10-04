
template <typename T>
	ArrayList::~ArrayList();
	{
	  m_data = NULL;
	  delete m_data;
	} 

template <typename T>
	ArrayList::ArrayList<T>& operator=(const ArrayList<T>& rhs)
	{
	
	return 0;
	
	}

template <typename T>
	ArrayList::ArrayList(const ArrayList<T>& cpy)
	{
	  
	  return 0;
	
	  
	  
	}

/* ----- Basic Accessor Operations ----- */

template <typename T>
	int ArrayList<T>::size() const
	{
	  return m_size;
	}

template <typename T>
		const ArrayList::T& first() const
		{
		  if (m_data > 0)
		    return m_data[0];
		  else
		    
		}
template <typename T>
	ArrayList::T& operator[](int i);
	{
		
		return 0;
	
	}

template <typename T>
	const T& operator[](int i) const;
	{
	  return 0;
	
	  
	}

template <typename T>
	int find(const T& x)
	{
		return 0;
	
		
	}

/* ----- Basic Mutator Operations -----  */

template <typename T>
	void ArrayList::clear()
	{
		return 0;
	
		
	}

template <typename T>
	 void ArrayList::insert_back(const T& x)
	 {
		 return 0;
	
		 
	 }

template <typename T>
	void ArrayList::insert(const T& x, int i)
	{
		return 0;
	
		
	}

template <typename T>
	void remove(int i)
	{
		return 0;
	
		
	}

/* ----- Complex Mutator Operations ----- */

template <typename T>
	void ArrayList::swap(int i, int k)
	{
		return 0;
	
		
	}

template <typename T>
	void ArrayList::append(const ArrayList<T>& alist)
	{
		return 0;
	
		
	}

template <typename T>
	void ArrayList::purge()
	{
		return 0;
	
		
		
	}

/* ----- Complex Accessor Operations -----  */


template <typename T>
	friend std::ostream& operator<< <> (std::ostream& out, const ArrayList<T>& alist)
	{
		
		return 0;
	
	}
