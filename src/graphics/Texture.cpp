#include <stdexcept>
#include "Texture.h"

Texture::Texture(const std::string &filename): m_texture(nullptr), m_filename(filename), m_width(0), m_height(0){

    loadTexture(m_filename);
}

Texture::Texture(const Texture& copy) : m_texture(nullptr), m_filename(copy.m_filename),m_width(0), m_height(0){
    loadTexture(m_filename);
}

Texture& Texture::operator=(const Texture& copy) {
    removeTexture();
    m_texture = nullptr;
    m_filename = copy.m_filename;

    loadTexture(m_filename);
    return *this;
}

bool Texture::operator==(const Texture& other) {
    return m_filename == other.m_filename;
}

Texture::~Texture() {
    removeTexture();
}

SDL_Texture* Texture::loadTexture(const std::string &filename) {
    m_texture = IMG_LoadTexture(static_cast<SDL_Renderer*>(Renderer::getInstance()->getSdlRenderer()), filename.c_str());
    if(m_texture == nullptr) {
        std::string error = "Unable to load texture " + filename + " ! SDL_image Error : " + IMG_GetError();
        throw std::runtime_error(error);
    }
    SDL_QueryTexture(m_texture, nullptr, nullptr, &m_width, &m_height);
    return m_texture;
}

SDL_Texture * Texture::get() const {
    return m_texture;
}

const std::string & Texture::getFilename() const {
    return m_filename;
}

int Texture::getWidth() const {
    return m_width;
}

int Texture::getHeight() const{
    return m_height;
}

void Texture::removeTexture() {
    SDL_DestroyTexture(m_texture);
}