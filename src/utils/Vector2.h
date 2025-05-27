#ifndef _VECTOR2_H
#define _VECTOR2_H

#include <cmath>
#include <queue>

#include "MathUtils.h"

/// <summary>
/// A two dimensional vector class. 
/// </summary>
template <class Scalar>
class Vector2
{
protected:
	Scalar m_coordinates[2];

public:	
	/// <summary>
	/// Initializes a new instance of the <see cref="Vector2"/> class.
	/// </summary>
	/// <param name="x">The x coordinate.</param>
	/// <param name="y">The y coordinate.</param>
	Vector2(Scalar x = 0.0, Scalar y = 0.0)
	{
		m_coordinates[0] = x;
		m_coordinates[1] = y;
	}
	Vector2(Scalar z)
	{
		m_coordinates[0] = z;
		m_coordinates[1] = z;
	}
	template<class Scalar2>
	Vector2(const Vector2<Scalar2> & v) {
		m_coordinates[0] = static_cast<Scalar>(v[0]);
		m_coordinates[1] = static_cast<Scalar>(v[1]);
	}
	
	/// <summary>
	/// Gets the value of the coordinate designated by index.
	/// </summary>
	/// <param name="index">The index of the coordinate.</param>
	/// <returns></returns>
	Scalar operator[] (unsigned int index) const
	{
		return m_coordinates[index];
	}
	
	/// <summary>
	/// Gets / sets the value of the coordinate designated by index.
	/// </summary>
	/// <param name="index">The index of the coordinate.</param>
	/// <returns></returns>
	Scalar & operator[] (unsigned int index)
	{
		return m_coordinates[index];
	}
	
	/// <summary>
	/// Computes the sum of two vectors.
	/// </summary>
	/// <param name="v">The other vector.</param>
	/// <returns></returns>
	Vector2 operator+ (const Vector2 & v) const
	{
		return Vector2(m_coordinates[0] + v[0], m_coordinates[1] + v[1]);
	}
	
	/// <summary>
	/// Computes the difference between two vectors.
	/// </summary>
	/// <param name="v">The other vector.</param>
	/// <returns></returns>
	Vector2 operator-(const Vector2 & v) const
	{
		return Vector2(m_coordinates[0] - v[0], m_coordinates[1] - v[1]);
	}
	
	/// <summary>
	/// Computes the multiplication of this vector by a scalar.
	/// </summary>
	/// <param name="v">The scalar.</param>
	/// <returns></returns>
	Vector2 operator* (const Scalar & v) const
	{
		return Vector2(m_coordinates[0]*v, m_coordinates[1]*v);
	}
	
	/// <summary>
	/// Computes the division of the vector by a scalar.
	/// </summary>
	/// <param name="v">The scalar.</param>
	/// <returns></returns>
	Vector2 operator/ (const Scalar & v) const
	{
		return Vector2(m_coordinates[0] / v, m_coordinates[1] / v);
	}
	
	/// <summary>
	/// Computes the negation of this vector.
	/// </summary>
	/// <returns></returns>
	Vector2 operator- () const
	{
		return Vector2(-m_coordinates[0], -m_coordinates[1]);
	}
	
	/// <summary>
	/// Computes the dot product of two vectors.
	/// </summary>
	/// <param name="v">The v.</param>
	/// <returns></returns>
	Scalar operator * (const Vector2 & v) const
	{
		return m_coordinates[0] * v.m_coordinates[0] + m_coordinates[1] * v.m_coordinates[1];
	}
	
	/// <summary>
	/// Computes the norm of this vector.
	/// </summary>
	/// <returns></returns>
	Scalar norm() const
	{
		return sqrt(m_coordinates[0] * m_coordinates[0] + m_coordinates[1] * m_coordinates[1]);
	}
	
	/// <summary>
	/// Computes the normalized vector (*this)/this->norm().
	/// </summary>
	/// <returns></returns>
	Vector2 normalized() const
	{
		return (*this) / norm();
	}
	
	/// <summary>
	/// Equality test between two vectors.
	/// </summary>
	/// <param name="v">The other vector.</param>
	/// <returns></returns>
	bool operator== (const Vector2 & v) const
	{
		return m_coordinates[0] == v[0] && m_coordinates[1] == v[1];
	}
	
	/// <summary>
	/// Difference test between two vectors.
	/// </summary>
	/// <param name="v">The other vector.</param>
	/// <returns></returns>
	bool operator != (const Vector2 & v) const
	{
		return !((*this) == v);
	}
	
	/// <summary>
	/// Computes the rotation of this vector by the angle angle (in radians).
	/// </summary>
	/// <param name="angle">The angle.</param>
	/// <returns></returns>
	Vector2 rotate(const Scalar & angle) const
	{
		return Vector2(cos(angle)*m_coordinates[0] - sin(angle)*m_coordinates[1], sin(angle)*m_coordinates[0] + cos(angle)*m_coordinates[1]);
	}
		
	/// <summary>
	/// Computes the distance between two points which coordinates are this vector and the provided one.
	/// </summary>
	/// <param name="v">The distance.</param>
	/// <returns></returns>
	Scalar calcDistance(const Vector2<Scalar> & v) const
	{
		return ((*this) - v).norm();
	}
	
	/// <summary>
	/// Assuming that this vector is a point and v is a point, computes the direction (*this) to v.
	/// </summary>
	/// <param name="v">The direction from (*this) to v.</param>
	/// <returns></returns>
	Vector2<Scalar> direction(const Vector2<Scalar> & v) const
	{
		return (v - (*this)).normalized();
	}

	Vector2 &operator=(Vector2 & other) const {
		return *other;
	}

	/// <summary>
	/// Returns a random unit vector.
	/// </summary>
	/// <returns></returns>
	static Vector2 random()
	{
		return Vector2(Scalar(1), Scalar(0)).rotate(MathUtils::random()*MathUtils::pi*Scalar(2));
	}

	bool operator<(const Vector2<Scalar>& other) const {
		return std::tie(m_coordinates[0], m_coordinates[1]) < std::tie(other.m_coordinates[0], other.m_coordinates[1]);
	}

	const std::vector<Vector2<int>> directions = {
		{0, 1}, {1, 0}, {0, -1}, {-1, 0}
	};

	Vector2<int> findClosestReachableFreeCell(
	const std::vector<std::vector<bool>>& occupied,
	const Vector2<int>& pos2,
	int X
) {
		Vector2<int> pos1 = *this;
		int rows = occupied.size();
		int cols = occupied[0].size();

		std::queue<std::pair<Vector2<int>, int>> q;
		std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

		q.push({pos1, 0});
		visited[pos1[0]][pos1[1]] = true;

		Vector2<int> bestPos = {-1, -1};
		int bestDist = std::numeric_limits<int>::max();

		while (!q.empty()) {
			auto [cur, steps] = q.front(); q.pop();

			if (steps > X) continue;

			if (!occupied[cur[0]][cur[1]]) {
				int dist = cur.calcDistance(pos2);
				if (dist < bestDist) {
					bestDist = dist;
					bestPos = cur;
				}
			}

			for (const auto& dir : directions) {
				Vector2<int> next = {cur[0] + dir[0], cur[1] + dir[1]};

				if (next[0] >= 0 && next[0] < rows && next[1] >= 0 && next[1] < cols && !visited[next[0]][next[1]]) {
					visited[next[0]][next[1]] = true;
					q.push({next, steps + 1});
				}
			}
		}

		return bestPos;
	}
};


namespace std {
	template<typename T>
	struct hash<Vector2<T>> {
		size_t operator()(const Vector2<T>& v) const {
			return hash<T>()(v[0]) ^ (hash<T>()(v[1]) << 1);
		}
	};
}


#endif //_VECTOR2_H
