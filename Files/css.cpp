#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class video{
    public:
        std::string id;
        std::string name;
        std::string genre;
        int length;
        float rating;
        std::string comment;
        std::string episode;

        video(std::string id,
        std::string name,
        std::string genre,
        int length,
        float rating,
        std::string comment){
            video::id = id;
            video::name = name;
            video::genre = genre;
            video::length = length;
            video::rating = rating;
            video::comment = comment;
        }

        video(std::string id,
        std::string episode, 
        std::string name,
        std::string genre,
        int length,
        float rating,
        std::string comment){
            video::id = id;
            video::episode = episode;
            video::name = name;
            video::genre = genre;
            video::length = length;
            video::rating = rating;
            video::comment = comment;
        }

};

class movies{
    private:
        std::vector<video> movies;

    public:
        void readinfo()
        {
            std::ifstream file;
            file.open("movies.csv");
            std::string line, word;
            std::string row[6];
            while(getline(file, line))
            {
                std::stringstream ss(line);
                int i = 0;
                while(getline(ss, word, ',' ))
                {
                    row[i] = word;
                    i++;
                }
                movies.push_back(video(row[0], row[1], row[2], stoi(row[3]), stof(row[4]), row[5]));
            }
            file.close();
        }
};

class series{
private:
        std::vector <video> series;

    public:
        void readinfo()
        {
            std::ifstream file;
            file.open("series.csv");
            std::string line, word;
            std::string row[7];
            int j = 0;
            while(getline(file, line))
            {
                std::stringstream ss(line);
                int i = 0;
                while(getline(ss, word, ',' ))
                {
                    row[i] = word;
                    i++;
                }
                series.push_back(video(row[0], row[1], row[2], row[3], stoi(row[4]), stof(row[5]), row[6]));
            }
            file.close();
        }
};

