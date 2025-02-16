#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "files.h"
#include "map.h"
#include "ops.h"

bool checkDirExists(const char* dirname){
	DIR* dir = opendir(dirname);
	if(dir){
		closedir(dir);
		return true;
	}else{
		return false;
	}
}

// this is certainly vulnerable to path injection
// due to the lack of input handling and the expansion of the 
// relative path...
// FIXME: path injection and path validation
void createDb(char* name){
	char* dirname = "~/.tensdb";
	char constructedPath[512];

	snprintf(constructedPath, sizeof(constructedPath), "%s/%s", dirname, name);
	
	if(checkDirExists(dirname) == false){
		int status = mkdir(dirname, 0644);

		if(status != 0){
			perror("Error creating directory");
			return;
		}
	}

	createFile(constructedPath);
}
