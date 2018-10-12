## Metrics

### Object Detection

#### mAP

- Compute average precision (AP) separately for each class, then average over classes.
- Detection is true positive if IoU with ground-truth box is over 0.5 (Is called mAP@0.5).


Combine all detections from all test images, draw a precision / recall curve. mAP is an area under the curve.