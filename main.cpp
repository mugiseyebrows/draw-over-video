#include <QApplication>

#include "surface.h"
#include "widget.h"
#include <QMediaPlayer>
#include <QMediaContent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Surface surface;
    Widget widget(surface);
    widget.show();

    QMediaPlayer player;
    player.setVideoOutput(&surface);
    player.setMedia(QMediaContent(QUrl("D:/w/sample_960x400_ocean_with_audio.mp4")));
    player.play();

    return a.exec();
}
