#include <stdexcept>
#include <iostream>
#include <map>
#include <string>

class Song
{
public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist()
    {
        /* A playlist is considered a repeating playlist if 
        any of the songs contain a pointer to a previous song
        in the playlist. Otherwise, the playlist will end with
        the last song which points to NULL */

    std::cout<<"Song "<<this->name<<" Points "<<this->nextSong->name <<std::endl;

       if (this->nextSong == nullptr)
           return false;  //song list ends

       for (Song *p=this->nextSong;p->nextSong != nullptr;p=p->nextSong){
           if(p->name.compare(this->name)==0){
               return true;
           }
       }
       return false;
    }

    bool isRepeatingPlaylistTwo()
    {
        if (this->nextSong == nullptr)
            return false;  // song list ends

        std::map<std::string,int> songList;  // empty map container

        for(Song *p=this;p != nullptr;p=p->nextSong){
            songList[p->name]=1;
        }
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");
    Song* third = new Song("We are the world");
    Song* fourth = new Song("Beautiful Day");
    
    first->next(second);
    second->next(first);

    third->next(fourth);

    std::cout << std::boolalpha << first->isRepeatingPlaylist()<<std::endl;
    second->next(NULL);
    std::cout << std::boolalpha << first->isRepeatingPlaylist()<<std::endl;
    std::cout << std::boolalpha << third->isRepeatingPlaylist()<<std::endl;
}
#endif