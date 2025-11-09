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

        return false;
    }
    ressources.push_back(res);

    return true;
}

Ressource* Publication::rechercher(int id) {
    for (auto& res : ressources) {
        if (res.getId() == id) return &res;
    }
    return nullptr;
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
}//TODO : enlever

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
        //Gère le conflit d'id entre le client et le serveur

        res.setId(id);

        // On force l'id pour correspondre à celui du fichier
        ressources.push_back(res);
    }
    return true;
}
