#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <vector>
#include <string>
#include <algorithm>
#include "../models/Resturant.h"
using namespace std;

class ResturantManager {
private:
    vector<Resturant*> resturants;
    static ResturantManager* instance;

    ResturantManager() {
        // private constructor
    }

public:
    static ResturantManager* getInstance() {
        if (!instance) {
            instance = new ResturantManager();
        }
        return instance;
    }

    void addResturant(Resturant* r) {
        resturants.push_back(r);
    }

    vector<Resturant*> searchByLocation(string loc) {
        vector<Resturant*> result;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
        for (auto r : resturants) {
            string rl = r->getLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if (rl == loc) {
                result.push_back(r);
            }
        }
        return result;
    }
};

ResturantManager* ResturantManager::instance = nullptr;

#endif // RESTAURANT_MANAGER_H
