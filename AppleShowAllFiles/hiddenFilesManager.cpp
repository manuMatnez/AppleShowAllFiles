/*
 This file is part of AppleShowAllFiles.
 AppleShowAllFiles is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 AppleShowAllFiles is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with PersiautoCalculator.  If not, see <http://www.gnu.org/licenses/>.
 */

//
//  hiddenFilesManager.cpp
//  AppleShowAllFiles
//
//  Created by Manuel Martinez Martin on 19/2/17.
//  Copyright © 2017 Manuel Martinez Martin. All rights reserved.
//

#include "hiddenFilesManager.hpp"

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Gets current Status.
string currentStatus() {
    char buffer[128];
    std::string result = "";
    
    FILE* pipe = popen("defaults read com.apple.finder AppleShowAllFiles", "r");
    
    if (!pipe) throw std::runtime_error("popen() failed!");
    
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    
    string::size_type pos= result.find ("\n", 0);
    
    if (pos == string::npos) return result;
    
    result.replace (pos, 1, "");
    
    return result;
}

// Gets file Status
bool fileStatus() {
    string true1 = "TRUE";
    string true2 = "YES";
    string true3 = "1";
    
    if (currentStatus().compare(true1) == 0 || currentStatus().compare(true2) == 0
        || currentStatus().compare(true3) == 0) {
        return true;
    } else {
        return false;
    }
}

// Change Status by exec cmd
int changeStatus() {
    bool statusF = fileStatus();
    string newStatus;
    
    if (statusF) {
        newStatus = "FALSE";
    } else if (!statusF) {
        newStatus = "TRUE";
    } else {
        return -1;
    }
    system(("defaults write com.apple.finder AppleShowAllFiles "+ newStatus +"; killall Finder").c_str());
    return 0;
}
