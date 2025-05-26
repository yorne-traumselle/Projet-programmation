#ifndef _ENTITY_H
#define _ENTITY_H

#include "../utils/Vector2.h"
#include "../graphics/Texture.h"
#include "../graphics/TextureManager.h"

class Entity {

private:

    Vector2<float> m_position;          //Position de l'entité dans le monde
    Vector2<float> m_size;              //Taille (width-height) de l'entie
    std::shared_ptr<Texture> m_texture; //Texture associé à l'entité
    std::string m_nameEntity;           //Nom de l'entité dans la liste

public : 
    /// <summary>
	/// Constructeur de l'entité.
	/// </summary>
	/// <param name="position">Position dans le monde.</param>
    /// <param name="size">Taille (largeur et hauteur) de l'entité.</param>
    /// <param name="filename">nom et chemin du fichier contenant la texture.</param>
    /// <param name="nameEntity">Nom donné à l'entité pour l'associer à la texture</param>
    Entity(const Vector2<float>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity);

    /// <summary>
	/// Destucteur de l'entité.
	/// </summary>
    virtual ~Entity();

    void setPosition(const Vector2<float>& position);
    const Vector2<float>& getPosition();

    /// <summary>
	/// Permet de charger la texutre et de l'associer à l'entité.
	/// </summary>
     /// <param name="filename">nom et chemin du fichier contenant la texture.</param>
    /// <param name="nameEntity">Nom donné à l'entité pour l'associer à la texture</param>
    void loadTexture(const std::string &filename, const std::string &nameEntity);
    
    /// <summary>
	/// Met à jour les caractéristiques de l'entité.
	/// </summary>
    virtual void update() = 0;

    /// <summary>
	/// Affichage de l'entité dans la fenêtre du jeu.
	/// </summary>
    virtual void render();

};

#endif //_ENTITY_H