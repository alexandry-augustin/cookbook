//http://www.codepedia.com/1/CppAdjacency_listTutorial1
#include <iostream>
#include <cassert>
#include <boost/graph/adjacency_list.hpp>

struct Neuron
{
	Neuron(const double& epsilon=0.1) : mVoltage(0), mEpsilon(epsilon) {}
	double mVoltage;
	const double mEpsilon;

	//The function below prevents the following error:
	//d:\visualstudio8\vc\include\xutility(2726) : 
	//error C2582: 'operator =' function is unavailable in 
	//'boost::detail::adj_list_gen
	//<Graph,VertexListS,OutEdgeListS,DirectedS,VertexProperty,EdgeProperty,GraphProperty,EdgeListS>
	//  ::config::stored_vertex'
	Neuron operator=(const Neuron& n)
	{
		//Implement it using the copy-constructor
		return Neuron(n);
	}
	Neuron(const Neuron& n) : mVoltage(n.mVoltage), mEpsilon(n.mEpsilon) {}
};
std::ostream& operator<<(std::ostream& os, const Neuron& n)
{
	os << "Voltage: " << n.mVoltage << ", Epsilon: " << n.mEpsilon;
}

struct MyNeuronPropertyTag 
{
	typedef boost::edge_property_tag kind;
};

int main_03()
{
	typedef boost::property<MyNeuronPropertyTag, Neuron> MyNeuronProperty;
	typedef boost::adjacency_list
		<
		boost::vecS, //class OutEdgeListS=vecS, // a Sequence or an AssociativeContainer
		boost::vecS, //class VertexListS=vecS, // a Sequence or a RandomAccessContainer
		boost::directedS, //class DirectedS=directedS,
		boost::property<MyNeuronProperty, Neuron> //class VertexProperty=no_property,
		//class EdgeProperty=no_property,
		//class GraphProperty=no_property,
		//class EdgeListS=listS
		> NeuralNet;
	NeuralNet net;
	assert(boost::num_vertices(net)==0);
	assert(boost::num_edges(net)==0);

	//Add neurons and edges
	{
		const int nNeurons=10;
		for (int i=0; i<nNeurons; ++i)
		{
			boost::add_vertex(Neuron(),net);
		}
		assert(boost::num_vertices(net)==nNeurons);

		//Connect all neurons, connect neuron x to x+1
		for (int i=0; i<nNeurons-1; ++i)
		{
			boost::add_edge(i,i+1,net);
		}
		assert(boost::num_edges(net)==nNeurons-1);
	}
	//std::cout all vertices
	// 
}
