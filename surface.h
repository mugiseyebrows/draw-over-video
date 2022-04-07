#ifndef SURFACE_H
#define SURFACE_H

#include <QAbstractVideoSurface>

class Surface : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    explicit Surface(QObject *parent = nullptr);

public:
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const;
    bool start(const QVideoSurfaceFormat &format);
    void stop();
    bool present(const QVideoFrame &frame);

    QVideoFrame frame() const;

    QImage::Format imageFormat() const;

    QSize imageSize() const;

signals:
    void frameRecieved();

protected:

    QImage::Format mImageFormat;
    QSize mImageSize;

    QVideoFrame mFrame;

};

#endif // SURFACE_H
