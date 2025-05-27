#ifndef _GAME_H
#define _GAME_H

#include "Map.h"
#include "../utils/Timer.h"
#include "../entity/Hero.h"
<<<<<<< HEAD
#include "/home/drtin/projet_info/Projet-programmation/src/game/Hud.h"
=======
#include "../entity/Fighter.h"
#include "../entity/Minion.h"
#include "../entity/Boss.h"
#include <string>
>>>>>>> 2408f09c1364702991966834b1a8a4a96c896a16

/// <summary>
/// Classe représentant la gestion du jeu
/// </summary>
class Game {

private :

	enum class GameState { PLAY, PAUSE, INVENTORY, COMBAT, GAME_OVER, GAME_FINISHED, EXIT };
	GameState m_gameState;			//Etat du jeu

    std::shared_ptr<Map> m_map;		//Carte du jeu

	std::shared_ptr<Hero> m_hero;	//Personnage dans le jeu
	std::shared_ptr<Hud> m_hud; //c'est le petit HUD ;)

	std::vector<std::shared_ptr<Minion>> m_minions; //ennemies

	std::shared_ptr<Boss> m_boss; //Boss final

	std::shared_ptr<Inventory> m_inventory; //Boss final



public : 
    /// <summary>
	/// Constructeur permattant d'initialiser la fen�tre du jeu.
	/// </summary>
	/// <param name="width">Taille de la fenêtre</param>
	/// <param name="height">Taille de la fenêtre</param>
	Game(unsigned int width, unsigned int height);
	/// <summary>
	/// Destucteur
	/// </summary>
	virtual ~Game();

	/// <summary>
	/// Fonction permettant de lancer le jeu.
	/// </summary>
	void run();

private : 

	/// <summary>
	/// Initialise les paramètres de la fenêtre et le jeu.
	/// </summary>
	/// <param name="width">Taille de la fenêtre</param>
	/// <param name="height">Taille de la fenêtre</param>
	void initGame(unsigned int width, unsigned int height);
	/// <summary>
	/// Charge la carte du jeu
	/// </summary>
	/// <param name="width">nom et chemin du fichier contenant la carte du jeu.</param>
	void loadGame(std::string roomName);
	/// <summary>
	/// Charge lles caractéristique du personnage.
	/// </summary>
	/// <param name="position">Position dans le monde.</param>
    /// <param name="size">Taille (largeur et hauteur) de l'entité.</param>
    /// <param name="filename">nom et chemin du fichier contenant la texture.</param>
    /// <param name="nameEntity">Nom donné à l'entité pour l'associer à la texture</param>
	void loadHero(const Vector2<float>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity);

    /// <summary>
	/// Boucle principale du jeu, permet de gérer toutes les "tapes d'un tour de jeu.
	/// </summary>
	void gameLoop();
	/// <summary>
	/// Gestion des évènements du jeu.
	/// </summary>
	void handleEvent();
	/// <summary>
	/// Fonction permettant de mettre à jour tous les éléments du jeu.
	/// </summary>
	void update();
	/// <summary>
	/// Fonction pour mettre à jour le renderer.
	/// </summary>
	void render();
	/// <summary>
	/// Fonction pour quitter le jeu et terminer SDL.
	/// </summary>
	void endGame();


	void loadMap(std::string roomName);

	void loadMinions(const Vector2<float>& position, const Vector2<float>& size, 
		const std::string &filename, const std::string &nameEntity);

	void loadBoss(const Vector2<float>& position, const Vector2<float>& size, 
		const std::string &filename, const std::string &nameEntity)
};

#endif //_GAME_H
