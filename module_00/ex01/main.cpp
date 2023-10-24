#include "ex01.hpp"

int main()
{
	Graph my_graph(Vector2(6,6));

	my_graph.addPoint(Vector2(0,0));
	my_graph.addPoint(Vector2(2,2));
	my_graph.addPoint(Vector2(4,2));
	my_graph.addPoint(Vector2(2,3));

	my_graph.displayGraph();
	
	std::cout << std::endl;

	my_graph.updateSize(Vector2(8, 3));
	my_graph.displayGraph();
}
