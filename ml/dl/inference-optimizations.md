## Inference optimizations

#### Operations fusion
Merge several ops in the computational graph to lessen the number of ops.

#### Quantization
Convert all model parameters to uint8 (from float64). This will decrease memory footprint, when executing computation, and make computations simpler (int arithmetic instead of float arithmetic).

#### Graph compilation to machine code
Tensorflow graphs can be compiled ahead of time to machine code (which runs on GPU for instance) with TF -> XLA -> LLVM -> Machine code sequence.
