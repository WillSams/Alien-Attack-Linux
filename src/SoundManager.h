#ifndef SOUNDMANAGER_H_DEFINED
#define SOUNDMANAGER_H_DEFINED

#include <iostream>
#include <map>
#include <string>

#include <SDL2/SDL_mixer.h>

enum sound_type {
    SOUND_MUSIC = 1,
    SOUND_SFX = 1
};

class SoundManager {
    
public:    
    static SoundManager* Instance();
    
    bool load(std::string fileName, std::string id, sound_type type);
    
    void playSound(std::string id, int loop);
    void playMusic(std::string id, int loop);
    void clearSoundMap();
    
private:    
    static SoundManager* s_pInstance;
    
    std::map<std::string, Mix_Chunk*> m_sfxs;
    std::map<std::string, Mix_Music*> m_music;
    
    SoundManager();
    ~SoundManager();
    
    SoundManager(const SoundManager&);
	SoundManager& operator=(const SoundManager&);
};

typedef SoundManager TheSoundManager;

#endif /* defined(SOUNDMANAGER_H_DEFINED) */
