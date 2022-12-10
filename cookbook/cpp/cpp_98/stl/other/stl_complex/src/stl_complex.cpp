#include <iostream>
#include <vector>
#include <complex>

int main()
{
	std::complex<double> z(2.0, 2.0);
	std::cout<<"z="<<z<<"="<<std::norm(z)<<"e^{i"<<std::arg(z)<<"}"<<std::endl;
	std::cout<<"real(z)="<<std::real(z)<<std::endl;
	std::cout<<"im(z)="<<std::imag(z)<<std::endl;
	std::cout<<"\\bar{z}="<<std::conj(z)<<std::endl;
	std::cout<<"abs(z)=sqrt("<<std::real(z)<<"^2+"<<std::imag(z)<<"^2)="<<std::abs(z)<<std::endl;
	
	double e=std::real<double>(z);
	std::cout<<e<<std::endl;
	
	std::cout<<std::conj<double>(5)<<std::endl;
	std::cout<<std::real<double>(5)<<std::endl;
	
	return 0;
}
