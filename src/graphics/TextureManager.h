#ifndef _TextureManager_H
#define _TextureManager_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_set>

#include "Renderer.h"
#include "Texture.h"

/// <summary>
/// Classe permettant de gérer toutes les textures du jeu.
/// </summary>
class TextureManager
{

protected :

	static std::unique_ptr<TextureManager> m_singleton;

	std::unordered_map<int, std::shared_ptr<Texture> > m_textures;	//un exemple de stockage de texture pour la map

	std::unordered_map<std::string, std::shared_ptr<Texture> > m_textureEntities; //un exemple de stockage de texture pour les entitées

    TextureManager();

public :

	virtual ~TextureManager();
	TextureManager(const TextureManager& copy) = delete;
    TextureManager& operator=(const TextureManager& copy) = delete;

    /// <summary>
	/// Getter sur l'instance de TextureManager
	/// </summary>
	/// <returns></returns>
	static TextureManager* getInstance();

	/// <summary>
	/// Cr�� et retourne la texture charg�e � partir d'un fichier.
	/// </summary>
	/// <param name="filename">nom du fichier</param>
	/// <returns>Texture</returns>
	std::shared_ptr<Texture> loadTexture(const std::string &filename, int valueMap);
	std::shared_ptr<Texture> loadTexture(const std::string &filename, const std::string& value);

	Texture* get(int valueMap) const;
	Texture* get(const std::string &value) const;

    /// <summary>
	/// Supprime la texture en fonction de la valeur dans la carte.
	/// </summary>
	/// <param name="valueMap">valeur stockée dans le fichier texte</param>
	void removeTexture(int valueMap);
	/// <summary>
	/// Supprime la texture en fonction du nom associé.
	/// </summary>
	/// <param name="value">nom de la texture</param>
	void removeTexture(const std::string &value);

    /// <summary>
	/// Supprime toutes les textures
	/// </summary>
    void removeAllTexture();

};

#endif
