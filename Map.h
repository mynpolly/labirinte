#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <cmath>

class Entity
{
protected:
	double _x{}, _y{};
	int _type{};

public:
	Entity(double x, double y, double type)
	: _x(x), _y(y), _type(type){}
	int type() const { return _type;}
	double x() const {return _x;}
	double y() const {return _y;}
};

class Map
{
protected:
	int _width {}, _height {};
	double _start_x {}, _start_y {}, _start_dir {};
	std::vector<int> _data {};
	std::vector<Entity>_entities{};
public:
	Map(const char *filename);
	virtual ~Map() = default;

	int    width()     const { return _width; }
	int    height()    const { return _height; }
	double start_x()   const { return _start_x; }
	double start_y()   const { return _start_y; }
	double start_dir() const { return _start_dir; }

	int cell(int x, int y)
	{
		if (x<0 or x>=_width or y<0 or y>=_height)
			return 1;
		return _data[y*_width+x];
	}

	int cell(double x, double y){
		return cell(int(floor(x)),int(floor(y)));
	}

	bool is_space(int x, int y)
	{
		return cell(x,y)==0;
	}

	bool is_space(double x, double y)
	{
		return is_space(int(floor(x)), int(floor(y)));
	}

	const std::vector<Entity>& entities() const {
		return _entities;
	}
};

#endif /* MAP_H_ */
