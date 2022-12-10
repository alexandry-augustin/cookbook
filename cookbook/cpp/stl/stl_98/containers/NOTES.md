```c++
std::pair
std::vector
std::list
std::deque

#adaptors
std::queue
std::priority_queue
std::stack

#associative
std::set		red-black tree
std::multiset
std::map		red-black tree
std::multimap

std::bitset
std::valarray

std::string
std::tuple
```

---

`std::vector<int &> v; //compile error`
The component type of containers like vectors must be Assignable.
References are not assignable (you can only initialize them once when they are declared,
and you cannot make them reference something else later). Other non-assignable types are also
not allowed as components of containers, e.g. vector<const int> is not allowed.

http://en.cppreference.com/w/cpp/concept/CopyAssignable
