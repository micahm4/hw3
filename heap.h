#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <utility>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m;
  PComparator comp;

};

// Add implementation of member functions here

//constructor 
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) 
  :m(m), comp(c)
{
  if (m < 2) {
    throw std:: invalid_argument("Heap must have at least 2 children");
  }
}

//destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

//empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return data.empty();
}

//size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data.size();
}

//push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  data.push_back(item);

  size_t curr = data.size() - 1;

  while (curr > 0 ){
    size_t p = (curr -1)/m;

    if (comp(data[curr], data[p])) {
      std::swap(data[curr], data[p]);
      curr = p;
    }
    else {
      break;
    }
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Can't access in empty heap");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
  throw std::underflow_error("Can't access in empty heap");

  }

  data[0] = data.back();
  data.pop_back();

  if (empty()) {
    return;
  }

  size_t curr = 0;

  while (true) {
    size_t firstC = curr * m + 1;

    if (firstC >= data.size()) {
      break;
    }

    size_t priorityC = firstC;

    for (int childNum = 1; childNum < m; childNum++) {
      size_t child = firstC + childNum;

      if (child < data.size() && comp(data[child], data[priorityC])) {
        priorityC = child;
      }
    }

    if (comp(data[priorityC], data[curr])) {
      std::swap(data[priorityC], data[curr]);
      curr = priorityC;
    }
    else {
      break;
    }

  }

}



#endif

