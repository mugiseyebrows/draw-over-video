#include "widget.h"

#include "surface.h"
#include <QPainter>

Widget::Widget(Surface &surface, QWidget *parent)
    : QWidget{parent}, mSurface(surface)
{
    connect(&mSurface,SIGNAL(frameReceived()),this,SLOT(update()));
}

void Widget::paintEvent(QPaintEvent *event)
{
    QVideoFrame frame = mSurface.frame();

    if (frame.map(QAbstractVideoBuffer::ReadOnly)) {

        QPainter painter(this);

        int imageWidth = mSurface.imageSize().width();
        int imageHeight = mSurface.imageSize().height();

        auto image = QImage(frame.bits(),
                            imageWidth,
                            imageHeight,
                            mSurface.imageFormat());

        double scale1 = (double) width() / imageWidth;
        double scale2 = (double) height() / imageHeight;
        double scale = std::min(scale1, scale2);

        QTransform transform;
        transform.translate(width() / 2.0, height() / 2.0);
        transform.scale(scale, scale);
        transform.translate(-imageWidth / 2.0, -imageHeight / 2.0);

        painter.setTransform(transform);

        painter.drawImage(QPoint(0,0), image);

        painter.setTransform(QTransform());

        painter.setFont(QFont("Arial", 20));
        int fontHeight = painter.fontMetrics().height();

        int ypos = height() - (height() - imageHeight * scale) / 2 - fontHeight;
        QRectF textRect(QPoint(0, ypos), QSize(width(), fontHeight));
        QTextOption opt(Qt::AlignCenter);
        painter.setPen(Qt::blue);
        painter.drawText(textRect, "Subtitles sample", opt);

        frame.unmap();
    }

}
