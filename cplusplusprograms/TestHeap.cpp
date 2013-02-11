#include "MyHeap.h"

int main()
{
MyHeap<int> heap(10);
heap.upheap(6);
heap.print();
heap.upheap(16);
heap.print();
heap.upheap(7);
heap.print();
heap.upheap(14);
heap.print();
heap.upheap(3);
heap.print();
MyHeap<int> heap1(10, MIN_HEAP);
heap1.upheap(6);
heap1.print();
heap1.upheap(16);
heap1.print();
heap1.upheap(7);
heap1.print();
heap1.upheap(14);
heap1.print();
heap1.upheap(3);
heap1.print();
return 0;
}
