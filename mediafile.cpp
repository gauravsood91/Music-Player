#include "mediafile.h"


mediaobject::mediaobject()
{
    mobj = new Phonon::MediaObject(this);
}

void mediaobject::playFile(QString filename)
{
    mobj->setCurrentSource(Phonon::MediaSource(filename));
    audioOutput =new Phonon::AudioOutput(Phonon::MusicCategory, this);
    path = Phonon::createPath(mobj, audioOutput);
    mobj->play();
}

void mediaobject::pauseFile()
{
    mobj->pause();
}

void mediaobject::stopFile()
{
    mobj->stop();
}
