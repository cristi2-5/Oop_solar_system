#include "black_hole.h"
#include <cmath>

namespace Space {

    BlackHole::BlackHole(sf::Vector2f position, float strength)
        : SpaceObject("Black Hole", 9999.f, 30.f, position, "Black"), m_strength(strength) {
    }

    void BlackHole::Attract(std::vector<SpaceObject*>& bodies, float delta_time) {
        static int objects_absorbed = 0;

        for (auto body_iter = bodies.begin(); body_iter != bodies.end(); ) {
            SpaceObject* body = *body_iter;
            ///body_iter pentru iterare si stergere
            if (body == this || body->GetName() == "Rocket") {
                ++body_iter;
                continue;
            }

            sf::Vector2f direction = GetPosition() - body->GetPosition();
            float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

            // prag de absorbtie
            if (distance < 40.f) {
                objects_absorbed++;
                body_iter = bodies.erase(body_iter);
                continue;
            }

            float effective_distance = std::max(distance, 150.f);
            direction /= distance;

            float force = m_strength / (effective_distance * effective_distance);
            sf::Vector2f velocity = direction * force * delta_time;

            body->SetPosition(body->GetPosition() + velocity);
            ++body_iter;
        }
    }



    void BlackHole::Draw(sf::RenderWindow& window) {
        sf::CircleShape shape(GetDiameter());
        shape.setFillColor(sf::Color::Black);
        shape.setPosition(GetPosition());
        shape.setOrigin({ shape.getRadius(), shape.getRadius() });
        window.draw(shape);
    }

    void BlackHole::Afisare() const {
        std::cout << "Gaura neagră " << GetName() << " se află la poziția ("
            << GetPosition().x << ", " << GetPosition().y << "), cu forță de atracție "
            << m_strength << "." << std::endl;
    }


} 

