#ifndef MyHeap_H
#define MyHeap_H

#include <iostream>

using namespace std;

typedef enum
{ MAX_HEAP, MIN_HEAP } HeapType;
template < typename T > class MyHeap
{
public:
MyHeap (long _size, HeapType _type = MAX_HEAP):
  m_size (_size), m_type (_type)
  {
    m_last = -1;
    m_array = new T[m_size];
  }
  ~MyHeap ()
  {
    delete[]m_array;
  }
  bool upheap (T _item);
  bool downheap ();
  T top ()
  {
    return m_array[0];
  }
  void print ()
  {
    for (int i = 0; i <= m_last; i++)
      {
	cout << m_array[i] << " ";
      }
    cout << "\n";
  }
private:
  void maxheapyfy ();
  void minheapyfy ();
  bool is_valid (const long i)
  {
    return i >= 0 && i <= m_last;
  }
  long get_parent (const long _child)
  {
    if (_child % 2 == 0)
      {
	return (_child / 2) - 1;
      }
    else
      {
	return _child / 2;
      }
  }
  long get_left_child (long i)
  {
    return 2 * i + 1;
  }
  long get_right_child (long i)
  {
    return 2 * i + 2;
  }
  void swap (T & a, T & b)
  {
    T temp = a;
    a = b;
    b = temp;
  }
  long m_size;
  HeapType m_type;
  long m_last;
  T *m_array;
};

template < typename T > bool MyHeap < T >::upheap (T _item)
{
  if (m_last == (m_size - 1))
    {
      cout << "ERROR HEAP OVERFLOW\n";
      return false;
    }
  else
    {
      m_array[++m_last] = _item;
      m_type == MAX_HEAP ? maxheapyfy () : minheapyfy ();
    }
  return true;
}

template < typename T > bool MyHeap < T >::downheap ()
{
  if (m_last < 0)
    {
      cout << "ERROR: HEAP UNDERFLOW\n";
      return false;
    }
  else
    {
      m_array[0] = m_array[m_last--];
      m_type == MAX_HEAP ? maxheapyfy () : minheapyfy ();
    }
  return true;
}

template < typename T > void MyHeap < T >::maxheapyfy ()
{
  for (long i = m_last / 2; i >= 0; i--)
    {
      long current = i;
      while ((is_valid
	      (get_left_child (current))
	      && m_array[current] < m_array[get_left_child (current)])
	     ||
	     (is_valid
	      (get_right_child (current))
	      && m_array[current] < m_array[get_right_child (current)]))
	{
	  long max = get_left_child (current);
	  if (is_valid (get_right_child (current))
	      && m_array[get_right_child (current)] > m_array[max])
	    {
	      max = get_right_child (current);
	    }
	  swap (m_array[current], m_array[max]);
	  current++;
	}
    }
}

template < typename T > void MyHeap < T >::minheapyfy ()
{
  for (long i = m_last / 2; i >= 0; i--)
    {
      long current = i;
      while ((is_valid
	      (get_left_child (current))
	      && m_array[current] > m_array[get_left_child (current)])
	     ||
	     (is_valid
	      (get_right_child (current))
	      && m_array[current] > m_array[get_right_child (current)]))
	{
	  long max = get_left_child (current);
	  if (is_valid (get_right_child (current))
	      && m_array[get_right_child (current)] < m_array[max])
	    {
	      max = get_right_child (current);
	    }
	  swap (m_array[current], m_array[max]);
	  current++;
	}
    }
}

#endif
