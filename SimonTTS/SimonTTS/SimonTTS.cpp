#include "SimonTTS.h"

SimonTTS::SimonTTS()
{
}

//Loads individual audio files
//************************************
// Method:    loadAudioFile
// FullName:  SimonTTS::loadAudioFile
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: const std::string & path : path to file
// Parameter: const char & id : identifier for the file being added
//************************************
void SimonTTS::loadAudioFile(std::string path, const char& id)
{
	//load into buffer
	m_buffer.loadFromFile(path);
	//create new pointer to a sound and add buffer
	std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>();
	sound->setBuffer(m_buffer);

	//add to map
	sfxMap.insert({ id, sound });

}


//************************************
// Method:    loadAToZFiles
// Returns:   void
// Parameter: const char * path : path to beginning file
// Parameter: char id : identifier for the sound, default is 'a'
//************************************
///Loads 26 individual audio files, one for each character of the alphabet.
///Defaulted to 'a' as the beginning character id.
///Function works only if files are named sequentially e.g. "a.wav, b.wav, c.wav ... z.wav".
void SimonTTS::loadAToZFiles(std::string path, char id = 'a')
{
	char tempID = id;
	std::string folder = "";

	std::filesystem::path p = path;
	folder = p.parent_path().string;

	//if (path.find("/"))
	//{
	//	size_t found;
	//	found = path.find_last_of("/\\");
	//	folder = path.substr(0, found);
	//}

	for (int i = 0; i < 26; i++)
	{
		//Change path to match ID;
		//load into buffer
		m_buffer.loadFromFile(folder + id);
		//create new pointer to a sound and add buffer
		std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>();
		sound->setBuffer(m_buffer);

		//add to map
		sfxMap.insert({ tempID, sound });
		
		//Increment ID.
		tempID++;
	}
}



//************************************
// Method:    loadAudioFile
// Returns:   void
// Parameter: const std::string & path : path to file
// Parameter: const char & id : identifier for file
// Parameter: const unsigned int & gap : gap in milliseconds between one part of audio and the next
//************************************
void SimonTTS::loadAudioFile(const std::string path, const char& id, const unsigned int& gap)
{

}

void SimonTTS::play(std::string message)
{

}


//************************************
// Method:    setVoicePitch
// Returns:   void
// Parameter: const float & pitch : pitch of the track, default is 1.0
// Note higher will play the sound faster, lower will be slower.
//************************************
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
