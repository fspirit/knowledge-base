## Dropout

A technique that gives a boost to NN performance (2% min in practice, unless NN is underfitting).

What

- Set to 0 activations of a layer with prob `p`. Do that for each layer. For example - set to 0 50% of activations, effecetively switchig off a half of neurons of a layer.
- During test time use all the neurons by multiply all activations by `p`.

Dropout can be viewed as

1. A method of regularization, as it reduces a number of parameters of a model by half on every mini-batch cycle.
2. A method of ensembling as on every mini-batch cycle you have a different network and in test time you use them all.
3. A method of making a network to build redundant features at deep layers, as it can not rely on any particular feature separately bacause it can be turned off.