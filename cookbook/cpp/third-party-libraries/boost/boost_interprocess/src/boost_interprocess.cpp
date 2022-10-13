#include <cassert>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/mapped_region.hpp>
//---------------------------------------------------------
// header only
// /dev/shm
//---------------------------------------------------------
class base_00
{
	int _n;
public:
	base_00(int n): _n(n) { }
	int get() const { return _n; }
	void set(int n) { _n=n; }
};
//---------------------------------------------------------
void shm()
{
	{
		//create /dev/shm/base_shm_00 of size 0
		//TODO boost::interprocess::open_only
		boost::interprocess::shared_memory_object shm(boost::interprocess::open_or_create, "base_shm_00", boost::interprocess::read_write); 

		//resize shm
		shm.truncate(1024); // throws boost::interprocess::interprocess_exception

		assert(shm.get_name()==std::string("base_shm_00"));

		boost::interprocess::offset_t size; 
		shm.get_size(size);
		assert(size=1024);

		boost::interprocess::mapped_region region_00(shm, boost::interprocess::read_write); 
		boost::interprocess::mapped_region region_01(shm, boost::interprocess::read_only); 
		assert(region_00.get_address()!=region_01.get_address());
		assert(region_00.get_size()==1024);
		assert(region_01.get_size()==1024);

		int* p_00=static_cast<int*>(region_00.get_address()); 
		int* p_01=static_cast<int*>(region_01.get_address()); 
		*p_00=99; 
		assert(p_01!=p_00); 
		assert(*p_01==*p_00); 

		//If remove() is not being called on UNIX, the shared memory continues to exist even if the application is terminated (until reboot)
		//On windows/OSX, it will never be removed even after reboot
		assert(boost::interprocess::shared_memory_object::remove("base_shm_00"));  //remove from /dev/shm/
	}
	{
		boost::interprocess::shared_memory_object shm(boost::interprocess::open_or_create, "base_shm_00", boost::interprocess::read_write); 
		shm.truncate(1024);
		boost::interprocess::mapped_region region(shm, boost::interprocess::read_write); 
		base_00 b(9);

		base_00* p=static_cast<base_00*>(region.get_address()); 
		*p=b;
		

		assert(boost::interprocess::shared_memory_object::remove("base_shm_00"));
	}
}
//---------------------------------------------------------
void managed_shm()
{
	{
		boost::interprocess::managed_shared_memory shm(boost::interprocess::open_or_create, "base_shm_00", boost::interprocess::read_write); 

		int* p_00=shm.construct<int>("obj_00")(99); 
		assert(*p_00==99);

		std::pair<int*, std::size_t> p_01=shm.find<int>("obj_00");
		assert(*p_01.first==99);

		assert(shm.find<int>("unknown").first==0);
		assert(shm.find<int>("unknown").second==0);

		int *i = shm.construct<int>("obj_01")[10](99); //array of 10 elts
		//all 10 elts are initialized with the value 99.
		//It is not possible to initialize individual elements with different values.
		assert(*i==99);
		std::pair<int*, std::size_t> p=shm.find<int>("obj_01"); 
		assert(*p.first==99);
		assert(p.second==10);

		assert(boost::interprocess::shared_memory_object::remove("base_shm_00"));
	}
}
//---------------------------------------------------------
int main()
{
	shm();
	//managed_shm();
	return 0;
}
