

#include "Window.h"
#include <stdexcept>

Window::Window(int width, int height)
: _width(width), _height(height)
{
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"SDL Window",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width, height, 0),
			SDL_DestroyWindow);
	if (not _window)
		throw std::runtime_error(
				std::string("Не могу создать окно: ") +
				std::string(SDL_GetError()));

	_renderer = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(
					_window.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);
	if (not _renderer)
		throw std::runtime_error(
				std::string("Не могу запустить рендер: ") +
				std::string(SDL_GetError()));
}

void Window::main_loop()
{
	setup();

	SDL_Event event;
	auto keys = SDL_GetKeyboardState(nullptr);

	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return;
			if (	event.type == SDL_KEYDOWN and
					event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				return;
			handle_event(event);
		}
		handle_keys(keys);

		update();

		render();
		SDL_RenderPresent(_renderer.get());
	}
}
