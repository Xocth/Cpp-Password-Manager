#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

class PasswordManager {
private:
    std::unordered_map<std::string, std::string> passwords;

public:
    void addPassword(const std::string& site, const std::string& password) {
        passwords[site] = password;
    }

    std::string getPassword(const std::string& site) {
        if (passwords.find(site) != passwords.end()) {
            return passwords[site];
        } else {
            return "Password not found!";
        }
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& pair : passwords) {
            file << pair.first << " " << pair.second << std::endl;
        }
        file.close();
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        std::string site, password;
        while (file >> site >> password) {
            passwords[site] = password;
        }
        file.close();
    }
};

int main() {
    PasswordManager pm;
    int choice;
    std::string site, password, filename;

    while (true) {
        std::cout << "1. Add Password\n2. Get Password\n3. Save to File\n4. Load from File\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter site: ";
                std::cin >> site;
                std::cout << "Enter password: ";
                std::cin >> password;
                pm.addPassword(site, password);
                break;
            case 2:
                std::cout << "Enter site: ";
                std::cin >> site;
                std::cout << "Password: " << pm.getPassword(site) << std::endl;
                break;
            case 3:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                pm.saveToFile(filename);
                break;
            case 4:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                pm.loadFromFile(filename);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }
}