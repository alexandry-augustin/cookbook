#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>

//see also boost.Bimap

struct Employee
{
	int         id;
	std::string name;
	int         age;

	Employee(int id_, std::string name_, int age_)
		: id(id_), name(name_), age(age_)
	{ }

	std::string str() const
	{
		std::stringstream ss;
		ss<<id<<" "<<name<<" "<<age;
		return ss.str();
	}
};

struct id{};
struct name{};
struct age{};
typedef boost::multi_index_container<
	Employee,
	boost::multi_index::indexed_by<
		boost::multi_index::ordered_unique<
			boost::multi_index::tag<id>, BOOST_MULTI_INDEX_MEMBER(Employee, int, id)>,
		boost::multi_index::ordered_non_unique<
			boost::multi_index::tag<name>, BOOST_MULTI_INDEX_MEMBER(Employee, std::string, name)>,
		boost::multi_index::ordered_non_unique<
			boost::multi_index::tag<age>, BOOST_MULTI_INDEX_MEMBER(Employee, int, age)
				, std::greater<BOOST_MULTI_INDEX_MEMBER(Employee, int, age)::result_type> //reverse order			
			>
		>
	> EmployeeSet;

//typedef boost::multi_index_container<
//	Employee,
//	boost::multi_index::indexed_by<
//		boost::multi_index::ordered_unique<
//			boost::multi_index::identity<int> >//,
////		boost::multi_index::ordered_non_unique<
////			boost::multi_index::tag<name>,BOOST_MULTI_INDEX_MEMBER(Employee, std::string, name)>,
////		boost::multi_index::ordered_non_unique<
////			boost::multi_index::tag<age>, BOOST_MULTI_INDEX_MEMBER(Employee, int, age)>
//		>
//	> EmployeeSet;

int main()
{
	{
		typedef typename boost::multi_index::index<EmployeeSet, name>::type	EmployeeSetByName;
		typedef typename boost::multi_index::index<EmployeeSet, id>::type	EmployeeSetById;
		typedef typename boost::multi_index::index<EmployeeSet, age>::type	EmployeeSetByAge;
		
		EmployeeSet es;
		//EmployeeSet::iterator it;
		EmployeeSetById& id_set=boost::multi_index::get<id>(es);
		EmployeeSetByName& name_set=boost::multi_index::get<name>(es);
		EmployeeSetByAge& age_set=boost::multi_index::get<age>(es);
		
		es.insert(Employee(0, "Joe" ,31));
		es.insert(Employee(1, "Robert" ,27));
		es.insert(Employee(2, "John", 40));
		es.insert(Employee(2, "Aristotle", 2387)); //will fail, id already exist
		es.insert(Employee(3, "Albert", 20));
		es.insert(Employee(4, "John", 57));
		
		for(EmployeeSetById::iterator it=id_set.begin(); it!=id_set.end(); ++it)
			std::cout<<it->str()<<std::endl;
		std::cout<<"==================="<<std::endl;
		
		for(EmployeeSetByName::iterator it=name_set.begin(); it!=name_set.end(); ++it)
			std::cout<<it->str()<<std::endl;
		std::cout<<"==================="<<std::endl;
		
		for(EmployeeSetByAge::iterator it=age_set.begin(); it!=age_set.end(); ++it)
			std::cout<<it->str()<<std::endl;
		std::cout<<"==================="<<std::endl;
		
		{
			EmployeeSetByName::iterator it=name_set.find("John");
			assert(it!=name_set.end());
			std::cout<<it->str()<<std::endl;
		}
		{
			EmployeeSetByAge::iterator it=age_set.find(27);
			assert(it!=age_set.end());
			std::cout<<it->str()<<std::endl;
			Employee employee=*it;
//			es.erase(employee); //nok
			age_set.erase(it);
//			age_set.erase(employee); //nok
		}
	}
	
	return 0;
}