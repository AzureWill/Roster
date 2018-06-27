
#include "q_tts.h"
#include <QDebug>
#include <QObject>

const QString Q_TTS::EnglishVoiceKey = QLatin1String("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\VW Julie");
const QString Q_TTS::ChineseVoiceKey = QLatin1String("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\ScanSoftMei-Ling_Full_22kHz");
//TTS引擎ID，上面是英文的，下面是中文的。这个可以根据自己电脑上的找。 通过在运行里输入regedit查找到。
const QString Q_TTS::clsidSpObjectToken = QLatin1String("{EF411752-3736-4CB4-9C8C-8EF4CCB58EFE}");
const QString Q_TTS::clsidSpVoice = QLatin1String("{96749377-3391-11D2-9EE3-00C04F797396}");
//在运行里面输入regedit 查找注册表，在 HKEY_LOCAL_MACHINE\\SOFTWARE\\CLasscs\\CLSID 下可以找到，它是一个类标识符，window下的每个应用，如网上邻居，
//回收站，都有自己的类识别符。 上面是TTS语音的类识别符。

Q_TTS::Q_TTS()
{

}

Q_TTS::~Q_TTS()
{

}

bool Q_TTS::isSpeakerReady(const QString& key)
{
    QAxObject obj(clsidSpObjectToken);
    if (obj.isNull())
    {
        qWarning() << "Failed to create SpObjectToken";
        return false;
    }

    obj.dynamicCall("SetId(const QString&)", key);
    m_voice.setProperty("Voice", obj.asVariant());
    return true;
}

void Q_TTS::speakLatin(const QString& text)
{
    if(isSpeakerReady(EnglishVoiceKey))
    {
        startSpeak(QLatin1String(text.toLatin1()));
    }
}
void Q_TTS::speakLatin(const char* text)
{
    speakLatin(text);
}

void Q_TTS::speakChinese(const char* text)
{
    speakChinese(QObject::tr(text));
}

void Q_TTS::speakChinese(const QString& text)
{
    if(isSpeakerReady(ChineseVoiceKey))
    {
        startSpeak(text);
    }
}

void Q_TTS::startSpeak(const QString& text)
{
    m_voice.setControl(clsidSpVoice);
    m_voice.dynamicCall("Speak(QString, SpeechVoiceSpeakFlags)", text, 0x0013);
}
