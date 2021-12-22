
#ifndef MAZEWINDOW_H_
#define MAZEWINDOW_H_

#include <memory>
#include "Window.h"
#include "Map.h"
#include "Player.h"
#include "Texture.h"

class MazeWindow final : public Window
{
private:
	std::shared_ptr<Map> _map {};
	Player _player;
	Texture _wall1 {_renderer, "wall.png"};
	Texture _wall2 {_renderer, "wall2.png"};
	Texture _plant {_renderer, "plant.png"};
	Texture _sofa {_renderer, "sofa.png"};

	static constexpr int WINDOW_WIDTH = 1420;
	static constexpr int WINDOW_HEIGHT = 900;

	static constexpr int MINIMAP_CELL_SIZE = 27;
	static constexpr int PLAYER_DOT_SIZE = 14;
	static constexpr int PLAYER_ARROW_SIZE = 35;

	void draw_minimap();
	void draw_player();
	void cast_ray(double dx, double dy, double &rx, double &ry);

protected:
	virtual void render() override;
	virtual void handle_keys(const Uint8 *keys) override;

public:
	MazeWindow();
	virtual ~MazeWindow() = default;
};

#endif /* MAZEWINDOW_H_ */
