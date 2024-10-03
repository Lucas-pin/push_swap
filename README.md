# push_swap

`push_swap` es un proyecto que implementa un algoritmo para ordenar una lista de números enteros utilizando dos pilas y un conjunto limitado de operaciones. El objetivo es ordenar la lista con el menor número posible de movimientos.

## Funcionamiento

El programa `push_swap` toma una lista de números enteros como argumentos de línea de comandos y los ordena utilizando las siguientes operaciones:

- `sa`: Intercambia los dos primeros elementos de la pila `a`.
- `sb`: Intercambia los dos primeros elementos de la pila `b`.
- `ss`: Realiza `sa` y `sb` simultáneamente.
- `pa`: Mueve el primer elemento de la pila `b` a la pila `a`.
- `pb`: Mueve el primer elemento de la pila `a` a la pila `b`.
- `ra`: Rota todos los elementos de la pila `a` hacia arriba.
- `rb`: Rota todos los elementos de la pila `b` hacia arriba.
- `rr`: Realiza `ra` y `rb` simultáneamente.
- `rra`: Rota todos los elementos de la pila `a` hacia abajo.
- `rrb`: Rota todos los elementos de la pila `b` hacia abajo.
- `rrr`: Realiza `rra` y `rrb` simultáneamente.

El programa genera una secuencia de estas operaciones que, cuando se aplican a la lista de entrada, resultan en una lista ordenada.

## Uso

Para ejecutar el programa, compílalo y luego pásale una lista de números enteros como argumentos:

```sh
./push_swap 2 -1 -200
