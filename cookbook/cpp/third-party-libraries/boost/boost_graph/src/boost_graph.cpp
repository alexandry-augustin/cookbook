//http://www.codepedia.com/1/CppAdjacency_listTutorial1
#include <iostream>
#include <cassert>
#include <boost/graph/adjacency_list.hpp>
//--------------------------------------------------------
#define I_LOVE_USING_CONST
//--------------------------------------------------------
typedef boost::graph_traits<boost::adjacency_list<> >::vertex_iterator	 		VertexIterator;
typedef boost::graph_traits<boost::adjacency_list<> >::adjacency_iterator 		AdjacencyIterator;
typedef boost::property_map<boost::adjacency_list<>, boost::vertex_index_t>::type 	IndexMap;
//--------------------------------------------------------
int main_00()
{
	boost::adjacency_list<> myGraph;
	
	//See if it is indeed empty
	assert(boost::num_vertices(myGraph)==0);
	assert(boost::num_edges(myGraph)==0);

	//Add vertices and edges
	{
		//Create some vertices
		const int nVertices=10;
		for(int i=0; i!=nVertices; ++i)
			boost::add_vertex(myGraph);
		//Connect each vertex to all next vertices
		for(int i=0; i!=nVertices; ++i) //'-1' as the last vertex has no out-edge
			for(int j=i+1; j!=nVertices; ++j)
				boost::add_edge(i,j,myGraph);
		assert(boost::num_vertices(myGraph)==nVertices);
		assert(boost::num_edges(myGraph) == ((nVertices * (nVertices-1))) / 2 );
	}

	//Display the structure on screen
	//Get a property map. This property we need is the boost::vertex_index
	const IndexMap myIndexMap=boost::get(boost::vertex_index, myGraph);
#ifdef I_LOVE_USING_CONST    
	VertexIterator vertexIterator=boost::vertices(myGraph).first;
	//Set a const vertex iterator beyond the last vertex
	const VertexIterator vertexIteratorEnd=boost::vertices(myGraph).second;
#else 
	VertexIterator vertexIterator, vertexIteratorEnd;
	//set another vertex iterator beyond the last vertex
	boost::tie(vertexIterator, vertexIteratorEnd)=boost::vertices(myGraph); 
#endif
	for ( ; vertexIterator != vertexIteratorEnd; ++vertexIterator) 
	{
		//Show the focal vertex's index
		std::cout << "The vertex at index " << boost::get(myIndexMap, *vertexIterator);

		//Get the adjacent vertices
#ifdef I_LOVE_USING_CONST
		//Set the active iterator to the first adjecent vertex
		AdjacencyIterator adjacencyIterator=boost::adjacent_vertices(*vertexIterator, myGraph).first;
		//Set a const iterator to beyond the last adjecent vertex
		const AdjacencyIterator adjacencyIteratorEnd=boost::adjacent_vertices(*vertexIterator, myGraph).second;
#else
		//Set the active iterator to the first adjecent vertex
		//and set another iterator to beyond the last adjecent vertex
		AdjacencyIterator adjacencyIterator, adjacencyIteratorEnd;
		boost::tie(adjacencyIterator, adjacencyIteratorEnd)=boost::adjacent_vertices(*vertexIterator, myGraph);
#endif
		//Work through the range of the AdjecentIterators
		if (adjacencyIterator == adjacencyIteratorEnd)
			//There is no range, in other words: the vertex has no out-edge
			std::cout << " is not connected." << std::endl;
		else
		{
			//There is a range, in other words: the vertex has at least one out-edge
			std::cout << " is connected to ";
			//Loop through all vertices the focal vertex is connected to
			for (  ; adjacencyIterator != adjacencyIteratorEnd; ++adjacencyIterator) 
				//Display the index of the vertex the focal vertex is connected to
				std::cout << boost::get(myIndexMap, *adjacencyIterator) << " ";
			std::cout << std::endl;
		}
	} 
}
