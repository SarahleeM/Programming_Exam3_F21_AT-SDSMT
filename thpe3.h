#pragma once
#include <cmath>
#include <cctype>
#include <string>
#include <iostream> 
#include <fstream>
#include <random>
#include <iomanip>

using namespace std;

// Global Constants 
/**
* @brief number asigned to Royal Flush
*/
const int royalFlush = 9;
/**
* @brief number asigned to Straight Flush
*/
const int straightFlush = 8;
/**
* @brief number asigned to 4 of a Kind
*/
const int fourKind = 7;
/**
* @brief number asigned to Full House
*/
const int fullHouse = 6;
/**
* @brief number asigned to Flush
*/
const int flushVal = 5;
/**
* @brief number asigned to Straight
*/
const int straightVal = 4;
/**
* @brief number asigned to 3 of a Kind
*/
const int threeKind = 3;
/**
* @brief number asigned to Two Pair
*/
const int twoPair = 2;
/**
* @brief number asigned to 2 of a Kind
*/
const int twoKind = 1;
/**
* @brief number asigned to High Card
*/
const int highCard = 0;

struct cardType
{ 
   int face;
   int suit;
};

struct handVal
{
   double royalFlushQuant = 0;
   double straightFlushQuant = 0;
   double fourKindQuant = 0;
   double fullHouseQuant = 0;
   double flushQuant = 0;
   double straightQuant = 0;
   double thrKindQuant = 0;
   double twoPairQuant = 0;
   double twoKindQuant = 0;
   double highCardQuant = 0;
};

//Write prototypes here

void usage();

void fileOutput( ofstream &datafile, handVal fullHand, handVal fullHandStats, int handsDealt );

void outputMessage( handVal fullHand, handVal fullHandStats, int handsDealt );

bool openInput( ifstream &datafile, string input );

bool openOutput( ofstream &datafile, string output );

void assignHand( int hand[], cardType fullHand[] );

void sortHand( int hand[], int size );

bool isRoyalFlush( cardType fullHand[] );

bool isStraightFlush( cardType fullHand[] );

bool isFourKind( cardType fullHand[] );

bool isFullHouse( cardType fullHand[] );

bool isThrKind( cardType fullHand[] );

bool isTwoKind( cardType fullHand[] );

bool isFlush( cardType fullHand[] );

bool isStraight( cardType fullHand[] );

bool isTwoPair( cardType fullHand[] );

int classifyHand( int hand[], int size );
