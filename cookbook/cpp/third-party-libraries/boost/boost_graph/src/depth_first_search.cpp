// http://programmingexamples.net/wiki/Boost/BGL/DepthFirstSearch

#include <iostream>
#include <sstream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/graphviz.hpp>

typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS> BaseGraph;
typedef boost::graph_traits<BaseGraph>::vertex_descriptor BaseVertex;

class BaseVisitor: public boost::default_dfs_visitor
{
	std::list<BaseVertex> _list;

public:
	template < typename TVertex, typename TGraph >
	/*virtual*/ void discover_vertex(TVertex v, const TGraph& g) const
	{
		// preorder
		
		std::cout<<v<<std::endl;
//		const_cast<BaseVisitor*>(this)->_list.push_back(v);
	}
	
	std::string str() const
	{
		std::stringstream ss;
		
//		for(std::list<BaseVertex>::const_iterator it=_list.begin(); it!=_list.end(); std::advance(it, 1))
//			ss<<*it<<" ";
		ss<<_list.size();
		
		return ss.str();
	}
};
// 
//                             0
//                            / \
//                           /   \
//                          1     2
//                         / \   / \
//                        3   4 5   6
// 
int main()
{
	BaseGraph g;
	boost::add_edge(0, 1, g);
	boost::add_edge(0, 2, g);
	boost::add_edge(1, 3, g);
	boost::add_edge(1, 4, g);
	boost::add_edge(2, 5, g);
	boost::add_edge(2, 6, g);
	
	std::ofstream of("graph.gv");
	write_graphviz(of, g);
	
	BaseVisitor vis;
	boost::depth_first_search(g, boost::visitor(vis));
	
	std::cout<<vis.str()<<std::endl;
	
	return 0;
}
