#ifndef Q_TTS_H
#define Q_TTS_H

#include <ActiveQt/QAxObject>

class Q_TTS
{
    //Q_OBJECT

public:
    Q_TTS();
    ~Q_TTS();

public:
    // 朗读英文
    void speakLatin(const QString& text);
    void speakLatin(const char* text);

    // 朗读中文
    void speakChinese(const QString& text);
    void speakChinese(const char* text);

private:
    void startSpeak(const QString& text);
    bool isSpeakerReady(const QString& key);

private:
    mutable QAxObject m_voice;
    static const QString EnglishVoiceKey;
    static const QString ChineseVoiceKey;
    static const QString clsidSpObjectToken;
    static const QString clsidSpVoice;
};

#endif // Q_TTS_H
