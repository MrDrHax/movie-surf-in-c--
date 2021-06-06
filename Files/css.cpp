#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class video{
    public:
        string id;
        string name;
        string genre;
        int length;
        float rating;
        string comment;
        string episode;

        video(string id,
        string name,
        string genre,
        int length,
        float rating,
        string comment){
            video::id = id;
            video::name = name;
            video::genre = genre;
            video::length = length;
            video::rating = rating;
            video::comment = comment;
        }

        video(string id,
        string episode, 
        string name,
        string genre,
        int length,
        float rating,
        string comment){
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
        vector<video> movies;

    public:
        void readinfo()
        {
            ifstream file;
            file.open("movies.csv");
            string line, word;
            string row[6];
            while(getline(file, line))
            {
                stringstream ss(line);
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
        vector <video> series;

    public:
        void readinfo()
        {
            ifstream file;
            file.open("series.csv");
            string line, word;
            string row[7];
            int j = 0;
            while(getline(file, line))
            {
                stringstream ss(line);
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

