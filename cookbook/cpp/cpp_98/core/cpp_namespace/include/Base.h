
namespace base {

struct Base // can't be "base" cf rem[0]
{
	enum Type
	{
		BASE_A=0
	};
	int n;
	Base::Type type;
	Base(int n_=0): n(n_), type(Base::BASE_A) { }
	int get() const;
};

// rem [0]: "A namespace-name or namespace-alias shall not be declared as the name of any other entity in the same
// declarative region. A namespace-name defined at global scope shall not be declared as the name of any
// other entity in any global scope of the program."  [7.3.2/4] p114

struct Sub
{
	Base b;
	int get() const;
	Sub(int n_=0): b(n_) { }
};
namespace base {

struct factory
{
	static Base* get(int n) { return new Base(n); }
};

} //namespace base
} //namespace base

namespace base0 {

struct Base0
{
	base::Base b;
};

} //namespace base0
