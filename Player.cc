
#include "Player.h"
#include <cmath>

static constexpr double Pi = acos(-1);

void Player::spawn(std::shared_ptr<Map> &map)
{
	_map = map;
	_x = map->start_x();
	_y = map->start_y();
	_dir = map->start_dir();
}

void Player::walk_forward(double dist)
{
	double nx = _x + dist * cos(_dir);
	double ny = _y + dist * sin(_dir);
	if (_map->is_space(nx, ny)) {
		_x = nx;
		_y = ny;
	}
}

void Player::walk_backward(double dist)
{
	walk_forward(-dist);
}

void Player::shift_left(double dist)
{
	shift_right(-dist);
}

void Player::shift_right(double dist)
{
	double nx = _x + dist * cos(_dir + Pi/2.0);
	double ny = _y + dist * sin(_dir + Pi/2.0);
	if (_map->is_space(nx, ny)) {
		_x = nx;
		_y = ny;
	}
}

void Player::turn_right(double angle)
{
	_dir += angle;
	if (_dir > 2.0 * Pi)
		_dir -= 2.0 * Pi;
}

void Player::turn_left(double angle)
{
	_dir -= angle;
	if (_dir < 0.0)
		_dir += 2.0 * Pi;
}

void Player::set_fov(double fov)
{
	if (fov < Pi/18.0) return;
	if (fov > 2.0 * Pi / 3.0) return;
	_fov = fov;

}
