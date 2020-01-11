#pragma once

/**
 *  \brief The Vector3 struct
 *  
 *  \bug
 *  \note
 *  \author Welsley Gai-Yeen Lui
 *  \date 
 */
struct Vector3
{
	float m_X, m_Y, m_Z;

	/**
	 * \brief Default constuctor for Vector3
	 */
	Vector3(){}

	/**
	 * \brief Constuctor for Vector3 setting up the vectors
	 */
	Vector3(float newX, float newY, float newZ)
	{
		m_X = newX;
		m_Y = newY;
		m_Z = newZ;
	}

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param pos [description]
	 * @return [description]
	 */
	Vector3 operator+(Vector3 pos)
	{
		return Vector3(m_X + pos.m_X, m_Y + pos.m_Y, m_Z + pos.m_Z);
	}

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param pos [description]
	 * @return [description]
	 */
	Vector3 operator-(Vector3 pos)
	{
		return Vector3(m_X - pos.m_X, m_Y - pos.m_Y, m_Z - pos.m_Z);
	}

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param pos [description]
	 * @param pos [description]
	 * @param pos [description]
	 * @return [description]
	 */
	Vector3 operator*(Vector3 pos)
	{
		return Vector3(m_X * pos.m_X, m_Y * pos.m_Y, m_Z * pos.m_Z);
	}

	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param pos [description]
	 * @return [description]
	 */
	Vector3 operator/(Vector3 pos)
	{
		return Vector3(m_X / pos.m_X, m_Y / pos.m_Y, m_Z / pos.m_Z);
	}
};