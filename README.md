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
```
## 🔄 Réflexion des rayons

Dans ce projet, nous avons choisi d'ajouter une fonctionnalité bonus : les rayons émis par le personnage peuvent être réfléchis lorsqu'ils rencontrent un mur, simulant ainsi une réflexion réaliste. Par défaut, les rayons ne se réfléchissent pas. Cependant, lorsqu'on appuie sur la touche **E**, les rayons commencent à se réfléchir selon leur angle d'incidence par rapport au mur qu'ils rencontrent.

### 📌 Comment ça fonctionne ?

Les rayons sont d'abord projetés dans toutes les directions depuis la position du personnage. Lorsqu'un rayon touche un mur, la réflexion du rayon est calculée en utilisant la **loi de réflexion**. Cette loi stipule que l'angle d'incidence est égal à l'angle de réflexion, ce qui peut être formulé mathématiquement comme suit :

### 🧮 Formule de la réflexion

Lorsqu'un rayon touche un mur, sa trajectoire est modifiée pour qu'il se reflète selon un angle d'incidence égal à l'angle de réflexion. La formule mathématique utilisée pour calculer la direction du rayon réfléchi est la suivante :

Soit :
- \( \vec{d} \) le vecteur directeur du rayon (avant la réflexion),
- \( \vec{n} \) la normale à la surface du mur (le vecteur perpendiculaire au mur au point d'impact),
- \( \vec{d'} \) le vecteur directeur du rayon réfléchi.

La réflexion du rayon est donnée par la formule :

\[
\vec{d'} = \vec{d} - 2 \cdot (\vec{d} \cdot \vec{n}) \cdot \vec{n}
\]

Où :
- \( \vec{d} \cdot \vec{n} \) représente le produit scalaire entre le vecteur du rayon et la normale du mur,
- \( \vec{n} \) est la normale du mur qui est calculée à chaque intersection.

### 🖱️ Comment activer la réflexion ?

Pour activer la réflexion des rayons, il suffit d'appuyer sur la touche **E**. Cela permet de simuler un changement dans le comportement des rayons, les faisant rebondir sur les murs plutôt que de s'arrêter net à l'impact.

### 🚀 Ce qui se passe lorsqu'un rayon rencontre un mur :

1. **Sans réflexion (par défaut) :** Le rayon s'arrête lorsqu'il touche un mur.
2. **Avec réflexion (lorsqu'on appuie sur **E**) :**
    - Le rayon est réfléchi selon la loi de réflexion,
    - L'angle d'incidence devient égal à l'angle de réflexion, ce qui fait rebondir le rayon dans une direction opposée, par rapport à la normale du mur.

### 💡 Développement technique

Lorsqu'un rayon touche un mur, la réflexion est calculée en utilisant la normale du mur à l'intersection et la formule mentionnée ci-dessus. Le rayon réfléchi est ensuite tracé à partir du point d'impact avec le mur, dans la direction donnée par le vecteur réfléchi \( \vec{d'} \).

Le calcul est effectué dans la méthode `cast()` de la classe **Ray**. Si **reflectRays** est activé, les rayons sont réfléchis, sinon ils continuent leur trajet.

### 🖥️ Code de la réflexion

Voici la partie du code utilisée pour calculer et dessiner les rayons réfléchis :

```cpp
// Calcul de la réflexion dans la méthode cast() de la classe Ray
if (reflectRays) {
    // Calcule le vecteur réfléchi
    reflectionDir = dir - 2 * (dir.dot(normal)) * normal;
    // Dessiner le rayon réfléchi
    ofDrawLine(closestPoint, closestPoint + reflectionDir * 1000);  // Longueur arbitraire pour le rayon réfléchi
}
