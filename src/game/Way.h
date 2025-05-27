//
// Created by yorne-traumselle on 27/05/25.
//

#ifndef WAY_H
#define WAY_H
#include "Map.h"
#include "Way.h"
#include <deque>
#include <vector>
#include <queue>

class Way {

    Vector2<unsigned> m_depart;
    Vector2<unsigned> m_arrivee;
    Map* m_map;
    std::deque<Vector2<int>> m_path;
public:
    Way(const Vector2<unsigned>& depart, const Vector2<unsigned>& arrivee, Map* map);
    Way(Map* map);

    std::deque<Vector2<int>> compute(unsigned X);
    Vector2<int> front() const;
    void popFront();
    bool empty() const;
};


#endif //WAY_H
