#include <iostream>
#include <string>

// Node structure to represent a song
struct Song {
    std::string title;
    std::string producer;
    std::string singer;
    std::string genre;
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
