#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class video{
    protected:
        string id;
        string name;
        string genre;
        int length;
        float rating;
        string comment;

};

class movies : video{
    private:
        string id[30]; 
        string name[30];
        string genre[30];
        int length[30];
        float rating[30];
        string comment[30];
        int quantity;

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

class series : video{
private:
        string id[29];
        string episode[29];
        string name[29];
        string genre[29];
        int length[29];
        float rating[29];
        string comment[29];
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

