#include "space_object.h"
#include <iostream>

namespace Space {

    SpaceObject::SpaceObject(std::string name, float mass, float diameter, sf::Vector2f position, std::string color) {
        m_name = name;
        m_mass = mass;
        m_diameter = diameter;
        m_position = position;
        m_color = color;
		InitDurability();
    }

    double SpaceObject::GetDiameter() const {
        return m_diameter;
    }

    std::string SpaceObject::GetColor() const {
        return m_color;
    }

    sf::Vector2f SpaceObject::GetPosition() const {
        return m_position;
    }

    void SpaceObject::SetPosition(sf::Vector2f position) {
        m_position = position;
    }

    std::string SpaceObject::GetName() const {
        return m_name;
    }

    void SpaceObject::InitDurability() {
        if (GetName() == "Sun") {
            m_durability = -1; // soarele nu poate fi distrus
            return;
        }

        float diameter = GetDiameter();
        m_durability = static_cast<int>(diameter / 20.f);

        if (m_durability < 1)
            m_durability = 1;
    }

	int SpaceObject::GetDurability() const {
		return m_durability;
	}

	void SpaceObject::ReduceDurability() {
		if (m_durability > 0) {
			m_durability--;
		}
	}

	bool SpaceObject::IsDestroyed() const {
		return m_durability <= 0;
	}
} 
