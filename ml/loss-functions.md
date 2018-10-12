##  Loss Functions

Loss functions is a function which describes how well thge model fits our data.
If it fits data perfectly, the loss function should be 0. Usually loss fuction output is [0, eternity].

### Regression

#### Mean squared error (MSE) 
#### Mean absolute error (MAE)

When using MAE is appropriate?

### Classification

#### Multinomial Logistic Resression Loss

Treats class scores as unnormalized log probablilities. So to get real probs we first do `exp(score)` and 
than normalize as `prob_i = exp(score) / np.sum(exp.scores)`. So now we get Softmax output.

Our desired loss function is a function which maximized log-likelihood of correct class for each input. 
To maximize log(A) we can minimize -log(A). So out target loss functions is `-log(prob_correct_class)` summed up for 
all the data.

#### Hinge Loss

```
def hinge_loss(scores, target_y):
	values = np.max(0, scores - scores[target_y] + 1)
	values[target_y] = 0
	return np.sum(values)
```

#### Hinge Squared Loss

The same as `Hinge` but `np.max(0, scores - scores[target_y] + 1) ** 2`.

## Metrics
- Precision
- Recall
- F1 score 
