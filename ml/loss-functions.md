##  What are loss functions? When are they used? Name several most important ones for regression and classification.

Loss functions is a function which describes how well thge model fits our data.
If it fits data perfectly, the loss function should be 0. Usually loss fuction output is [0, eternity].

Regression:
- MSE
- MAE

Classification:
- Logistic regression loss
- Hinge loss
- Hinge squared loss

### What is 'mean squared error' (MSE) loss function?

### What is 'mean absolute error' (MAE) loss function. When is it appropriate to use it instead of MSE?


#### Multinomial Logistic Resression Loss

Treats class scores as unnormalized log probablilities. So to get real probs we first do `exp(score)` and 
than normalize as `prob_i = exp(score) / np.sum(exp.scores)`. So now we get Softmax output.

Our desired loss function is a function which maximized log-likelihood of correct class for each input. 
To maximize log(A) we can minimize -log(A). So out target loss functions is `-log(prob_correct_class)` summed up for 
all the data.
 
#### Describe the 'Hinge' loss function. Draw a plot.

```
def hinge_loss(scores, target_y):
	values = np.max(0, scores - scores[target_y] + 1)
	values[target_y] = 0
	return np.sum(values)
```

#### Describe Hinge Squared loss. Draw a plot.

The same as `Hinge` but `np.max(0, scores - scores[target_y] + 1) ** 2`.