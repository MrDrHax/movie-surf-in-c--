/*
Problem situation

Copyright 2021 Alejandro Fernandez del Valle, Joshua Amaya, Andrea Yela.

This file is part of Movie Surf in c++.

Movie Surf in c++ is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Movie Surf in c++ is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Movie Surf in c++.  If not, see <https://www.gnu.org/licenses/>.

This file is the main part of the project.
*/

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>

namespace media{
    /// Parent class 
    class video{
        public:
            std::string id;
            std::string name;
            std::string genre;
            int length;
            float rating;
            std::string comment;
            std::string episode;
        
            /// Constructor of video for movie
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
                video::episode = "N/A";
            }
            
            /// Constructor of video for series
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

    class SearchInfo{
        public:
        ///Method to search the info as the user request
        virtual void Search(std::vector<media::video> * searchIn){
            int Data;
            int moviesData;
            int seriesData;

            ///User display
            std::cout<<"What do you want to see?     |       Movies (0)      |       Series (1)       |\n";
            std::cin>>Data;

            if(Data == 0){
                std::cout<<"Type of filter      |       Rating (0)      |       Genre (1)       |       Name (2)        |       ID (3)\n";
                std::cin>>moviesData;

                if(moviesData == 0){
                    float movieRating;

                    std::cout<<"Introduce the rating value of the movie:\n";
                    std::cin>>movieRating;
                    for(int i = 0; i< (*searchIn).size(); i++){
                        if((*searchIn)[i].rating == movieRating){ 
                            std::cout<<(*searchIn)[i].id<<"\t"<<(*searchIn)[i].name<<"\t\t"<<(*searchIn)[i].genre<<"\t\t\t"<<(*searchIn)[i].length<<"\t\t\t\t"<<(*searchIn)[i].rating<<"\t\t\t\t\t"<<(*searchIn)[i].comment<<"\n";
                        }
                    }
                }

                else if(moviesData == 1){
                    std::string movieGenre;

                    std::cout<<"Introduce the genre of the movie:\n";
                    std::cin>>movieGenre;
                    for(int i = 0; i< (*searchIn).size(); i++){
                        if((*searchIn)[i].genre == movieGenre){
                            std::cout<<(*searchIn)[i].id<<"\t"<<(*searchIn)[i].name<<"\t\t"<<(*searchIn)[i].genre<<"\t\t\t"<<(*searchIn)[i].length<<"\t\t\t\t"<<(*searchIn)[i].rating<<"\t\t\t\t\t"<<(*searchIn)[i].comment<<"\n";
                        }
                    }
                }

                else if(moviesData == 2){
                    std::string movieName;

                    std::cout<<"Introduce the name of the movie:\n";
                    std::cin>>movieName;
                    for(int i = 0; i< (*searchIn).size(); i++){ 
                        if((*searchIn)[i].name == movieName){
                            std::cout<<(*searchIn)[i].id<<"\t"<<(*searchIn)[i].name<<"\t\t"<<(*searchIn)[i].genre<<"\t\t\t"<<(*searchIn)[i].length<<"\t\t\t\t"<<(*searchIn)[i].rating<<"\t\t\t\t\t"<<(*searchIn)[i].comment<<"\n";
                        }
                    }
                }

                else if(moviesData == 3){
                    std::string movieID;

                    std::cout<<"Introduce the ID of the movie:\n";
                    std::cin>>movieID;
                    for(int i = 0; i< (*searchIn).size(); i++){
                        if((*searchIn)[i].id == movieID){
                            std::cout<<(*searchIn)[i].id<<"\t"<<(*searchIn)[i].name<<"\t\t"<<(*searchIn)[i].genre<<"\t\t\t"<<(*searchIn)[i].length<<"\t\t\t\t"<<(*searchIn)[i].rating<<"\t\t\t\t\t"<<(*searchIn)[i].comment<<"\n";
                        }
                    }
                }

                else{
                    std::cout<<"Error! Please, enter a valid number...\n";
                }
            }

            else if(Data == 1){
                std::cout<<"Type of filter      |       Rating (0)      |       Genre (1)       |       Name (2)        |       ID (3)\n";
                std::cin>>seriesData;

                if(seriesData == 0){
                    float seriesRating;

                    std::cout<<"Introduce the rating value of the series:\n";
                    std::cin>>seriesRating;
                    for(int i = 0; i<(*searchIn).size(); i++){
                        if((*searchIn)[i].rating == seriesRating){
                            std::cout<<(*searchIn)[i].id<<"\t"<<(*searchIn)[i].name<<"\t\t"<<(*searchIn)[i].genre<<"\t\t\t"<<(*searchIn)[i].length<<"\t\t\t\t"<<(*searchIn)[i].rating<<"\t\t\t\t\t"<<(*searchIn)[i].comment<<"\n";
                        }
                    }
                }

                else if(seriesData == 1){
                    std::string seriesGenre;

                    std::cout<<"Introduce the genre of the series:\n";
                    std::cin>>seriesGenre;
                    for(int i = 0; i<(*searchIn).size(); i++){
                        if((*searchIn)[i].genre == seriesGenre){
                            std::cout<<(*searchIn)[i].id<<"\t"<<(*searchIn)[i].name<<"\t\t"<<(*searchIn)[i].genre<<"\t\t\t"<<(*searchIn)[i].length<<"\t\t\t\t"<<(*searchIn)[i].rating<<"\t\t\t\t\t"<<(*searchIn)[i].comment<<"\n";
                        }
                    }
                }

                else if(seriesData == 2){
                    std::string seriesName;

                    std::cout<<"Introduce the name of the series:\n";
                    std::cin>>seriesName;
                    for(int i = 0; i<(*searchIn).size(); i++){
                        if((*searchIn)[i].name == seriesName){
                            std::cout<<(*searchIn)[i].id<<"\t"<<(*searchIn)[i].name<<"\t\t"<<(*searchIn)[i].genre<<"\t\t\t"<<(*searchIn)[i].length<<"\t\t\t\t"<<(*searchIn)[i].rating<<"\t\t\t\t\t"<<(*searchIn)[i].comment<<"\n";
                        }
                    }
                }

                else if(seriesData == 3){
                    std::string seriesID;

                    std::cout<<"Introduce the ID of the series:\n";
                    std::cin>>seriesID;
                    for(int i = 0; i<(*searchIn).size(); i++){
                        if((*searchIn)[i].id == seriesID){
                            std::cout<<(*searchIn)[i].id<<"\t"<<(*searchIn)[i].name<<"\t\t"<<(*searchIn)[i].genre<<"\t\t\t"<<(*searchIn)[i].length<<"\t\t\t\t"<<(*searchIn)[i].rating<<"\t\t\t\t\t"<<(*searchIn)[i].comment<<"\n";
                        }
                    }
                }

                else{
                    std::cout<<"Error! Please, enter a valid number...\n";
                }
            }

            else{
                std::cout<<"Error! Please, enter a valid number...\n";
            }
        }


        /// Function to search information on vectors (overload)
        /// @param field field to search, 1=name, 2=genre, 3=rating
        virtual void Search(std::string term, int field, std::vector<media::video> *output, std::vector<media::video> *input){
            switch (field)
            {
            case 1:
                ///Compare and return the name of the videos
                for(int i = 0; i<(*input).size(); i++){
                if((*input)[i].name == term){
                    (*output).push_back((*input)[i]);
                    }
                }
                
                break;
            
            case 2:
                ///Compare and return the genre of the videos
                for(int i = 0; i<(*input).size(); i++){
                if((*input)[i].genre == term){
                    (*output).push_back((*input)[i]);
                    }
                }
                
                break;
            
            case 3:    
                ///Compare and return the rating value of the videos
                for(int i = 0; i<(*input).size(); i++){
                    if((*input)[i].rating == /* COMPILER ERRORS */ std::stoi(term)){
                        (*output).push_back((*input)[i]);
                    }
                }
                break;

            default:
                break;
            }
        }
    };

    ///Class movie, derived public from SearchInfo
    class movies : public SearchInfo{
        public:
            std::vector<video> movies;
            ///Convert csv file into vectors
            void readinfo()
            {
                std::ifstream file;
                file.open("Files/movies.csv");
                std::string line, word;
                std::string row[6];
                while(std::getline(file, line))
                {
                    std::stringstream ss(line);
                    int i = 0;
                    while(std::getline(ss, word, ',' ))
                    {
                        row[i] = word;
                        i++;
                    }
                    movies.push_back(video(row[0], row[1], row[2], std::stoi(row[3]), /* COMPILER ERRORS */ std::stoi(row[4]), row[5]));
                }
                file.close();
            }
    };
    ///Class series, derived public SearchInfo
    class series : public SearchInfo{
        public:
            std::vector <video> series;

        public:
            ///Convert csv file into vectors
            void readinfo()
            {
                std::ifstream file;
                file.open("Files/series.csv");
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
                    series.push_back(video(row[0], row[1], row[2], std::stoi(row[3]), std::stoi(row[4]), row[5]));
                }
                file.close();
            }
    };

    /// Gets the input of the user, with error correction
    /// @param output string to display before waiting (Default ">>>")
    /// @return gets the int the the user has inputted (0 if error)
    int getIntInput(std::string output = ">>> "){
        int choice = 0;

        std::cout << output;

        if (!(std::cin >> choice)){
            // in case of input error:
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ERROR: Please enter a number!\n";
            return 0; // no need to run anything else!
        } 

        return choice;
    }
}

namespace mainMannager{
    class centerCode{
        public:
        ///Builds an instance of the center code!
        ///
        ///loads the file
        ///starts main loop
        centerCode(){
            loadFile();
            mainLoop();
        }

        media::movies movieMannager;
        media::series seriesMannager;

        ///The main code loop
        ///
        ///This keeps alive the code andruns the main loop
        void mainLoop(){
            while (printOptionsAndWaitAnswer());
        }

        /// reload everything, like if from scratch
        void reset(){
            movieMannager = media::movies();
            seriesMannager = media::series();

            loadFile();
        }

        /// Loads the files
        void loadFile(){
            movieMannager.readinfo();
            seriesMannager.readinfo();
        }
        
        /// Searches for video
        /// @param term the term to search for
        /// @param field the field to look for (rating, name, etc.)
        ///     1=name, 
        ///     2=genre, 
        ///     3=rating
        /// @param type the type of video to search for
        ///     0=all,
        ///     1=movie,
        ///     2=series
        /// @param output POINTER vector to where all the movies should be stored
        void searchMovie(std::string term, int field, int type, std::vector<media::video> *output){
            std::vector<media::video> temp;

            if (type == 0 || type ==1)
            {
                for (int i = 0; i < movieMannager.movies.size(); i++)
                {
                    temp.push_back(movieMannager.movies[i]);
                }
            }

            if (type == 0 || type ==2)
            {
                for (int i = 0; i < seriesMannager.series.size(); i++)
                {
                    temp.push_back(seriesMannager.series[i]);
                }
            }

            movieMannager.Search(term, field, output, &temp);
        }

        /// Print selection of videos
        /// @param toPrint POINTER, what videos should be printed
        void print(std::vector<media::video> *toPrint){
            
            std::cout <<  "ID\t|EPISODE\t|NAME\t|GENRE\t|DURATION\t|RATING\t|COMMENT\n";
            
            for (int i = 0; i < (*toPrint).size(); i++)
            {
                std::cout << (*toPrint)[i].id << "\t" << (*toPrint)[i].episode << "\t" << (*toPrint)[i].name << "\t" << (*toPrint)[i].genre <<"\t" << (*toPrint)[i].length << "\t" << (*toPrint)[i].rating << "\t" <<(*toPrint)[i].comment << "\n";
            }
        }

        /// Edit a file regestry
        /// @param line the video file that will be replaced
        /// @param rating the new rating
        /// @param comment the new comment
        /// @param file the file to edit
        void edit(media::video line, int rating, std::string comment, std::string file){
            std::string strReplace = "";
            std::stringstream strReplaceStream;
            std::stringstream strNewStream;
            std::string strNew = "";

            // create new and old strings as how they should appear on the file
            strReplaceStream << line.id << "," << line.name << "," << line.genre << "," << line.length << "," << line.rating << "," << line.comment;  
            strNewStream << line.id << "," << line.name << "," << line.genre << "," << line.length << "," << rating << "," << comment;

            // pass them to normal strings
            strReplace = strReplaceStream.str();
            strNew = strNewStream.str();

            std::ifstream filein(file); //File to read from
            std::ofstream fileout(".save"); //Temporary file, this is to not overwrite anything
            if(!filein || !fileout) // test to see if done correctly
            {
                std::cout << "Error opening files!" << std::endl;
                return;
            }

            /**/

            // Checks all the things and replaces them in new file
            std::string strTemp;
            while(std::getline(filein, strTemp))
            {
                if(strTemp == strReplace){
                    strTemp = strNew;
                }
                strTemp += "\n";
                fileout << strTemp;
            }

            // deletes old file, and replaces it with new one
            remove(const_cast<char*>(file.c_str()));

            rename(".save",const_cast<char*>(file.c_str()));

            std::cout << "Changes saved!";
        }

        /// Prints the options that are available and chooses the selection.
        /// Options are:
        /// 
        ///     Load data file.
        ///     Show the videos with a specific rating or from a specific genre.
        ///     Show the episodes of a specific series with a specific rating.
        ///     Show the movies with a specific rating.
        ///     Rate a video.
        ///     Exit
        /// 
        /// Calls the apropiate function
        /// @return True if continue. False if exit or error.
        bool printOptionsAndWaitAnswer(){
            try
            {
                std::cout << "SELECTION MENU\nPlease choose one of the following options\n";

                std::string options[] = {"Refresh file list.", "Show all","Search videos by genre/rating","Show series episodes by rating", "Search movies by rating", "rate a video", "Exit"}; 

                for (int i = 0; i < sizeof options/sizeof options[0]; i++)
                {
                    std::cout << "\t" << i+1 << ")" << options[i] << "\n";
                }
                
                int choice = media::getIntInput();

                switch (choice)
                {
                case 1:
                    /* Refresh file list. */
                    reset();
                    break;
                case 2:
                    /* Show all */
                    print(&movieMannager.movies);
                    print(&seriesMannager.series);
                    break;
                case 3:
                {
                    /* Search videos by genre/rating */
                    std::vector<media::video> *searchOutput = new std::vector<media::video>;

                    std::string *ratingGenre = new std::string;
                    int term = 0;

                    int type = media::getIntInput("What would you like to search for?\n\t1) Genre\n\t2) Rating\n>>>");
                    if (type == 1){
                        term = 2;
                        std::cout << "What Genre do you wish to search for?\n>>>";
                        std::cin >> *ratingGenre;
                    }else{
                        term = 3;
                        std::cout << "What Rating do you want to search for?\n>>>";
                        std::cin >> *ratingGenre;
                    }
                    
                    searchMovie(*ratingGenre, term, 0, searchOutput);

                    print(searchOutput);

                    delete searchOutput, term, ratingGenre; // no memory leaks plz
                    break;
                }
                case 4:
                {
                    /* Show series episodes by rating */

                    std::vector<media::video> *searchOutput = new std::vector<media::video>;

                    std::string *ratingGenre = new std::string;
                    std::string *term = new std::string;

                    *term = "Rating";
                    std::cout << "What Rating do you want to search for in series?\n>>>";
                    std::cin >> *ratingGenre;
                    
                    searchMovie(*ratingGenre, 3, 2, searchOutput);

                    print(searchOutput);

                    delete searchOutput, term, ratingGenre; // no memory leaks plz
                    break;
                }
                case 5:
                {
                    /* Search movies by rating */

                    std::vector<media::video> *searchOutput = new std::vector<media::video>;

                    std::string *ratingGenre = new std::string;
                    std::string *term = new std::string;

                    *term = "Rating";
                    std::cout << "What Rating do you want to search for in movies?\n>>>";
                    std::cin >> *ratingGenre;
                    
                    searchMovie(*ratingGenre, 3, 1, searchOutput);

                    print(searchOutput);

                    delete searchOutput, term, ratingGenre; // no memory leaks plz

                    break;
                }
                case 6:{
                    /* rate a video */
                    std::vector<media::video> searchoutput = std::vector<media::video>();

                    std::string searchTerm;
                    char searchTermTemp [20] = {0};

                    std::cout << "What title do you want to change?\n>>>";

                    std::cin.ignore();

                    std::cin.getline(searchTermTemp, 20);
                    searchTerm += searchTermTemp; 

                    std::vector<media::video> * searchThingys;

                    if (media::getIntInput("Edit (0) Movie/ (1) Series\n>>>")){
                        searchThingys = &seriesMannager.series;
                    }else{
                        searchThingys = &movieMannager.movies;
                    }

                    // add search here
                    
                    movieMannager.Search(searchTerm, 1, &searchoutput, searchThingys);

                    if (searchoutput.size() == 0)
                    {
                        std::cout << "Search turned null\n";
                        return true;
                    }
                    

                    int newRating = media::getIntInput("What is your rating?\n>>>");
                    std::string newComment = "";

                    std::cin.ignore();
                    
                    std::cout << "What comment do you want to leave?\n>>>";
                    std::cin.getline(searchTermTemp, 20, '\n');
                    newComment += searchTermTemp;

                    edit(searchoutput[0], newRating, newComment, "Files/movies.csv");

                    reset();
                    break;
                }
                case 7:
                    /* EXIT */
                    std::cout << "Exiting... ";
                    return false;
                    break;
                
                default:
                    /* In case of error */
                    std::cout << "Please enter a valid number\n";
                    break;
                }

                return true;
            }
            catch(const std::exception& e)
            {
                std::cout << "Error found in code! Extra info: ";
                std::cerr << e.what() << '\n';
                return false;
            }
        
        }
    };
}

int main(int argc, char const *argv[])
{
    std::cout << "Welcome to the GREAT movie selector!" << std::endl 

    << "We hope you enjoy our work." << std::endl << std::endl;

    // start system here

    mainMannager::centerCode surfer = mainMannager::centerCode();

    std::cout << "Hope to see you soon! c:\n";
    
    return 0;
}
