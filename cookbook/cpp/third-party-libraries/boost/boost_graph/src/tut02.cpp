//http://www.codepedia.com/1/CppAdjacency_listTutorial1
#include <string>
#include <boost/graph/adjacency_list.hpp>

int main_02()
{
	typedef boost::adjacency_list
		<
		boost::vecS,
		boost::vecS,
		boost::directedS,
		boost::property<boost::vertex_name_t,std::string>
			> MyGraph;
	typedef boost::property_map<MyGraph, boost::vertex_name_t>::type MyNameMap;
	MyGraph myGraph;
	//Add vertices and add names
	{
		for (int i=0; i!=10; ++i) 
		{
			boost::add_vertex(myGraph);
			const std::string name(i+1,'x');
			std::cout << "Vertex name created: '" << name << "'." << std::endl;
			boost::put(boost::vertex_name,myGraph,i,name);
		}
	}
	//Get names
	{ 
		const MyNameMap myNameMap=boost::get(boost::vertex_name,myGraph);  
		typedef boost::graph_traits<MyGraph>::vertex_iterator VertexIterator;
		typedef std::pair<VertexIterator,VertexIterator> VertexRange;
		for (VertexRange i=boost::vertices(myGraph) ; i.first != i.second; ++i.first)
		{
			std::cout << "Vertex name found: '" << boost::get(myNameMap, *i.first) << "'." << std::endl;
		}
	}
}