
#include "Publication.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

//On publie une place si elle n'existe pas encore c'est à dire si on ne la pas encore publiée

bool Publication::existe(const Ressource& res) const {
    for (const auto& r : ressources) {
        if (r.getSection() == res.getSection() &&
            r.getRangee() == res.getRangee() &&
            r.getSiege() == res.getSiege()) {
            return true;
        }
    }
    return false;
}

bool Publication::publier(const Ressource& res) {
    if (existe(res)) {
        std::cout << " Place déjà publiée : Section " << res.getSection()
                  << ", Rangée " << res.getRangee()
                  << ", Siège " << res.getSiege() << std::endl;
        return false;
    }
    ressources.push_back(res);
    std::cout << " Place publiée : " << res.getSection()
                  << ", Rangée " << res.getRangee()
                  << ", Siège " << res.getSiege() << std::endl;
    return true;
}


/*void Publication::publier(const Ressource& res) {
    ressources.push_back(res);
    std::cout << " Ressource publiée : " << res.getSiege() << std::endl;
}*/

bool Publication::retirer(int id) {
    for (auto it = ressources.begin(); it != ressources.end(); ++it) {
        if (it->getId() == id) {
            ressources.erase(it);
            std::cout << "Place supprimée (id=" << id << ")" << std::endl;
            return true;
        }
    }
    std::cout << " Place non trouvée." << std::endl;
    return false;
}

bool Publication::modifier(int id, const Ressource &nouvelle) {
    for (auto &r : ressources) {
        if (r.getId() == id) {
            r.setSection(nouvelle.getSection());
            r.setRangee(nouvelle.getRangee());
            r.setSiege(nouvelle.getSiege());
            r.setPrix(nouvelle.getPrix());
            return true;
        }
    }
    return false;
}


Ressource* Publication::rechercher(int id) {
    for (auto& res : ressources) {
        if (res.getId() == id) return &res;
    }
    return nullptr;
}

std::vector<Ressource*> Publication::chercher(const std::string& section, const std::string& rangee) const {
    std::vector<Ressource*> résultats;
    for (auto& res : ressources) {
        if (res.getSection() == section && res.getRangee() == rangee) {
            résultats.push_back(const_cast<Ressource*>(&res)); 
        }
    }
    return résultats;
}


void Publication::afficherToutes() const {
    std::cout << ressources.size() << " places publiées :\n";
    std::cout << "Liste des places publiées :\n";
    for (const auto& res : ressources) {
        std::cout << " - ID: " << res.getId()
                  << " | Section: " << res.getSection()
                  << " | Rangée: " << res.getRangee()
                  << " | Siège: " << res.getSiege()
                  << " | Prix: " << res.getPrix() << " FCFA "
                  << " | Disponible: " << (res.estDisponible() ? "Oui" : "Non")
                  << "\n";
    }
}

//Sauvegarder et charger



bool Publication::sauvegarder(const std::string& fichier) const {
    std::ofstream ofs(fichier);
    if (!ofs) return false;

    for (const auto& res : ressources) {
        ofs << res.getId() << ";"
            << res.getSection() << ";"
            << res.getRangee() << ";"
            << res.getSiege() << ";"
            << res.getPrix() << ";"
            << (res.estDisponible() ? 1 : 0) << "\n";
    }
    return true;
}

bool Publication::charger(const std::string& fichier) {
    std::ifstream ifs(fichier);
    if (!ifs) return false;

    ressources.clear();
    std::string ligne;
    while (std::getline(ifs, ligne)) {
        std::stringstream ss(ligne);
        std::string token;

        int id, siege;
        double prix;
        bool dispo;
        std::string section, rangee;

        std::getline(ss, token, ';'); id = std::stoi(token);
        std::getline(ss, section, ';');
        std::getline(ss, rangee, ';');
        std::getline(ss, token, ';'); siege = std::stoi(token);
        std::getline(ss, token, ';'); prix = std::stod(token);
        std::getline(ss, token, ';'); dispo = (token == "1");

        Ressource res(section, rangee, siege, prix, dispo);

        // On force l'id pour correspondre à celui du fichier
        // (à ajuster si tu utilises un compteur statique)
        ressources.push_back(res);
    }
    return true;
}
