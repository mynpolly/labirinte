

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <memory>
#include <SDL2/SDL.h>

class Texture final {
protected:
	std::weak_ptr<SDL_Renderer> _renderer;
	std::shared_ptr<SDL_Texture> _texture;
	int _width{}, _height{};


public:
	Texture(std::shared_ptr<SDL_Renderer>&ren,const char *filename);

	int height() const {	return _height;	}
	int width() const {return _width;}

	void draw(const SDL_Rect &where);
	void draw(int x, int y, int h, double s);
};

#endif /* TEXTURE_H_ */
