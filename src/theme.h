#ifndef _THEME_H
#define _THEME_H

#include "graphics/TextureManager.h"

//permet de charger les textures de la map
namespace Theme {

    static void loadTextureMap(const std::string & filename, int valueMap) {
        TextureManager::getInstance()->loadTexture(filename, valueMap);
    }

    static void loadTextureMap() {
        //A compléter
        //loadTextureMap("assets/tiles/grassCenter.png",0);
        //loadTextureMap("assets/tiles/grassGreenCenter.png",1);

        loadTextureMap("assets/tiles/GRASS.png",0);
        loadTextureMap("assets/tiles/BRICK2.png",1);
        loadTextureMap("assets/tiles/WATER.png",2);
        loadTextureMap("assets/tiles/LAVA.png",3);

    }


}

#endif //_THEME_H