#include<fstream>
#include<iostream>
#include<string>

#include "MapManager.h"

using namespace std;

MapManager::MapManager(): width(0), height(0){

}

MapManager::~MapManager(){}


void MapManager::update(){

}

void MapManager::drawMap(){
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			//tile.draw(tiles[i][j]);
		}
	}
}

bool MapManager::saveMap(std::string mapPath){
	return false;
}

bool MapManager::loadMap(string mapPath){
	ifstream file(mapPath);
	string strNum;

	if(file.is_open()){ // if opened properly
		string line;
		cout << "Opened map data for reading" << endl;
		cout << "Reading map data" << endl;

		while(getline(file, line)){
			vector<int> tempVec;
			for(int lineCycle = 0; lineCycle < line.length(); lineCycle++){//Cycle through the current row of tiles.
				if(line[lineCycle] == ','){
					tempVec.push_back(stoi(strNum));
					strNum.clear();
					continue;
				}
				string temp;
				temp = line[lineCycle];
				strNum.append(temp);
			}
			tiles.push_back(tempVec);
		}
		file.close();
		cout << "Map is loaded. Closing file." << endl << endl;
		
		height = tiles.size();
		width = tiles[0].size();
		cout << "Map height: " << height << endl;
		cout << "Map width: " << width << endl;
		cout << height*width << " tiles loaded" << endl;
		printMap();
	} else{
		cout << "Invalid file path to map data!" << endl;
		return false;
	}

	return true;
}


void MapManager::printMap(std::string mapPath){

}

void MapManager::printMap(){

	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			cout << tiles[i][j];
			if((i == height - 1 && j == width - 1))//Don't print a comma after the last tile
				continue;
			cout << ", ";
		}
		cout<<endl;
	}
}

std::vector<std::vector<int>>* MapManager::getMap(){
	return &tiles;
}