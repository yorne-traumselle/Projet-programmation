#include "Timer.h"


std::unique_ptr<Timer> Timer::m_singleton = nullptr;

Timer &Timer::getInstance()
{
    if (m_singleton == nullptr)
        m_singleton = std::unique_ptr<Timer>(new Timer());

    return *m_singleton;
}

Timer::Timer():m_startTicks(0)
{
}

Timer::~Timer(){
}

Uint64 Timer::getTicks() const {
    if(m_startTicks>0){
        return SDL_GetTicks64() - m_startTicks;
    }
    return 0;
}

double Timer::getSeconds() const {
    return (double)SDL_GetTicks64() / 1000;
}

void Timer::start() {
    m_startTicks = SDL_GetTicks64();
}

void Timer::stop() {
    m_startTicks = 0;
}
