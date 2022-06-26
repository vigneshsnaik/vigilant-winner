
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

const int sampleRate = 44100;
const int bitDepth = 16;
float angle = 0.0f, offset = 0.0f;

void Oscillator(float freq){
    offset = 2 * M_PI * freq / sampleRate;
}

float SineOsc() {
    auto sample =sin(angle);
    angle += offset;
    return sample;
}


void writeToFile(ofstream &file, int value, int size) {
    file.write(reinterpret_cast<const char*> (&value), size);
}

int file_generator(float fr, float amp,int duration){
    
    string str_fr=to_string(int(fr));
    string str_duration=to_string(duration);
    string filename=str_fr+"Hz_"+str_duration+"s.wav" ;
    ofstream audioFile;
    audioFile.open(filename, ios::binary);
    Oscillator(fr);

    //Header chunk
    audioFile << "RIFF";
    audioFile << "----";
    audioFile << "WAVE";

    // Format chunk
    audioFile << "fmt ";
    writeToFile(audioFile, 16, 4); // Size
    writeToFile(audioFile, 1, 2); // Compression code
    writeToFile(audioFile, 1, 2); // Number of channels
    writeToFile(audioFile, sampleRate, 4); // Sample rate
    writeToFile(audioFile, sampleRate * bitDepth / 8, 4 ); // Byte rate
    writeToFile(audioFile, bitDepth / 8, 2); // Block align
    writeToFile(audioFile, bitDepth, 2); // Bit depth

    //Data chunk
    audioFile << "data";
    audioFile << "----";

    int preAudioPosition = audioFile.tellp();

    auto maxAmplitude = pow(2, bitDepth - 1) - 1;
    for(int i = 0; i < sampleRate * duration; i++ ) {
        auto sample = SineOsc();
        int intSample = static_cast<int> (sample * maxAmplitude);
        writeToFile(audioFile, intSample, 2);
    }
    int postAudioPosition = audioFile.tellp();

    audioFile.seekp(preAudioPosition - 4);
    writeToFile(audioFile, postAudioPosition - preAudioPosition, 4);

    audioFile.seekp(4, ios::beg);
    writeToFile(audioFile, postAudioPosition - 8, 4);

    audioFile.close();
    return 0;
}

int main() {
    int duration = 2;
    float fr=440.0,amp=1;
    printf("\nEnter the requirments\n");

    printf("Duration (in seconds)= ");
    cin>> duration;

    if(duration>=100||duration<1){
        printf("Duration too large, Durtion set to default (10s)\n");
        duration=10;
    }

    file_generator(fr,amp,duration);

    return 0;

}
