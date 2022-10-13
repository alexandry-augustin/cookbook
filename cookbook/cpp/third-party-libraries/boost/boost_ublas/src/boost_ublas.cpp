#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp> //BLAS (Basic Linear Algebra Subprograms)
#include <boost/numeric/ublas/io.hpp>
//using namespace boost;
using namespace boost::numeric::ublas;
//using namespace std;

#include "storage_adaptors.hpp"

//http://www.guwi17.de/ublas/examples/

int main()
{
/*
	double initialValues[3][3] = {
		11, 12, 13,
		21, 22, 23,
		31, 32, 33
	};

	matrix<double> A(3, 3);
	A = make_matrix_from_pointer(initialValues);

	std::cout << "A=" << A << std::endl;
*/
	
	//vectors
	vector<double> w(2); 
	for(unsigned i=0; i <w.size(); ++i)
		w(i) = i;
	
	vector<double> v(2); 
		v(0) = 1; v(1) = 2;

	double c = norm_2(v);                  // euclidean norm
	c = norm_inf(v);                       // max-norm
	c = inner_prod(v,w);                   // inner product (scalar product)

	vector<double> x = w + 2.543*w;
	v += w*2.0;
	v -= w*2.0;
	//w=v;
	
	//matrices
    identity_matrix<double> I(3);
	zero_matrix<double> Z(3, 8);
	scalar_matrix<double> S(3, 3);
	
	matrix<double> n(2,2);
	for(unsigned int i = 0; i<n.size1(); ++i)
		for(unsigned int j = 0; j<n.size2(); ++j)
			n(i,j) = 2.0;

	matrix<double> m(2,2);
		m(0,0) = 0; m(0,1) = 1;
		m(1,0) = 2; m(1,1) = 3;
	
	
	//Mix
	v = prod(m, v); // matrix/vector product
	matrix<double> o = prod(m, n); // matrix/matrix product

	
	std::cout << n << std::endl;
}

//	//matrix_row<const matrix<double>  > mr (A, 0);

	//v.resize
