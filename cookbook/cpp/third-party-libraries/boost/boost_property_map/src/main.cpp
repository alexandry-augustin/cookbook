#include <iostream>
#include <map>
#include <string>
#include <boost/property_map/property_map.hpp>
//---------------------------------------------------------
template <typename T>
void fct(T t)
{
	typedef typename boost::property_traits<T>::value_type value_type;
	typedef typename boost::property_traits<T>::key_type key_type;

	value_type old_address, new_address;
	key_type fred = "Fred";
	old_address = get(t, fred);
	new_address = "384 Fitzpatrick Street";
	put(t, fred, new_address);

	key_type joe = "Joe";
	value_type& joes_address = t[joe];
	joes_address = "325 Cushing Avenue";
}
//---------------------------------------------------------
int main()
{
	std::map<std::string, std::string> std_map;
	boost::associative_property_map<std::map<std::string, std::string> > prop_map(std_map);

	std_map.insert(std::make_pair(std::string("Fred"), std::string("710 West 13th Street")));
	std_map.insert(std::make_pair(std::string("Joe"), std::string("710 West 13th Street")));

	fct(prop_map);

	for(std::map<std::string, std::string>::iterator it=std_map.begin(); it!=std_map.end(); ++it)
		std::cout<<it->first<<":"<<it->second<<std::endl;

	return 0;
}
