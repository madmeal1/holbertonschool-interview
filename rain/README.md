# Rain

Exercice d'algorithmie du cursus **Holberton School – Interview Preparation**.

## Description

Étant donné une liste d'entiers non négatifs représentant la hauteur de murs
de largeur 1 (vue en coupe d'un relief), on calcule combien d'unités carrées
d'eau restent piégées après la pluie.

Les extrémités de la liste (avant l'index `0` et après le dernier élément)
ne sont pas des murs : elles ne retiennent pas d'eau.

## Prototype

```python
def rain(walls)
```

- `walls` : liste d'entiers non négatifs
- **Retour** : un entier, la quantité totale d'eau retenue
- Si la liste est vide, la fonction retourne `0`

## Exemple

```
$ ./0_main.py
6
6
```

Murs `[0, 1, 0, 2, 0, 3, 0, 4]` :

```
              #
          #~~~#
      #~~~#~~~#
  #~~~#~~~#~~~#
 0 1 0 2 0 3 0 4    -> 1 + 2 + 3 = 6
```

Murs `[2, 0, 0, 4, 0, 0, 1, 0]` :

```
      #
      #
 #~~~~#
 #~~~~#~~~~~#
 2 0 0 4 0 0 1 0    -> 2 + 2 + 1 + 1 = 6
```

## Algorithme

Approche **deux pointeurs** en `O(n)` temps et `O(1)` mémoire :

1. Un pointeur part de la gauche, un autre de la droite.
2. On garde en mémoire le mur le plus haut vu de chaque côté
   (`left_max`, `right_max`).
3. On avance toujours le pointeur du côté du mur le plus bas : l'eau au-dessus
   de cette case vaut `max_du_côté - hauteur_actuelle` (si positif).
4. On s'arrête quand les deux pointeurs se rejoignent.

## Fichiers

| Fichier      | Description                                 |
|--------------|---------------------------------------------|
| `0-rain.py`  | Fonction `rain(walls)`                      |
| `0_main.py`  | Script de test fourni par le sujet          |

## Contraintes

- Ubuntu 14.04 LTS, `python3` (3.4.3)
- Style PEP 8 (`pycodestyle` 1.7.x)
- Aucun import de module
- Tous les modules et fonctions sont documentés
- Tous les fichiers sont exécutables et finissent par une nouvelle ligne

## Auteur

madmeal1
