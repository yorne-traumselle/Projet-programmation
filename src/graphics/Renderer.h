#ifndef _Renderer_H
#define _Renderer_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <map>
#include <vector>
#include <memory>
#include <iostream>

#include "../utils/Vector2.h"
#include "Texture.h"

/// <summary>
/// Classe utilisée pour le rendu 2D
/// </summary>
class Texture; 

class Renderer
{

protected:	
	
	static std::unique_ptr<Renderer> m_singleton;
	
	unsigned int m_width, m_height;		//Taille de la fenêtre

	SDL_Window * m_window;	//fenêtre de rendu (SDL)

	SDL_Renderer * m_renderer; //Moteur de rendu interne à SDL
	

	/// <summary>
	/// Initialise une nouvelle instance de <see cref="Renderer"/> class.
	/// </summary>
	/// <param name="width">Taille de la fenêtre</param>
	/// <param name="height">Taille de la fenêtre</param>
	Renderer(unsigned int width, unsigned int height);


public:	

	Renderer(const Renderer& ) = delete;
	void operator=(const Renderer&) = delete;

	/// <summary>
	/// Destructeur de <see cref="Renderer"/> class.
	/// </summary>
	virtual ~Renderer();


	/// <summary>
	/// Getter sur le renderer
	/// </summary>
	/// <returns></returns>
	SDL_Renderer * getSdlRenderer() const { return m_renderer; }
	
	/// <summary>
	/// Retourne la taille de la fenêtre
	/// </summary>
	/// <returns></returns>
	unsigned int width() const { return m_width; }
	
	/// <summary>
	/// Retourne la taille de la fenêtre
	/// </summary>
	/// <returns></returns>
	unsigned int height() const { return m_height; }
	
	/// <summary>
	/// Initialise le singleton
	/// </summary>
	/// <param name="width">Taille de la fenêtre</param>
	/// <param name="height">Taille de la fenêtre</param>
	static void initialize(unsigned int width, unsigned int height);
	
	/// <summary>
	/// Supprime le singleton
	/// </summary>
	static void finalize();

	/// <summary>
	/// Retourne l'instance de Renderer (accès au singleton).
	/// </summary>
	/// <returns></returns>
	static Renderer * getInstance() { return m_singleton.get(); }

	void render();

	/// <summary>
	/// ajoute dans le renderer une chaine de caractères.
	/// </summary>
	void drawString(const std::string & text, Vector2<float> const & position, TTF_Font* font,  const SDL_Color& color, double size);

	void drawRect(const SDL_Rect& rect, const SDL_Color& color, bool filled = true);


	/// <summary>
	/// ajoute dans le renderer une texture
	/// </summary>
	/// <param name="texture">Texture à afficher dans le renderer</param>
	/// <param name="src">Partie de la texture initiale à copier (coordonnées x, y et taille w, h)</param>
	/// <param name="dest">Destination où la texture doit être rendue dans la fenêtre</param>
	void drawTexture(SDL_Texture* texture, const SDL_Rect * src, const SDL_Rect * dest);
	void drawTexture(const Texture * texture, const Vector2<float>& center, const Vector2<float>& scale, float rotation);
};

#endif
