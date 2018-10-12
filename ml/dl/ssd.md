## SSD

### Idea

1. Dont use RPN as Faster-RCNN does. Use conv filters right away to predict boxes coords and class scores.
2. Use multi-scale, that is apply those conv layer predictor on feature maps on top of base CNN (VGG16, VGG19).

NN-architecture for object detection (bboxes).

![Arch Pic](https://camo.githubusercontent.com/d7babb7cec9201761494fbc65245c71a4a7df8f9/687474703a2f2f6a6f736875613838313232382e77656266616374696f6e616c2e636f6d2f6d656469612f75706c6f6164732f52656164696e674e6f74652f61725869765f5353442f5353442e706e67)

- Starts from a base model pretrained on ImageNet (vgg, resnet).
- The base model is extended by several convolutional layers.
- Each feature map is used to predict bounding boxes. Diversity in feature map size allows object detection at different resolutions.
- Boxes are filtered by IoU metrics and [hard negative mining](./hard-negative-mining.md).
- Loss is a combination of classification (softmax) and detection (smooth L1)
- Model can be trained end to end.

### Refs
- Need a ref to paper here
