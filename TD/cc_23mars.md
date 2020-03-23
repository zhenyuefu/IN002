# Éléments de programmation 2– LU1IN002
## Devoir à la maison - 16 mars 2020
### Pointeurs
#### Question 1
```c
#include<stdio.h>
int n;int* a;
```
1. 
```c
n = 42; a = &n; printf("%d %d\n", n, *a);
```
output:
42 42

2.
```c
n = 42; a = &n; printf("%d %d\n", n, a);
```
output:
42 \<adress de n en entier\>

il faul utiliser `%p` represent le pointeur

3.
```c
n = 42; *a = n; printf("%d %d\n", n, *a);
```
output:
42 42

4. 
```c
n = 42; *a = &n; printf("%d %d\n", n, *a);
```
`*a = &n`

erreur de type

5. 
```c
n = 42; a = 42; printf("%d %d\n", n, *a);
```
`a = 42` 

42 n'est pas un adress

6.
```c
a = &n; n = 42; printf("%d %d\n", n, *a);
```
output:42 42

7.
```c
a = &n; *a = 42; printf("%d %d\n", n, *a);
```
output:42 42

8.
```c
a = malloc(sizeof(int)); *a = 42; printf("%d %d\n", n, *a);
```
output:\<on ne sais pas\> 42

il n'y a pas de valeur de `n`

9.
```c
a = malloc(sizeof(int)); n = 42; printf("%d %d\n", n, *a);
```
output:42 \<on ne sais pas\>

il n'y a pas de valeur de `*a`

10.
```c
a = malloc(sizeof(int)); n = 42; *a = n; printf("%d %d\n", n, *a);
```
output:42 42

11.
```c
a = malloc(sizeof(int)); *a = 42; n = *a; printf("%d %d\n", n, *a);
```
output: 42 42

#### Question 2
```c
#include <stdio.h>
void f(int a, int* b) { *b = *b + a; }
int main() {
  int x = 6;
  f(x, &x);
  f(x, &x);
  return 0;
}
```
![pile.png](https://raw.githubusercontent.com/zhenyuefu/picbed/master/image/pile.png)
### Alternatives
#### Question 3
```c
int points(int e1, int e2) {
  int diff = e1 - e2;
  switch (diff) {
    case 3:
      return 15;
    case 2:
      return 20;
    case 1:
      return 30;
    case 0:
      return 60;
    case -1:
      return 90;
  }
  if (diff <= -2) {
    return 120;
  }
  return 0;
}
```
### Tableaux
#### Question 4
```c
int val_pos(int n, int t[], int len) {
  int i;
  int nb = 0;
  for (i = 0; i < len; i++) {
    if (t[i] > 0) {
      nb++;
    }
    if (nb >= n) {
      return 1;
    }
  }
  return 0;
}
```
#### Question 5
la fonction donne l’indice de la première occurrence de la valeur.
```c
int indice_min(int t[], int len) {
  int min = t[0];
  int indice = 0;
  int i;
  for (i = 1; i < len; i++) {
    if (t[i] < min) {
      min = t[i];
      indice = i;
    }
  }
  return indice;
}
```
#### Question 6
```c
void replace_min_if_sup(int n, int t[], int len) {
  int indice;
  indice = indice_min(t, len);
  if (n > t[indice]) {
    t[indice] = n;
  }
}
```
#### Question 7
```c
int *t_best(int n, int t[], int len) {
  int *n_plus_grand;
  int i;
  int indice;
  n_plus_grand = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    n_plus_grand[i] = t[i];
  }
  for (i = n; i < len; i++) {
    replace_min_if_sup(t[i], n_plus_grand, n);
  }
  return n_plus_grand;
}
```
#### Question 8
```c
void echange(int *t1, int *t2, int len) {
  int i;
  int temp;
  for (i = 0; i < len; i++) {
    if (t1[i] < t2[i]) {
      temp = t1[i];
      t1[i] = t2[i];
      t2[i] = temp;
    }
  }
}
```
#### Question 9
`t3={7,4,9,4,6,7,6,3,8,3,5,5}`

`t3` c'est un pointeur commence a `t3[0]` c'est identique à `t1`

`&t3[6]` c'est un pointeur commence a `t3[6]` c'est identique à `t2`