#include "ecosystem.h"
#include "animal.h"
#include "organism.h"
#include "plant.h"
#include <iostream>
#include <string>

Ecosystem::Ecosystem() : organisms(nullptr), size(0) {};

Ecosystem::~Ecosystem() {
    clear();
}

void Ecosystem::clear()
{
    if (organisms != nullptr)
    {
        for (int i = 0; i < size; i++)
        {
            delete organisms[i];
        }
        delete[] organisms;
        organisms = nullptr;
    }
    size = 0;
}

bool Ecosystem::initialize(const string& input) {
    // Clear any existing organisms
    clear();

    // Count the number of organisms by counting the colons
    int count = 0;
    for (char c : input) {
        if (c == ':')
            count++;
    }

    // Allocate memory for organisms
    size = count + 1; // Number of segments is equal to number of colons + 1
    organisms = new Organism * [size];

    // Initialize index
    int index = 0;

    // Initialize pointers to nullptr
    for (int i = 0; i < size; ++i) {
        organisms[i] = nullptr;
    }

    // Start parsing input
    int startPos = 0;
    int endPos = input.find(':', startPos);

    while (endPos != string::npos) {
        string segment = input.substr(startPos, endPos - startPos);

        // Parse each segment
        string name, type;
        size_t hashPos = segment.find('#');
        if (hashPos != string::npos) {
            name = segment.substr(0, hashPos);
            type = segment.substr(hashPos + 1);

            // Create organism based on type
            if (type == "animal") {
                organisms[index] = new Animal(name);
            }
            else if (type == "plant") {
                organisms[index] = new Plant(name);
            }
            else {
                cerr << "Invalid type: " << type << endl;
                clear(); // Free memory before returning false
                return false;
            }
        }

        // Move to the next segment
        startPos = endPos + 1;
        endPos = input.find(':', startPos);
        index++;
    }

    // Parse the last segment
    string lastSegment = input.substr(startPos);
    string name, type;
    size_t hashPos = lastSegment.find('#');
    if (hashPos != string::npos) {
        name = lastSegment.substr(0, hashPos);
        type = lastSegment.substr(hashPos + 1);

        // Create organism based on type
        if (type == "animal") {
            organisms[index] = new Animal(name);
        }
        else if (type == "plant") {
            organisms[index] = new Plant(name);
        }
        else {
            cerr << "Invalid type: " << type << endl;
            clear(); // Free memory before returning false
            return false;
        }
    }

    return true;
}