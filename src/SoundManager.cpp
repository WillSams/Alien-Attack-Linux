#include "SoundManager.h"

SoundManager* SoundManager::s_pInstance;

SoundManager* SoundManager::Instance()  {
    if(s_pInstance == 0)
    {
        s_pInstance = new SoundManager();
        return s_pInstance;
    }
    return s_pInstance;
}

SoundManager::SoundManager()
{
    int flags = MIX_INIT_OGG | MIX_INIT_MP3;
    int initted = Mix_Init(flags);
    if((initted & MIX_INIT_MP3) == 0)
    {
        std::cout << "Could not init MP3 support: " << Mix_GetError() << std::endl;
    }

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
    {
        std::cout << "Could not open audio: " << Mix_GetError() << std::endl;
    }
}

SoundManager::~SoundManager()
{
    Mix_CloseAudio();
    Mix_Quit();
}

bool SoundManager::load(std::string fileName, std::string id, sound_type type)
{
    fileName = DATA_PREFIX "sfx/" + fileName;
    if(type == SOUND_MUSIC)
    {
        Mix_Music* pMusic = Mix_LoadMUS(fileName.c_str());
        if(pMusic == 0)
        {
            std::cout << "Could not load music: ERROR - " << Mix_GetError() << std::endl;
            return false;
        }
        
        m_music[id] = pMusic;
        return true;
    }
    else if(type == SOUND_SFX)
    {
        Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());
        if(pChunk == 0)
        {
            std::cout << "Could not load SFX: ERROR - " << Mix_GetError() << std::endl;
            return false;
        }
        
        m_sfxs[id] = pChunk;
        return true;
    }
    return false;
}

void SoundManager::playMusic(std::string id, int loop)
{
    Mix_PlayMusic(m_music[id], loop);
}

void SoundManager::playSound(std::string id, int loop)
{
    Mix_PlayChannel(-1, m_sfxs[id], loop);
}

void SoundManager::clearSoundMap() {
	for(auto i=m_music.begin();i!=m_music.end();i++){
		if(i->second!=nullptr){
			Mix_FreeMusic(i->second);
			i->second=nullptr;
		}
	}
	m_music.clear();

	for(auto j=m_sfxs.begin();j!=m_sfxs.end();j++){
		if(j->second!=nullptr){
			Mix_FreeChunk(j->second);
			j->second=nullptr;			
		}
	}
	m_sfxs.clear();
}