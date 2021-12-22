

#include "Texture.h"
#include <stdexcept>
#include <SDL2/SDL_image.h>
Texture::Texture(std::shared_ptr<SDL_Renderer> &ren,
		const char *filename)
:_renderer(ren)
{
	auto real_ren=_renderer.lock();
	if (real_ren==nullptr)
		throw std::runtime_error("Рендер куда-то делся");

	_texture= std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(real_ren.get(),filename),
			SDL_DestroyTexture);
	if (_texture==nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить текстуру: ")+
				std::string(SDL_GetError()));
	SDL_QueryTexture(_texture.get(),nullptr,nullptr,&_width,&_height);
}

void Texture::draw(const SDL_Rect &where)
{
	auto real_ren=_renderer.lock();
	if (real_ren==nullptr) throw std::runtime_error("Нет рендера");
	SDL_RenderCopy(real_ren.get(),_texture.get(),nullptr,&where);
}

void Texture::draw(int x, int y, int h, double s)
{
	auto real_ren=_renderer.lock();
	if (real_ren==nullptr) throw std::runtime_error("Нет рендера");
	SDL_Rect src {
		int(floor(s*width())),0,1,height()};
	SDL_Rect dst {x,y,1,h};
	SDL_RenderCopy(real_ren.get(),_texture.get(),&src,&dst);
	}
