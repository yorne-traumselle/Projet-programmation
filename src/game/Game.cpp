#include "Game.h"
#include "../theme.h"

#include <iostream>

Game::Game(unsigned int width, unsigned int height) : m_gameState(GameState::PLAY) {
    initGame(width, height);
    loadGame("assets/maps/map.txt");
}

Game::~Game()
{
}

void Game::run()
{
	gameLoop();
	endGame();
}

void Game::initGame(unsigned int width, unsigned int height) {

    // 1 - Initialization of SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		exit(3);
	}

    Renderer::initialize(width, height);

    //Load Texture
    Theme::loadTextureMap();

	//Load Hero
	loadHero(Vector2<float>(50, 50), Vector2<float>(20, 20), "assets/player/p1_walk01.png", "SuperHero");

}

void Game::loadGame(const std::string & filename){
    loadMap(filename);
}

void Game::loadMap(const std::string & filename,std::string roomName){
	m_map = std::make_shared<Map>(filename);
	if (roomName=="spawn" || roomName=="shop1" || roomName=="shop2"){
		m_gameState=GameState::PLAY;
	}else{
		m_gameState=GameState::COMBAT;
	}
}

void Game::loadHero(const Vector2<float>& position, const Vector2<float>& size, const std::string &filename, const std::string &nameEntity) {
	m_hero = std::shared_ptr<Hero>(new Hero(position, size, filename, nameEntity));
}

void Game::gameLoop()
{

	//// The main event loop
	while (m_gameState != GameState::EXIT)
	{
		Timer::getInstance().start();

		// 1 - We handle events 
		handleEvent();

		// 2 - We update the simulation
		update();
		
		// 3 - We render the scene
		render();

		//4 - We limit the frame rate
		Uint64 frameTime = Timer::getInstance().getTicks();
		if(TICKS_PER_FRAME > frameTime) {
			SDL_Delay( TICKS_PER_FRAME - frameTime);
		}

	}
}

void Game::handleEvent()
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			std::cout << "Exit signal detected" << ::std::endl;
			m_gameState = GameState::EXIT;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case 'q':
				std::cout << "Exit signal detected" << ::std::endl;
				m_gameState = GameState::EXIT;
				break;
			case SDLK_RETURN:
				std::cout << "Enter" << ::std::endl;
				break;
			case SDLK_RIGHT:
				std::cout << "Right down" << ::std::endl;
				break;
			case SDLK_LEFT:
				std::cout << "Left down" << ::std::endl;
				break;
			case SDLK_UP:
				std::cout << "Up down" << ::std::endl;
				break;
			case SDLK_DOWN:
				std::cout << "Down down" << ::std::endl;
				break;
			case SDLK_SPACE:
				std::cout << "space down" << ::std::endl;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				std::cout << "Left up" << ::std::endl;
				break;
			case SDLK_RIGHT:
				std::cout << "Right up" << ::std::endl;
				break;
			case SDLK_UP:
				std::cout << "up up" << ::std::endl;
				break;
			case SDLK_DOWN:
				std::cout << "down up" << ::std::endl;
				break;
			case SDLK_SPACE:
				std::cout << "space up" << ::std::endl;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

}

void Game::update()
{	
	m_hero->update();
	/*
	if (m_map->getMapType()==Map::MapType::Chill){
		if (m_map->getCell(m_hero->getTile())->isExit()=true){
			loadMap();
		}
	}*/
}

void Game::render()
{
	m_map->drawMap();
	m_hero->render();
	Renderer::getInstance()->render();
}

void Game::endGame()
{
	std::cout << "Shutting down renderer..." << std::endl;
	Renderer::finalize();
	std::cout << "Shutting down SDL" << std::endl;
	SDL_Quit();
}