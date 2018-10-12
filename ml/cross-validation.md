### Cross-validation

OK, so we have a set of labeled data and we want to learn a model from that data. 
- How do we evaluate the performance of a model on the new data? 
- How do we make sure that selected model does not overfit?

#### Solution
We use only part of the data for training and other part for testing/evaluating the performance of the model with certain params.

1. We can just leave 30% of the data as testing set and check model on that data. The problem with this approach is that we do not use all the available data for training, so it loses predictive power (Holdout method).
2. We can divide all data into n parts and then do n iterations: train on n-1 parts and test on the part that is left (this method is usually referred to as cross-validation).

Typically we select 2 main hyperparams via cross-validation:
1. Learning rate for gradient descent
2. Regularization term coefficient (lambda)
