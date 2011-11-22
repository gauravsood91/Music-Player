#ifndef MEDIAFILE_H
#define MEDIAFILE_H
#include<Phonon/MediaObject>
#include<Phonon/Path>
#include<Phonon/AudioOutput>

class mediaobject:public Phonon::MediaObject{
    Phonon::MediaObject *mobj;
    Phonon::AudioOutput *audioOutput;
    Phonon::Path path;
    Phonon::State newState;

public:
    mediaobject();
    void playFile(QString);
    void pauseFile();
    void stopFile();
};


#endif // MEDIAFILE_H
