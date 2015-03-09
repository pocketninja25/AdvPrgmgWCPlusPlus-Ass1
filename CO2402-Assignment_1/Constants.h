#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using std::string;

const unsigned char gPOUND = 156;	//The ASCII value of the £ symbol

//Enum of different kinds of player pieces
enum EPlayerPieces {PIECE_DOG, PIECE_CAR, PIECE_BOAT, PIECE_HORSE, PIECE_HAT, PIECE_IRON, PIECE_BOOT, PIECE_WHEELBARROW, PIECE_THIMBLE, PIECE_CANNON, PIECE_SIZE};

//Array that corresponds EPlayerPieces to a string 'textual' value
const string gPIECE_NAMES[PIECE_SIZE] = { "Dog", "Car", "Boat", "Horse", "Hat", "Iron", "Boot", "Wheelbarrow", "Thimble", "Cannon" };

//Different kinds of game board squares
enum ESquareCategory {CATEGORY_PROPERTY, CATEGORY_GO, CATEGORY_RETAILPARK, CATEGORY_BONUS, CATEGORY_PENALTY, CATEGORY_JAIL, CATEGORY_GOTOJAIL, CATEGORY_FREEPARKING};

//Different property colour groups
enum EPropertyGroup {GROUP_APPLE, GROUP_STRAWBERRY, GROUP_GRAPE, GROUP_ORANGE, GROUP_BANANA, GROUP_PEAR, GROUP_BLACKCURRANT, GROUP_DAMSON, GROUP_RETAILPARK};

#endif