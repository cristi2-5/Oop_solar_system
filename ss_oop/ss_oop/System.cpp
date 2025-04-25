#include "system.h"
#include "i_rotating_entity.h"
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <cstdlib>

using namespace Space;

namespace Simulation {

    void System::AddSun(Star* body) {
        m_stars.push_back(body);
        m_bodies.push_back(body);
        m_object_map[body->GetName()] = body;
    }

    void System::AddPlanet(Planet* body) {
        m_planets.push_back(body);
        m_bodies.push_back(body);
        m_object_map[body->GetName()] = body;
    }

    void System::AddSatellite(Satellite* body) {
        m_satellites.push_back(body);
        m_bodies.push_back(body);
        m_object_map[body->GetName()] = body;
    }

    std::vector<Space::SpaceObject*>& System::GetBodies() {
        return m_bodies;
    }

    void System::RotateByName(const std::string& name, float step) {
        SpaceObject* obj = GetObject(name);

        auto* rotating = dynamic_cast<IRotatingEntity*>(obj);

        RotateEntity(rotating, step);
    }

	SpaceObject* System::GetObject(const std::string& name) {
		auto body = m_object_map.find(name);
		if (body != m_object_map.end()) {
			return body->second;
		}
		return nullptr;
	}

    sf::CircleShape System::CreateEntity(SpaceObject* body) {
        sf::CircleShape sprite(body->GetDiameter());
        sprite.setFillColor(ColorConvertor(body->GetColor()));
        sprite.setPosition(body->GetPosition());
        sprite.setOrigin(sprite.getGeometricCenter());
        return sprite;
    }

    sf::Color System::ColorConvertor(std::string color) {
        if (color == "Red")    return sf::Color::Red;
        if (color == "Blue")   return sf::Color::Blue;
        if (color == "Green")  return sf::Color::Green;
        if (color == "Yellow") return sf::Color::Yellow;
        if (color == "White")  return sf::Color::White;
		if (color == "Black")  return sf::Color::Black;
		if (color == "Gray")   return sf::Color(128, 128, 128);
		if (color == "Orange") return sf::Color(255, 165, 0);
		if (color == "Cyan")   return sf::Color(0, 255, 255);
		if (color == "LightYellow") return sf::Color(255, 255, 224);
		if (color == "LightGray") return sf::Color(211, 211, 211);
		if (color == "DarkGray") return sf::Color(169, 169, 169);
		if (color == "DarkRed") return sf::Color(139, 0, 0);
		if (color == "DarkGreen") return sf::Color(0, 100, 0);
        return sf::Color::Black;
    }

    std::vector<sf::CircleShape> System::DrawEntities() {
        std::vector<sf::CircleShape> sprites;
        for (auto body : m_bodies) {
            sprites.push_back(CreateEntity(body));
        }
        return sprites;
    }

    void System::RotateEntity(IRotatingEntity* entity, float step) {
        if (entity) entity->UpdateRotation(step);
    }

    void System::PrintOrbitData(IRotatingEntity* entity) {
        if (!entity) return;
        std::cout << "Obiect cu centrul de rotatie la (" << entity->GetRotationCenter().x << ", " << entity->GetRotationCenter().y
            << ") și raza orbitala de " << entity->GetRotationRadius() << " unitati." << std::endl;
    }

    void System::UpdateMeteorites(float delta_time, float screen_width, float screen_height) {
        // scade timerul pentru spawn-ul de meteoriti
        m_meteorite_spawn_timer -= delta_time;

        // daca timerul a expirat, adauga un nou meteorit
        if (m_meteorite_spawn_timer <= 0.0f) {
            m_meteorites.emplace_back(screen_width, screen_height);
            m_meteorite_spawn_timer = m_meteorite_spawn_interval;
        }

        // parcurg toti meteorii existenti
        for (auto meteor_it = m_meteorites.begin(); meteor_it != m_meteorites.end(); ) {
            meteor_it->Update(delta_time); // actualizez pozitia meteoritului
            sf::Vector2f meteor_pos = meteor_it->GetPosition();

            bool collided = false;

            // verific coliziunea cu fiecare obiect din sistem
            for (auto body_it = m_bodies.begin(); body_it != m_bodies.end(); ++body_it) {
                SpaceObject* body = *body_it;
                sf::Vector2f body_pos = body->GetPosition();

                float dx = body_pos.x - meteor_pos.x;
                float dy = body_pos.y - meteor_pos.y;
                float distance = std::sqrt(dx * dx + dy * dy);
                float radius_sum = body->GetDiameter() + meteor_it->GetDiameter();

                // daca s-au ciocnit
                if (distance < radius_sum) {
                    std::cout << "Coliziune: " << meteor_it->GetName() << " a lovit " << body->GetName() << "!\n";

                    // daca obiectul e indestructibil , doar sterg meteoritul
                    if (body->GetDurability() == -1) {
                        meteor_it = m_meteorites.erase(meteor_it);
                        collided = true;
                        break;
                    }

                    // altfel reduc durabilitatea obiectului
                    body->ReduceDurability();

                    // daca nu mai are viata, il scot din sistem
                    if (body->IsDestroyed()) {
                        std::cout << body->GetName() << " a fost distrus!\n";
                        m_bodies.erase(body_it);
                    }

                    meteor_it = m_meteorites.erase(meteor_it);
                    collided = true;
                    break;
                }
            }

            // daca nu a fost coliziune, trec la urmatorul meteorit
            if (!collided)
                ++meteor_it;
        }
    }




    void System::DrawMeteorites(sf::RenderWindow& window) {
        for (auto& m : m_meteorites) {
            m.Draw(window);
        }
    }

    void System::PrintObjects() const {
        for (auto body : m_bodies) {
            body->Afisare();
        }
    }

} 
