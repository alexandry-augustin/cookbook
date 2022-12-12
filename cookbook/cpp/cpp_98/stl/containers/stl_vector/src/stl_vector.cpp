#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

// cf std::copy for easy std::cout

class myClass
{
public:
    int m_n;
    myClass(int n): m_n(n) { std::cout<<"constructed"<<std::endl; }
    ~myClass() { std::cout<<"destructed"<<std::endl; }
};

template<typename T>
class myClassTemplate
{
public:
    std::vector<T> m_v;
    myClassTemplate() { std::cout<<"constructed"<<std::endl; }
    //http://social.msdn.microsoft.com/Forums/en-US/vcgeneral/thread/cb7f9977-34d1-46bc-a2a5-78285d85ea5a/
    //When you're using a type from within a templated class, which depends on the template parameters, 
    //you need to use the "typename" keyword.
    //void assign(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last)
    void assign(T* first, T* last)
    { 
        m_v.assign(first, last); 
    }
    ~myClassTemplate() { std::cout<<"destructed"<<std::endl; }
};

void print1(const std::vector<int> &v)
{
    std::vector<int>::iterator i;  //random access iterator
    
    for(unsigned int i=0; i<v.size(); ++i)
        std::cout<<v[i]<<" ";
    std::cout<<std::endl;
}

void print2(std::vector<int> &v)
{
    std::vector<int>::iterator i;  //random access iterator

    for(i=v.begin(); i!=v.end(); ++i) 
        std::cout<<*i<<" ";
    std::cout<<std::endl;
}

void print3(std::vector<int> &v)
{
    copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
}

int main()
{
    {
        // std::vector<int &> v; //compile error

        // "The component type of containers like vectors must be Assignable.
        // References are not assignable (you can only initialize them once when they are declared,
        // and you cannot make them reference something else later). Other non-assignable types are also
        // not allowed as components of containers, e.g. vector<const int> is not allowed." 
        // -- http://en.cppreference.com/w/cpp/concept/CopyAssignable
    }
    {
        int a[] = {1, 2, 3};
        std::vector<int> v(a, a+3);
        v.erase(v.begin()+1);
        assert(v[0]==1);
        assert(v[1]==3);
    }
    std::vector<int> v;
    std::cout<<v.size()<<std::endl;
    std::vector<int> w(5); //5 int of value 0
    std::vector<myClass> x(5, myClass(2)); //5 int of value 2
    x.assign(2,myClass(3)); //assigne 2 int of value 3
    std::vector<int> y(v); //copy of v
    std::vector<int> z(w.begin(), w.end());
    z.assign(w.begin(), w.end());
    //print1(w);

    std::vector<int> ab(5); for(unsigned int i=0; i<ab.size(); ++i) ab[i]=i;
    std::vector<int> aa(ab.begin(), ab.begin()+4);
    print1(ab);
    print1(aa);

    aa.insert(aa.begin(), 99);
    aa.insert(aa.end(), w.begin(), w.end());
    print1(aa);

    y=z; //deep copy

    std::cout<<w.size()<<std::endl;

    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> m(b+2, b+4); //b[2] to b[4-1]

    std::swap(w,m); //Assigns the content of a to b and the content of b to a.
    m.pop_back();   //Remove last element
    m.erase(m.begin()+2);
    print2(w);

    for(unsigned int i=0; i<w.size(); ++i)
        if(true==true)
        {
            w.erase(w.begin()+i);
            --i;
        }

    v.clear();//remove all elements
    // 2 dimensions
    //a_{row,col}=a_{ij}=a[row][colummn]

    int nbColumns=3; 
    int nbRows=2; 

    std::vector<std::vector<int> > a(nbRows, std::vector<int>(nbColumns));
    for(int row=0; row<a.size(); ++row)
        for(int column=0; column<a[row].size(); ++column)
            a[row][column]=row*nbRows+column;
    //or



    //display
    for(int row=0; row<a.size(); ++row)
    {
        for(int column=0; column<a[row].size(); ++column)
            std::cout<<a[row][column]<<", ";
        std::cout<<std::endl;
    }
    
    myClassTemplate<int> u;
    u.assign(b, b+4);
    print1(u.m_v);
    
    //std::vector<int> v(5); //reserve for 5 elts
    
    std::vector<int> v;
    
    for(int i=0; i<15; ++i) v.push_back(0);
    
    std::cout<<"[size:"<<v.size()<<" elts.]"<<std::endl;
    
    std::vector<int>::size_type capacity=v.capacity();
    std::cout<<"[capacity:"<<v.capacity()<<" elts.] [2^{size-2}="<<pow(2, v.size()-2)<<"]"<<std::endl;
    
    //maximum number of elements that the std::vector can hold.
    std::cout<<"[max_size:"<<v.max_size()<<" elts.]"<<std::endl;
    
//  std::vector::reserve //storage pre-allocation
    
    {
        int a[]={1, 2, 3 };
        std::vector<int> v(a, a+3);
    
        v.insert(v.begin()+1, 0);
        assert(v[1]==0);

        v.insert(std::find(v.begin(), v.end(), 2)+1, 9);
        assert(v[3]==9);
    
        assert(v.size()==5);
    }
    {
        int nbRows=4;
        int nbColumns = 3;

        std::vector<bool> row(nbColumns, false);
        std::vector< std::vector<bool> > matrice;
        matrice.insert(matrice.begin(), nbRows, row); 

        matrice[3][2]=true;

        for(int i=0; i<matrice.size(); ++i)
        {
            for(int j=0; j<matrice[i].size(); ++j)
                std::cout << matrice[i][j] << " ";
            std::cout<<std::endl;
        }
    }
    
    return 0;
}
