#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class Surface;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(Surface& surface, QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
protected:
    Surface& mSurface;
signals:

};

#endif // WIDGET_H
