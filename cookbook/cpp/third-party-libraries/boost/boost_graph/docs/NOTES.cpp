// boost::adjacency_list<
//	OutEdgeList,		//container used to represent the edge lists
//	VertexList,		//container used to represent the outer two-dimensional container
//	Directed,		//
//	VertexProperties,	//
//	EdgeProperties,		//
//	GraphProperties,	//
//	EdgeList> 		//

// Parameter		Description								Default
//======================================================================================================
// OutEdgeList		container to represent the edge-list for each vertices			boost::vecS
// VertexList		container to represent the vertex-list of the graph			boost::vecS
// Directed		boost::directedS boost::undirectedS boost::bidirectionalS		boost::directedS
// VertexProperties	internal property storage						boost::no_property
// EdgeProperties	internal property storage						boost::no_property
// GraphProperties	property storage for the graph object					boost::no_property
// EdgeList		container to represent the edge-list for the graph			boost::listS

//VertexList and OutEdgeList:
//boost::vecS		std::vector
//boost::listS		std::list
//boost::slistS		std::slist
//boost::setS		std::set
//boost::multisetS	std::multiset
//boost::hash_setS	std::hash_set

//VertexProperties:
// boost::property<boost::vertex_name_t, std::string>
// boost::no_property
// boost::vertex_index_t
// boost::vertex_index1_t
// boost::vertex_index2_t
// boost::edge_index_t
// boost::graph_name_t
// boost::vertex_name_t
// boost::edge_name_t
// boost::edge_weight_t
// boost::edge_weight2_t
// boost::edge_capacity_t
// boost::edge_residual_capacity_t
// boost::edge_reverse_t
// boost::vertex_distance_t
// boost::vertex_root_t
// boost::vertex_all_t
// boost::edge_all_t
// boost::graph_all_t
// boost::vertex_color_t
// boost::vertex_rank_t
// boost::vertex_predecessor_t
// boost::vertex_isomorphism_t
// boost::vertex_invariant_t
// boost::vertex_invariant1_t
// boost::vertex_invariant2_t
// boost::vertex_degree_t
// boost::vertex_out_degree_t
// boost::vertex_in_degree_t
// boost::vertex_discover_time_t
// boost::vertex_finish_time_t

//std::pair<vertex_iterator, vertex_iterator> boost::vertices(...)

//(OutEdgeList, directed graph) all vertices that have only incoming edges have an empty corresponding adjacency list

