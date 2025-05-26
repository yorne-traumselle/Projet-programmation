#ifndef _HERO_H
#define _HERO_H

#include "Entity.h"

/// <summary>
/// Classe représentant un personnage du jeu
/// </summary>
class Hero : public Entity {

public : 
    /// <summary>
	/// Constructeur du héro.
	/// </summary>
	/// <param name="position">Position dans le monde.</param>
    /// <param name="size">Taille (largeur et hauteur) de l'entité.</param>
    /// <param name="filename">nom et chemin du fichier contenant la texture.</param>
    /// <param name="nameEntity">Nom donné à l'entité pour l'associer à la texture</param>
    Hero(const Vector2<float>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity);
    virtual ~Hero();

    virtual void update() override;
    virtual void render() override;

};

#endif //_HERO_H