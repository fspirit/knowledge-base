## Tensoflow

A machine learning lib from Google. 

**Big idea**
Express numeric computation as a graph, where nodes are ops (0-n inputs, 1 output) and edges are tensors.

### Operations
	- Constant, outputs a const tensor value during execution.
	- Variable, stateful node, which outputs current value, are updated by gradients nad tuned to minimize the loss.
	- Placeholders, outputs a const tensor, which is provided before session run. Op that outputs a value, which is fed in execution time.
 	- Math (add, matmul)
 	- Convolutions
 	- Inverse convolutions
 	- etc

### How to use
1. Build a graph of operations, which consume and spit out tensors (n-dimentional arrays)

```
W = tf.Variable(..)
b = tf.Variable(..)

x = tf.Placeholder(shape)

h = tf.nn.relu(tf.matmul(W, x) + b)

labels = tf.Placeholder()
prediction = tf.nn.softmax(..)

cross_entropy_loss = tf.reduce_mean(-tf.reduce_sum(labels * tf.log(prediction), reduction_indices=[1]))
train_step = tf.train.GradientDescentOptimizer(0.5).minimize(cross_entropy_loss)
```

2. Run computation by executing that graph of ops inside a TF session
```
sess = tf.Session()
sess.run(tf.initialize_all_variables())

for i in range(1000):
	batch_x, batch_labels = data.next_batch()
	sess.run(train_step, feed_dict={x: batch_x, labels: batch_labels})
```

### Pros & Cons

#### Pros
- Maintained by Google
- Has C++ API
- Supports distributed execution
- Can use GPU

#### Cons
- Hard to debug ops, you dont know its output, until you run it

### Refs
- https://www.tensorflow.org/programmers_guide
- https://www.youtube.com/watch?v=MrijcdNl_U4&list=PL-XeOa5hMEYxNzHM7YLRjIwE1k3VQpqEh
- https://www.youtube.com/watch?v=PicxU81owCs
