# Multi Slider style in QT

## 1. Float value slider

  1. new a project FloatDemo
  2. add this as the submodule to the new project
  3. include the submodule in the `.pro` file
  4. define a `QWidget` in the new project, where you want to add float slider
  5. upgrade the class `QWidget` to `FloatSlider`

  Here is an [example](https://github.com/jiaohu/FloatSliderDemo)

## 2. circle ticker slider

to make each ticker style to a circle, same as the `FloatSlider`, you need to upgrade the class `QWidget` or `QSlider` as `CircleTickSlider`