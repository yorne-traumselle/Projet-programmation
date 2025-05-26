#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Renderer.h"

/// <summary>
/// Classe utilisée pour gérer une texture
/// </summary>
class Texture
{

private :

	SDL_Texture * m_texture;
	std::string m_filename;
	int m_width;
	int m_height;

protected: 
	/// <summary>
	/// Chargemenent de la texture correspondant au fichier texte.
	/// </summary>
	/// <param name="filename">nom du fichier</param>
	/// <returns>Texture</returns>
	SDL_Texture* loadTexture(const std::string &filename);

	/// <summary>
	/// Détruit la texture.
	/// </summary>
	void removeTexture();

public : 

 	/// <summary>
	/// Constructeur de Texture.
	/// </summary>
	/// <param name="filename">Nom et chemin du fichier contenant la texture</param>
	Texture(const std::string &filename);
    Texture(const Texture& copy);
    Texture& operator=(const Texture& copy);
	bool operator==(const Texture& other);

    virtual ~Texture();

    SDL_Texture *get() const;
	const std::string & getFilename() const;
	int getWidth() const;
	int getHeight() const;

};

#endif 	//_TEXTURE_H
