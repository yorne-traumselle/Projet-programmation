#include "Renderer.h"

/// <summary>
/// The singleton
/// </summary>
std::unique_ptr<Renderer> Renderer::m_singleton = nullptr;



/// <summary>
/// Initializes a new instance of the <see cref="Renderer"/> class.
/// </summary>
/// <param name="width">The width of the render window.</param>
/// <param name="height">The height of the render window.</param>
Renderer::Renderer(unsigned int width, unsigned int height)
	: m_width(width), m_height(height)
{
	if (SDL_CreateWindowAndRenderer(m_width, m_height, SDL_WINDOW_SHOWN, &m_window, &m_renderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		exit(3);
	}
	SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
	SDL_SetWindowTitle(m_window, "Jeu ESIR");
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void Renderer::initialize(unsigned int width, unsigned int height)
{
	std::cout << "Initialize Renderer" << std::endl;
	m_singleton = std::unique_ptr<Renderer>(new Renderer(width, height));
}

void Renderer::finalize()
{
	m_singleton = nullptr;
}

void Renderer::render(){
	// After drawing
	SDL_RenderPresent(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
}

void Renderer::drawString(const std::string & text, Vector2<float> const & position, TTF_Font* font, const SDL_Color& color, double size) {
	SDL_Surface * surfaceText = TTF_RenderText_Solid(font, text.c_str(), color);
	if(surfaceText==nullptr) {
		throw std::runtime_error(TTF_GetError());
	}
	SDL_Texture * textureText = SDL_CreateTextureFromSurface(m_renderer, surfaceText);
	if(textureText==nullptr) {
		SDL_FreeSurface(surfaceText);
		throw std::runtime_error(SDL_GetError());
	}
	SDL_Rect rect = { (int)position[0], (int)position[1], 
		surfaceText->w, surfaceText->h};
	//rect.x = position[0]-surfaceText->w/2;
    //rect.y = position[1]-surfaceText->h/2;

	SDL_RenderCopy(m_renderer, textureText, nullptr, &rect);
    SDL_DestroyTexture(textureText);
    SDL_FreeSurface(surfaceText);
}

void Renderer::drawRect(const SDL_Rect& rect, const SDL_Color& color, bool filled)
{
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);


    if (filled) {
        SDL_RenderFillRect(m_renderer, &rect);
    } else {
        SDL_RenderDrawRect(m_renderer, &rect);
    }

}


void Renderer::drawRect(const SDL_Rect& rect, const SDL_Color& color, bool filled)
{
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);


    if (filled) {
        SDL_RenderFillRect(m_renderer, &rect);
    } else {
        SDL_RenderDrawRect(m_renderer, &rect);
    }

}

void Renderer::drawTexture(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect * dest)
{
    SDL_RenderCopy(m_renderer, texture, src, dest);
}

void Renderer::drawTexture(const Texture * texture, const Vector2<float>& center, const Vector2<float>& scale, float rotation) {
	SDL_Rect rect; //localization and size of the texture
	rect.x = center[0] - scale[0] / 2;
    rect.y = center[1] - scale[1] / 2;
    rect.w = scale[0];
    rect.h = scale[1];
	SDL_Texture *text = texture->get();
	SDL_RenderCopyEx( m_renderer, text, nullptr, &rect, rotation, nullptr, SDL_FLIP_NONE);
}
