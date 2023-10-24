#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "ex01.hpp"

class Graph
{
	private:
		Vector2	size;
		std::vector<Vector2>	all_points;
		std::vector<std::vector<char> > drawing;
		

	public:
		Graph(Vector2 _size): size(_size) {};
		~Graph() {};

		void addPoint(Vector2 point)
		{
			this->all_points.push_back(point);
		}

		void updateSize(Vector2 _size)
		{
			size = _size;
		}

		void setGraph()
		{
			this->drawing.clear();
			this->drawing.resize(this->size.y);


			for (int i = 0; i < this->size.y; i++)
				this->drawing[i].assign(this->size.x, '.');

			for (size_t i = 0; i < this->all_points.size(); i++)
			{
				try {
					this->drawing.at(this->all_points[i].y).at(this->all_points[i].x) = 'X';
				}
				catch (...) {}
			}
		}
		
		template<typename T>
		std::string to_string(const T & value) {
    			std::ostringstream oss;
    			oss << value;
    			return oss.str();
		}

		void displayGraph()
		{
			this->setGraph();
			std::string line = "";

			for (int i = size.y - 1; i >= 0; i--)
			{
				line += to_string(i);
				for (int j = 0; j < size.x; j++)
					line += (" " + to_string(drawing[i][j]));
				line += "\n";
			}
			line += " ";
			for (int j = 0; j < size.x; j++)
				line += (" " + to_string(j));

			std::cout << line << std::endl;
		}
};

#endif
