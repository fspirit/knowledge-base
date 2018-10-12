### Regularization

Is a set of technics to reduce to complexity of the model while training (and thus prevent overfitting). 
Regularization usually targets to 
- Reduce number of parameters of the model
- Decrease magnitude (abs value or squred value) of parameters of the model

Both number of params and their magnitudes directly affect the generalization ability of the model as 
`generalization error < training_error + model_complexity`.

Usually regularization term is added to the loss function.

Most used regularization methods are
- Adding sum of abs of all params to the loss function (L1, Lasso)
- Adding sum of squares of all params to the loss function (L2, Ridge)
- Elastic net (L1 + L2)
- Dropout (reduces number of params)
- Batch normalization
