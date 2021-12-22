

#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>
#include <memory>

class Window
{
public:
	static constexpr int DEFAULT_WIDTH  = 800;
	static constexpr int DEFAULT_HEIGHT = 600;
protected:
	int _width {}, _height {};
	std::shared_ptr<SDL_Window> _window {};
	std::shared_ptr<SDL_Renderer> _renderer {};

	virtual void setup() {}
	virtual void render() {}
	virtual void update() {}
	virtual void handle_event(const SDL_Event &e) {}
	virtual void handle_keys(const Uint8 *keys) {}

public:
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~Window() = default;

	void main_loop();

	int width() const { return _width; }
	int height() const { return _height; }
};

#endif /* WINDOW_H_ */
