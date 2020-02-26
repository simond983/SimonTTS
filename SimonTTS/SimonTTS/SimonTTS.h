#ifndef SIMONTTS_H
#define SIMONTTS_H

#include "SFML/Audio.hpp"
#include <memory>
#include <unordered_map>
#include <filesystem>

class SimonTTS
{
public:
	SimonTTS();
	void loadAudioFile(std::string path, const char& id);
	void loadAToZFiles(std::string path, char id);
	void loadAudioFile(std::string path, const char& id, const unsigned int& gapBetweenSounds);
	void play(std::string message);
	void setVoicePitch(const float& pitch);

private:
	std::unordered_map<char, std::shared_ptr<sf::Sound>> sfxMap;
	sf::SoundBuffer m_buffer;

};

#endif
