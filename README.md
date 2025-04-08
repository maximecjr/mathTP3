# 🔦 Vision par Raycasting en 2D avec OpenFrameworks

## 🎯 Objectif

Ce projet implémente une simulation de **champ de vision 2D** à l’aide de **rayons (raycasting)**. Le personnage (contrôlé par la souris) envoie des rayons dans toutes les directions pour détecter quels murs sont visibles. Les rayons s’arrêtent lorsqu’ils rencontrent un mur.

---

## 🛠️ Technologies & Outils

- **Langage :** C++
- **Framework :** [OpenFrameworks](https://openframeworks.cc/) (librairie de création graphique en C++)
- **Paradigme :** Programmation orientée objet (POO)
- **Maths :** Algorithmes géométriques pour intersection rayon-segment

---

## 📁 Structure du projet

```plaintext
src/
├── ofApp.cpp / ofApp.h        # Classe principale OpenFrameworks
├── Particle.cpp / Particle.h  # Représente le personnage et ses rayons
├── Ray.cpp / Ray.h            # Gère les rayons, calculs d'intersection
├── Wall.cpp / Wall.h          # Représente les murs
