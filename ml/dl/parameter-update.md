## Parameters Update 

### Stohastic Gradient Descent

```
x += -learning_rate * dx
``` 

### Using momentum

#### Simple momentum

```
v += mu * v - learning_rate * dx
x += v
```

#### Nesterov momentum

Idea: Calculating gradient `dx` after moving a bit in the direction of momentum `mu * v`.


### Adagrad + RMSProp (Keeping cache)

#### Adagrad

```
cache += dx ** 2
x += -learning_rate * dx / (sqrt(cache) + 1e7)
```

`cache` always grows, when we do learning for a long time, cache becomes so large that x update stops.


#### RMSProp


```
cache = decay_rate * cache + (1 - decay_rate) * dx ** 2
x += -learning_rate * dx / (sqrt(cache) + 1e7)
```

Now `cache` contains basically only several latest values.


### Momentum + RMSProp = Adam

```
m += beta_1 * m - (1 - beta_1) * dx
cache = beta_2 * cache + (1 - beat_2) * dx ** 2
x += - learning_rate * m / (sqrt(cache) + 1e7)
```