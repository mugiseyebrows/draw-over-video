# draw-over-video

Project demonstrates how graphics (for example subtitles) can be drawn over video using `QtMultimedia` module.

# How it works

`QAbstractVideoSurface` receives `QVideoFrame`s from `QMediaPlayer` and feeds them to `QWidget` which converts them to `QImage`s and draws them in `paintEvent`.

# See also

Code based on Qt [customvideoitem](https://code.qt.io/cgit/qt/qtmultimedia.git/tree/examples/multimediawidgets/customvideosurface/customvideoitem?h=5.12) example, but instead of `QGraphicsView`, `QGraphicsScene` and `QGraphicsItem` uses simple `QWidget`.