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
 along with AppleShowAllFiles.  If not, see <http://www.gnu.org/licenses/>.
 */

//
//  hiddenFilesManager.hpp
//  AppleShowAllFiles
//
//  Created by Manuel Martinez Martin on 19/2/17.
//  Copyright © 2017 Manuel Martinez Martin. All rights reserved.
//

#ifndef hiddenFilesManager_hpp
#define hiddenFilesManager_hpp

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
    bool fileStatus();
    int changeStatus();
#ifdef __cplusplus
}
#endif

#endif /* hiddenFilesManager_hpp */
