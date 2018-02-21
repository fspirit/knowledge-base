## Save and restore a model

####  Read & run 

```python
with tf.Session() as sess:
	tf.saved_model.loader.load(sess, [tf.saved_model.tag_constants.TRAINING], './model/')

	graph = tf.get_default_graph()
	input_ph = graph.get_tensor_by_name('image_input:0')
	keep_prob_ph = graph.get_tensor_by_name('keep_prob:0')
	
	logits_op = graph.get_operation_by_name('Reshape_2')
```

A `load` method load a graph from file right into current context/stream. After that a `tf.get_default_graph` method will return loaded graph.
To run some operation (probably a last layer op or a loss calculation op) in that graph you have fill all the placeholders and get that 
op reference from a loaded grapsh by name.

```python

```