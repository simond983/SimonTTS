#include "SimonTTS.h"

SimonTTS::SimonTTS()
{
}

//Loads individual audio files
void SimonTTS::loadAudioFile(const std::string& path, const char& id)
{
	//load into buffer
	m_buffer.loadFromFile(path);
	//create new pointer to a sound and add buffer
	std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>();
	sound->setBuffer(m_buffer);

	//add to map
	sfxMap.insert({ id, sound });

}

///Loads 26 individual audio files, one for each character of the alphabet.
///Defaulted to 'a' as the beginning character id.
///Function works best if files are named sequentially e.g. "a.wav, b.wav, c.wav ... z.wav".
void SimonTTS::loadAToZFiles(const char* path, char id = 'a')
{

	char tempID = id;

	for (int i = 0; i < 26; i++)
	{
		//load into buffer
		m_buffer.loadFromFile(path);
		//create new pointer to a sound and add buffer
		std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>();
		sound->setBuffer(m_buffer);

		//add to map
		sfxMap.insert({ tempID, sound });
		
		//Increment ID.
		tempID++;
	}
}

void SimonTTS::loadAudioFile(const std::string& path, const char& id, const unsigned int& gap)
{

}

void SimonTTS::play(std::string message)
{

}

///Function to set the pitch of each sound effect in the map.
///Note that pitch will also affect the playback speed of a sound.
///Default is 1, lower will be deeper, higher will be more high-pitched.
void SimonTTS::setVoicePitch(const float& pitch)
{
	//Iterator 
	std::unordered_map<char, std::shared_ptr<sf::Sound>>::iterator iter;

	//Go through each sound in the map and set its pitch.
	for (iter = sfxMap.begin(); iter != sfxMap.end(); iter++)
	{
		iter->second->setPitch(pitch);
	}
}
