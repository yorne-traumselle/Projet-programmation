#ifndef _TIMER_H
#define _TIMER_H

#include <SDL2/SDL.h>
#include <memory>

#define TPS 60
#define TICKS_PER_FRAME 1000/TPS

/// <summary>
/// Classe permettant de gérer les FPS dans le jeu.
/// </summary>
class Timer {

protected :

    static std::unique_ptr<Timer> m_singleton;

    Uint64 m_startTicks;
    Uint64 m_count;
    
    Timer();

public : 

    ~Timer();

    Timer(const Timer& copy) = delete;
    Timer& operator=(const Timer& copy) = delete;

	static Timer& getInstance();

    Uint64 getTicks() const;
    double getSeconds() const;

    void start();
    void stop();
    void update();

};

#endif //_TIMER_H