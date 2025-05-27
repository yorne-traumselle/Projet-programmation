#ifndef _ENTITY_H
#define _ENTITY_H

#include <set>

#include "../utils/Vector2.h"
#include "../graphics/Texture.h"
#include "../graphics/TextureManager.h"
#include "../game/Map.h"
#include "../utils/Timer.h"
#include "../game/Way.h"

class Entity {
public : typedef enum { running, destroy, not_moving } Status;

protected:

	Map* m_map;
    Vector2<float> m_position;          //Position de l'entité dans le monde
	Vector2<unsigned int> m_tile;
	float m_speed;
    Vector2<float> m_size;              //Taille (width-height) de l'entie
    std::shared_ptr<Texture> m_texture; //Texture associé à l'entité
    std::string m_nameEntity;           //Nom de l'entité dans la liste
	Status m_status;
	static std::set<Entity*> s_entities;
	Way m_way;


public :

    /// <summary>
	/// Constructeur de l'entité.
	/// </summary>
	/// <param name="position">Position dans le monde.</param>
    /// <param name="size">Taille (largeur et hauteur) de l'entité.</param>
    /// <param name="filename">nom et chemin du fichier contenant la texture.</param>
    /// <param name="nameEntity">Nom donné à l'entité pour l'associer à la texture</param>
    Entity(Map* map, const Vector2<unsigned int>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity, float speed = 200);

    /// <summary>
	/// Destucteur de l'entité.
	/// </summary>
    virtual ~Entity();

    virtual void setPosition(const Vector2<unsigned int>& position); // place à la position indiquée
	void setPositionDirectly(const Vector2<unsigned int>& position); // places directly at the desired position
    const Vector2<float>& getPosition() const; // get the float position
	const Vector2<unsigned int>& getTile() const; // get which tile we are on
	void setTile(const Vector2<unsigned int>& tile); // set the tile we are on

    /// <summary>
	/// Permet de charger la texutre et de l'associer à l'entité.
	/// </summary>
     /// <param name="filename">nom et chemin du fichier contenant la texture.</param>
    /// <param name="nameEntity">Nom donné à l'entité pour l'associer à la texture</param>
    void loadTexture(const std::string &filename, const std::string &nameEntity);
    
    /// <summary>
	/// Met à jour les caractéristiques de l'entité.
	/// </summary>
    virtual void update();

	// updates all the entities
	static void simulate();

	// status setter
	void setStatus(Status status);

	// sets all the entities to destroy
	static void finalize();

    /// <summary>
	/// Affichage de l'entité dans la fenêtre du jeu.
	/// </summary>
    virtual void render();

};

#endif //_ENTITY_H