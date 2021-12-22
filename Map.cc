
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Map.h"

Map::Map(const char *filename)
{
	std::ifstream mapfile { filename };
	if (not mapfile)
		throw std::runtime_error(
				std::string("Не могу открыть файл карты ") +
				std::string(filename));

	std::string line;
	if (std::getline(mapfile, line)) {
		std::stringstream ss { line };
		ss >> _width >> _height >> _start_x >> _start_y >> _start_dir;
	}

	_data.resize(_width * _height);
	for (int row = 0; row < _height; ++row) {
		std::getline(mapfile, line);
		for (int col = 0; col < _width; ++col) {
			int result = 1;
			if (line[col] == ' ') result = 0;
			if (line[col] == '@') result = 2;
			_data[_width * row + col] = result;
		}
	}

	int count;
	mapfile>>count;
	for (int i=0; i<count; ++i){
		double x,y;
		int type;
		mapfile>>x>>y>>type;
		_entities.push_back(Entity(x,y,type));
	}


	mapfile.close();
}
