#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

struct BaseVertex
{
	std::string name;
	//...
};

struct BaseEdge
{
	double weight;
	//...
};

// 
//                 A -> B -> C 
// 

/// default graph

void default_graph()
{
	boost::adjacency_list<> g;
	assert(boost::num_vertices(g)==0);
	assert(boost::num_edges(g)==0);
	
	//optional:
	//	boost::add_vertex(g);
	//	boost::add_vertex(g);
	//	boost::add_vertex(g);
	//	assert(boost::num_vertices(g)==3);
	
	boost::add_edge(0, 1, g);
	boost::add_edge(1, 2, g);
	assert(boost::num_edges(g)==2);
	assert(boost::num_vertices(g)==3);
	
//	boost::graph_traits<boost::adjacency_list<> >::vertex_iterator
//		vertex_it=boost::vertices(g).first;
	boost::adjacency_list<>::vertex_iterator vertex_it;
	boost::adjacency_list<>::vertex_iterator vertex_end;
	
	vertex_it=boost::vertices(g).first;
	vertex_end=boost::vertices(g).second;
	//or
	boost::tie(vertex_it, vertex_end)=boost::vertices(g);
	
	std::cout<<"[vertices] ";
	for(; vertex_it!=vertex_end; ++vertex_it) 
		std::cout<<"["<<*vertex_it<<"] ";
	std::cout<<std::endl;
	
//	boost::graph_traits<boost::adjacency_list<> >::adjacency_iterator
//		adjacency_it=boost::adjacent_vertices(*vertex_it, g).first;
	boost::adjacency_list<>::adjacency_iterator adjacency_it;  //iterate throught out-edges of a given vertex
	boost::adjacency_list<>::adjacency_iterator adjacency_end;
	
	std::cout<<"[edges] ";
	for(vertex_it=boost::vertices(g).first; vertex_it!=vertex_end; ++vertex_it) 
	{
		//boost::tie(adjacency_it, adjacency_end)=boost::adjacent_vertices(*vertex_it, g); 
		//for(; adjacency_it!=adjacency_end; ++adjacency_it) 
		//	std::cout<<"["<<*vertex_it<<"->"<<*adjacency_it<<"] "; 
		//or
		for(adjacency_it=boost::adjacent_vertices(*vertex_it, g).first; adjacency_it!=boost::adjacent_vertices(*vertex_it, g).second; ++adjacency_it) 
			std::cout<<"["<<*vertex_it<<"->"<<*adjacency_it<<"] "; 
	}
	std::cout<<std::endl;
	
//	boost::property_map<boost::adjacency_list<>, boost::vertex_index_t>::type
//		c;
	
	// write on std ouput
	//write_graphviz(std::cout, g); 
	// write on file
	std::ofstream of("graph.gv");
	write_graphviz(of, g);
}

/// custom properties graph (01)

//struct custom_vertex_prop_01_t
//{
//	typedef edge_property_tag kind;
//};

void custom_properties_graph_01()
{
	//	typedef boost::adjacency_list<
	//		boost::listS,
	//		boost::vecS,
	//		boost::bidirectionalS,
	//		// Vertex properties
	//		boost::property<boost::vertex_name_t, std::string, 
	//		boost::property<custom_vertex_prop_01_t, int,
	//		boost::property<custom_vertex_prop_02_t, std::vector<int> > > >,
	//		// Edge properties
	//		boost::property<boost::edge_name_t, std::string,
	//		boost::property<boost::edge_length_t, double,
	//		boost::property<custom_edge_prop_01_t, int,
	//		boost::property<custom_edge_prop_02_t, bool> > > >,
	//		> BaseGraph_t;
	
	//	BaseGraph_t g;
	
	//	boost::put(boost::vertex_name, g, 0, "A");
	//	boost::put(boost::vertex_name, g, 1, "B");
	//	boost::put(boost::vertex_name, g, 2, "C");
}

/// custom properties graph (02)

struct BaseVertexPropertyTag
{
	typedef boost::edge_property_tag kind;
};

void custom_properties_graph_02()
{
	typedef boost::adjacency_list<
		boost::listS,
		boost::vecS,
		boost::bidirectionalS,
		boost::property<boost::property<BaseVertexPropertyTag, BaseVertex>, BaseVertex>
			> BaseGraph_t;
	
	BaseGraph_t g;
	
	boost::add_vertex(BaseVertex(), g);
	boost::add_vertex(BaseVertex(), g);
	boost::add_vertex(BaseVertex(), g);
	
	boost::add_edge(0, 1, g);
	boost::add_edge(1, 2, g);
	boost::add_edge(1, 3, g);
}

/// bundled properties graph

// http://www.boost.org/doc/libs/1_36_0/libs/graph/doc/bundles.html
// internal properties are cumbersome in many uses, where it would be more intuitive
// to just specify a structure or class that contains internal properties for edges or vertices.

void bundled_properties_graph()
{
	typedef boost::adjacency_list<
		boost::vecS,
		boost::vecS,
		boost::undirectedS,  
		BaseVertex,
		BaseEdge> BaseGraph_t;
	
	BaseGraph_t g;
	
	BaseGraph_t::vertex_descriptor vertex_index=boost::add_vertex(g);
	g[vertex_index].name="A";
	vertex_index=boost::add_vertex(g);
	g[vertex_index].name="B";
	vertex_index=boost::add_vertex(g);
	g[vertex_index].name="C";
	
	//	BaseGraph_t::edge_descriptor edge_index=add_edge(0, 1, g);
	//	g[edge_index].weight=.5;
}

int main__()
{
	default_graph();
	
	return 0;
}