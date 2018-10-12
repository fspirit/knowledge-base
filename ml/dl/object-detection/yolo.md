## YOLO

### Main Idea

The major concept of YOLO is to build a CNN network to predict a (7, 7, 30) tensor.

### Model

- Divides the image into S x S cells (usually 7 x 7, so totally its 49 cells)
- Each cell generates through conv layers:
	- B boxes (each box is h, w, x, y)
	- confidence score for object in the cell
	- C probs for classes
- Output is 7 x 7 x ((B x 5) + C)

#### Network Structure

