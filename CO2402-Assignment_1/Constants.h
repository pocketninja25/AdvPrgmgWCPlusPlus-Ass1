#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using std::string;

const unsigned char POUND = 156;

enum EPlayerPieces {PIECE_DOG, PIECE_CAR, PIECE_SIZE};

const string PieceNames[PIECE_SIZE] = { "Dog", "Car" };

enum ESquareCategory {CATEGORY_PROPERTY, CATEGORY_GO, CATEGORY_RETAILPARK, CATEGORY_BONUS, CATEGORY_PENALTY, CATEGORY_JAIL, CATEGORY_GOTOJAIL, CATEGORY_FREEPARKING};

enum EPropertyGroup {GROUP_GREEN, GROUP_RED, GROUP_GREY, GROUP_ORANGE, GROUP_YELLOW, GROUP_DARKGREEN, GROUP_BLUE, GROUP_PURPLE, GROUP_RETAILPARK};

#endif;