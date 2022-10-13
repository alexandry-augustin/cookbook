class Base;

typedef int Int; //ok
//typedef typename int Int; //not ok
typedef Int* int_ptr; //ok
//typedef typename Int* int_ptr_; //not ok

typedef Base base; //ok
//typedef typename Base base_;  //not ok
typedef Base* base_ptr; //ok
//typedef typename Base* base_ptr_; //not ok
