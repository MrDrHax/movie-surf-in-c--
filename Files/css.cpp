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
        string name,
        string genre,
        int length,
        float rating,
        string comment, string episode){
            video::id = id;
            video::name = name;
            video::genre = genre;
            video::length = length;
            video::rating = rating;
            video::comment = comment;
            video::episode = episode;

        }

};

class movies{
    private:
        int quantity;
        vector<video> videos;

    public:
        void readinfo()
        {
            ifstream file;
            file.open("movies.csv");
            string line, word;
            string row[6];
            int j = 0;
            quantity = 0;
            while(getline(file, line))
            {
                quantity ++;
                stringstream ss(line);
                int i = 0;
                while(getline(ss, word, ',' ))
                {
                    row[i] = word;
                    i++;
                }
                videos.push_back(new video(row[0], row[1], row[2], row[0], row[0], row[0], ));
                id [j] = row[0];
                name[j] = row[1];
                genre[j] = row[2];
                length [j] = stoi(row[3]);
                rating[j] = stoi(row[4]);
                comment[j] = row[5];
                j++;
            }
            file.close();
        }
};

class series : public video{
private:
        string episode[29];
        int quantity;

    public:
        void readinfo()
        {
            ifstream file;
            file.open("series.csv");
            string line, word;
            string row[7];
            int j = 0;
            quantity = 0;
            while(getline(file, line))
            {
                quantity ++;
                stringstream ss(line);
                int i = 0;
                while(getline(ss, word, ',' ))
                {
                    row[i] = word;
                    i++;
                }
                id [j] = row[0];
                episode[j] = row[1];
                name[j] = row[2];
                genre[j] = row[3];
                length [j] = stoi(row[4]);
                rating[j] = stoi(row[5]);
                comment[j] = row[6];
                j++;
            }
            file.close();
        }
};

