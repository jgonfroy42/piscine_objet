# Liens entre classes

## L'association

Relation durable entre deux classes

### L'agrégation (cas particulier)

La Classe A (**composite**) est composé de Classe B (**composant**).
Le composant peut avoir plusieurs composite et survivre à la destruction du composite.

### La composition (cas particulier)

Agrégation non partagé : le composant n'a qu'un seul composite.
Composant non autonome : il ne survit pas à la destruction du composite.

## L'héritage

La **classe enfant** (classe héritée) a des méthodes ou attributs en plus ce qui en fait une classe plus "précise" que la **classe parent**.
