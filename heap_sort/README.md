# Heap sort

Exercice d'algorithmie du cursus **Holberton School – Interview Preparation**.

## Description

Tri d'un tableau d'entiers dans l'ordre croissant avec l'algorithme
**Heap sort** (version *sift-down*). Le tableau est affiché après chaque
échange de deux éléments.

## Prototype

```c
void heap_sort(int *array, size_t size);
```

- `array` : le tableau à trier
- `size` : nombre d'éléments dans `array`
- Un tableau de moins de 2 éléments n'a pas besoin d'être trié

## Algorithme

1. **Construction du tas max** : pour chaque nœud parent, du dernier
   (`size / 2 - 1`) jusqu'à la racine, on le fait descendre (*sift-down*)
   tant qu'un de ses enfants est plus grand que lui.
2. **Extraction** : on échange la racine (le plus grand élément) avec le
   dernier élément du tas, on réduit la taille du tas de 1, puis on refait
   descendre la nouvelle racine.
3. On recommence jusqu'à ce que le tas ne contienne plus qu'un élément.

## Complexité (`0-O`)

| Cas      | Temps        |
|----------|--------------|
| Meilleur | `O(nlog(n))` |
| Moyen    | `O(nlog(n))` |
| Pire     | `O(nlog(n))` |

Le tri se fait sur place, en mémoire `O(1)`.

## Exemple

```
$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
$ ./0-heap
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 99, 86, 13, 52, 96, 73, 71, 7
...
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Fichiers

| Fichier         | Description                                   |
|-----------------|-----------------------------------------------|
| `sort.h`        | Header : prototypes de `heap_sort` et `print_array` |
| `0-heap_sort.c` | Fonction `heap_sort` et ses fonctions utilitaires |
| `print_array.c` | Fonction d'affichage fournie par le sujet     |
| `0-O`           | Complexités du Heap sort (meilleur, moyen, pire cas) |

## Contraintes

- Ubuntu 14.04 LTS, `gcc 4.8.4` avec `-Wall -Werror -Wextra -pedantic`
- Style Betty (`betty-style.pl` et `betty-doc.pl`)
- Pas de variables globales, 5 fonctions maximum par fichier
- Headers protégés par des include guards

## Auteur

madmeal1
