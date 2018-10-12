## Faster R-CNN

### Model

```
feature_maps = process(image)
ROIs = region_proposal(feature_maps)        
for ROI in ROIs
    patch = roi_pooling(feature_maps, ROI)
    results = detector2(patch)
```

1. Feature maps are taken from a large pretrained model (VGG16, ResNet101).
2. Regions Of Interest (ROI) are generated with the help of Region Proposal Network (RPN). Its a network that takes a feature map and is trained to
output bbox and objectness (a prob that a bbox cvontains an object). A 3x3 conv filter is applied to a feature map, than a 1x1 conv that output a 256-d vector for every spacial location in a original feature map. Than a FC layer is used to generate a k * (4 + 2) vector for each location in original feature map. 4 coords and 2 objectness scores (object/background). k is a number of anchors = fixed ratio bboxes (1x1, 2x2, 1x2, 2x1) relative to which a RPN generates coords and scores.
3. Each (dx, dy, w, h) that has OK objectness score is applied to an original feature map and the resulting patch is warped into fixed size. (ROI pooling).
4. Each patch is fed into detector (usually a couple of FC layers) that has 2 heads - regression for coords and softmax for classes.

**Test time perf - 0.2 sec per image.**

### Loss Function 

Multi-Class Log Loss + (MSE + L1)

### Parameters Update

Adam?
