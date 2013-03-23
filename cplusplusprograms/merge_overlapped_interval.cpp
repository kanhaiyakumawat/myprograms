#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct Interval
{
  int start;
  int end;
};

bool
compare (const Interval & i, const Interval & j)
{
  return i.start < j.start ? true : false;
}

void
merge_overlapped_interval (vector < Interval > &arr)
{
  if (arr.size () <= 0)
    {
      return;
    }
  sort (arr.begin (), arr.end (), &compare);
  stack < Interval > s;
  s.push (arr[0]);

  for (int i = 1; i < arr.size (); i++)
    {
      Interval current = s.top ();

      if (current.end < arr[i].start)
	{
	  s.push (arr[i]);
	}
      else if(current.end < arr[i].end)
	{
	  current.end = arr[i].end;
	  s.pop ();
	  s.push (current);
	}
    }

  while (!s.empty ())
    {
      cout << "[" << s.top ().start << ", " << s.top().end << "] ";
      s.pop ();
    }
  cout << endl;
  return;
}

int
main ()
{
  Interval intrvl[] = { {6, 8}, {1, 9}, {2, 4}, {4, 7} };
vector<Interval> arr(intrvl, intrvl + 4);
  merge_overlapped_interval (arr);
  return 0;
}
