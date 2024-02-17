#include <iostream>
#include <string>

// Node structure to represent a song
struct Song {
  string title;
  string producer;
 string singer;
   string genre;
    Song* prev;
    Song* next;
    // Constructor
    Song(std::string _title, std::string _producer, std::string _singer, std::string _genre)
        : title(_title), producer(_producer), singer(_singer), genre(_genre), prev(nullptr), next(nullptr) {}
};
// Playlist class
class Playlist {
private:
    Song* head;
    Song* tail;
public:
    // Constructor
    Playlist() : head(nullptr), tail(nullptr) {}
    // Destructor to free memory
    ~Playlist() {
        Song* current = head;
        while (current != nullptr) {
            Song* temp = current;
            current = current->next;
            delete temp;
        }
    }
    // Function to add a song to the playlist
    void addSong(std::string title, std::string producer, std::string singer, std::string genre) {
        Song* newSong = new Song(title, producer, singer, genre);
        if (head == nullptr) {
            head = tail = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }
    // Function to display all songs in the playlist
    void displayPlaylist() {
        Song* current = head;
        std::cout << "Playlist:\n";
        while (current != nullptr) {
            std::cout << "Title: " << current->title << ", Producer: " << current->producer
                      << ", Singer: " << current->singer << ", Genre: " << current->genre << "\n";
            current = current->next;
        }
    }
    // Function to display songs by a specific producer
    void displayByProducer(std::string producer) {
        Song* current = head;
        std::cout << "Songs by producer " << producer << ":\n";
        while (current != nullptr) {
            if (current->producer == producer) {
                std::cout << "Title: " << current->title << ", Singer: " << current->singer
                          << ", Genre: " << current->genre << "\n";
            }
            current = current->next;
        }
    }

    // Function to display songs by a specific singer
    void displayBySinger(std::string singer) {
        Song* current = head;
        std::cout << "Songs by singer " << singer << ":\n";
        while (current != nullptr) {
            if (current->singer == singer) {
                std::cout << "Title: " << current->title << ", Producer: " << current->producer
                          << ", Genre: " << current->genre << "\n";
            }
            current = current->next;
        }
    }

    // Function to display songs of a specific genre
    void displayByGenre(std::string genre) {
        Song* current = head;
        std::cout << "Songs of genre " << genre << ":\n";
        while (current != nullptr) {
            if (current->genre == genre) {
                std::cout << "Title: " << current->title << ", Producer: " << current->producer
                          << ", Singer: " << current->singer << "\n";
            }
            current = current->next;
        }
    }
};

int main() {
    Playlist playlist;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a song\n";
        std::cout << "2. Display playlist\n";
        std::cout << "3. Display songs by producer\n";
        std::cout << "4. Display songs by singer\n";
        std::cout << "5. Display songs by genre\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, producer, singer, genre;
                std::cout << "Enter song title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter producer: ";
                std::getline(std::cin, producer);
                std::cout << "Enter singer: ";
                std::getline(std::cin, singer);
                std::cout << "Enter genre: ";
                std::getline(std::cin, genre);
                playlist.addSong(title, producer, singer, genre);
                break;
            }
            case 2:
                playlist.displayPlaylist();
                break;
            case 3: {
                std::string producer;
                std::cout << "Enter producer name: ";
                std::cin.ignore();
                std::getline(std::cin, producer);
                playlist.displayByProducer(producer);
                break;
            }
            case 4: {
                std::string singer;
                std::cout << "Enter singer name: ";
                std::cin.ignore();
                std::getline(std::cin, singer);
                playlist.displayBySinger(singer);
                break;
            }
            case 5: {
                std::string genre;
                std::cout << "Enter genre: ";
                std::cin.ignore();
                std::getline(std::cin, genre);
                playlist.displayByGenre(genre);
                break;
            }
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
//second 
#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    string producer;
    string singer;
    string genre;
    Song* next_song;
    Song* prev_song;

    Song(string t, string p, string s, string g) : title(t), producer(p), singer(s), genre(g), next_song(nullptr), prev_song(nullptr) {}
};

void addSong(Song*& head, string title, string producer, string singer, string genre) {
    Song* newSong = new Song(title, producer, singer, genre);

    if (!head) {
        head = newSong;
    } else {
        Song* currentSong = head;
        while (currentSong->next_song) {
            currentSong = currentSong->next_song;
        }
        currentSong->next_song = newSong;
        newSong->prev_song = currentSong;
    }
}

void displayByProducer(Song* head, string producer) {
    Song* currentSong = head;
    while (currentSong) {
        if (currentSong->producer == producer) {
            cout << "Title: " << currentSong->title << ", Singer: " << currentSong->singer << ", Genre: " << currentSong->genre << endl;
        }
        currentSong = currentSong->next_song;
    }
}

void displayBySinger(Song* head, string singer) {
    Song* currentSong = head;
    while (currentSong) {
        if (currentSong->singer == singer) {
            cout << "Title: " << currentSong->title << ", Producer: " << currentSong->producer << ", Genre: " << currentSong->genre << endl;
        }
        currentSong = currentSong->next_song;
    }
}

void displayByGenre(Song* head, string genre) {
    Song* currentSong = head;
    while (currentSong) {
        if (currentSong->genre == genre) {
            cout << "Title: " << currentSong->title << ", Producer: " << currentSong->producer << ", Singer: " << currentSong->singer << endl;
        }
        currentSong = currentSong->next_song;
    }
}

void displayPlaylist(Song* head) {
    Song* currentSong = head;
    while (currentSong) {
        cout << "Title: " << currentSong->title << ", Producer: " << currentSong->producer << ", Singer: " << currentSong->singer << ", Genre: " << currentSong->genre << endl;
        currentSong = currentSong->next_song;
    }
}

int main() {
    Song* playlist = nullptr;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Display by Producer" << endl;
        cout << "3. Display by Singer" << endl;
        cout << "4. Display by Genre" << endl;
        cout << "5. Display Entire Playlist" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, producer, singer, genre;
                cout << "Enter song title: ";
                cin>>title;
                cout << "Enter producer: ";
                cin>>producer;
                cout << "Enter singer: ";
                cin>>singer;
                cout << "Enter genre: ";
                cin>>genre;
                addSong(playlist, title, producer, singer, genre);
                break;
            }
            case 2: {
                string producer;
                cout << "Enter producer to display songs: ";
                cin>>producer;
                displayByProducer(playlist, producer);
                break;
            }
            case 3: {
                string singer;
                cout << "Enter singer to display songs: ";
                cin>>singer;
                displayBySinger(playlist, singer);
                break;
            }
            case 4: {
                string genre;
                cout << "Enter genre to display songs: ";
                cin>>genre;
                displayByGenre(playlist, genre);
                break;
            }
            case 5:
                cout << "Displaying entire playlist:" << endl;
                displayPlaylist(playlist);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
