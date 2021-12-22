

#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>
#include "Map.h"

class Player final
{
public:
	static constexpr double WALK_STEP = 0.05;
	static constexpr double TURN_STEP = 0.05;
private:
	double _x {}, _y {}, _dir {};
	std::shared_ptr<Map> _map;
	double _fov { acos(-1.0) / 3.0 };

public:
	Player() = default;
	virtual ~Player() = default;

	void spawn(std::shared_ptr<Map> &map);

	double dir() const { return _dir; }
	double x() const   { return _x;   }
	double y() const   { return _y;   }
	double fov() const { return _fov; }

	void walk_forward (double dist  = WALK_STEP);
	void walk_backward(double dist  = WALK_STEP);
	void shift_left   (double dist  = WALK_STEP);
	void shift_right  (double dist  = WALK_STEP);
	void turn_right   (double angle = TURN_STEP);
	void turn_left    (double angle = TURN_STEP);

	void set_fov(double fov);
};

#endif /* PLAYER_H_ */
