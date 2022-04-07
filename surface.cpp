#include "surface.h"

#include <QVideoSurfaceFormat>

Surface::Surface(QObject *parent)
    : QAbstractVideoSurface{parent}
{

}

QList<QVideoFrame::PixelFormat> Surface::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const
{
    if (handleType == QAbstractVideoBuffer::NoHandle) {
        return QList<QVideoFrame::PixelFormat>()
                << QVideoFrame::Format_RGB32
                << QVideoFrame::Format_ARGB32
                << QVideoFrame::Format_ARGB32_Premultiplied
                << QVideoFrame::Format_RGB565
                << QVideoFrame::Format_RGB555;
    } else {
        return QList<QVideoFrame::PixelFormat>();
    }
}

bool Surface::start(const QVideoSurfaceFormat &format)
{
    if (isFormatSupported(format)) {
        mImageFormat = QVideoFrame::imageFormatFromPixelFormat(format.pixelFormat());
        mImageSize = format.frameSize();
        //framePainted = true;

        QAbstractVideoSurface::start(format);

        return true;
    } else {
        return false;
    }
}

void Surface::stop()
{
    mFrame = QVideoFrame();
    QAbstractVideoSurface::stop();
}

bool Surface::present(const QVideoFrame &frame)
{
    mFrame = frame;
    emit frameRecieved();
    return true;
}

QVideoFrame Surface::frame() const
{
    return mFrame;
}

const QImage::Format &Surface::imageFormat() const
{
    return mImageFormat;
}

const QSize &Surface::imageSize() const
{
    return mImageSize;
}

