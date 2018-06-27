#ifndef TEXTSPEECH_H
#define TEXTSPEECH_H
#include <QObject>
#include <QAxObject>
#include <QRunnable>
#include <QQueue>

class TextSpeech : public QObject
{
    Q_OBJECT
public:
    explicit TextSpeech(QObject *parent = 0);
    ~TextSpeech();
    bool initSpeech();//初始化函数
    bool speak(QString txt);//文本转语音函数
    void setRate(int rate);//设置语速，范围-10到10
    void setVolume(int value);//设置音量，范围 0到100
    bool isSpeaking();

private:
    QAxObject _voice;
    bool _binit;
    bool _bReading;
    bool stopped;
    QQueue<QString> queue;
signals:
    void speakComplete();
private slots:
    void dealevent(QString name, int arc , void* argv);
};
#endif // TEXTSPEECH_H
