//
// Created by yorne-traumselle on 27/05/25.
//
#include "Way.h"

Way::Way(const Vector2<unsigned>& depart, const Vector2<unsigned>& arrivee, Map* map)
        : m_depart(depart), m_arrivee(arrivee), m_map(map) {}

Way::Way(Map * map):m_depart(Vector2<unsigned>(0,0)), m_arrivee(Vector2<unsigned>(0,0)),m_map(map) {

}


std::deque<Vector2<int>> Way::compute(unsigned X) {
    const std::vector<std::vector<bool>>& matrice = m_map->getMatriceBool();
    int lignes = matrice.size();
    int colonnes = matrice[0].size();

    std::queue<std::tuple<int, int, int>> q;
    std::vector<std::vector<bool>> visited(lignes, std::vector<bool>(colonnes, false));
    std::unordered_map<Vector2<unsigned>, Vector2<unsigned>> parent;
    std::unordered_map<Vector2<unsigned>, Vector2<int>> moveFromParent;

    std::vector<Vector2<int>> directions = {
        Vector2<int>(-1, 0), // gauche
        Vector2<int>(1, 0),  // droite
        Vector2<int>(0, -1), // haut
        Vector2<int>(0, 1)   // bas
    };

    q.push({m_depart[0], m_depart[1], 0});
    visited[m_depart[1]][m_depart[0]] = true;

    bool found = false;

    while (!q.empty()) {
        auto [x, y, dist] = q.front();
        q.pop();

        if (x == m_arrivee[0] && y == m_arrivee[1] && dist <= X) {
            found = true;
            break;
        }

        if (dist >= X) continue;

        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 0 && nx < colonnes && ny >= 0 && ny < lignes) {
                if (!visited[ny][nx] && matrice[ny][nx]) {
                    visited[ny][nx] = true;
                    Vector2<unsigned> next(nx, ny);
                    parent[next] = Vector2<unsigned>(x, y);
                    moveFromParent[next] = dir;
                    q.push({nx, ny, dist + 1});
                }
            }
        }
    }

    std::deque<Vector2<int>> path;

    if (!found) return path;

    Vector2<unsigned> current = m_arrivee;
    while (!(current == m_depart)) {
        path.push_front(moveFromParent[current]);
        current = parent[current];
    }

    return path;
}

Vector2<int> Way::front() const {
    return m_path.front();
}

void Way::popFront() {
    m_path.pop_front();
}

bool Way::empty() const {
    return m_path.empty();
}