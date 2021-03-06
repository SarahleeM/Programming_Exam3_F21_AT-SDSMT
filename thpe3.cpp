#include "thpe3.h"

//write functions here
 /** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A void function that displays the usage statemtent for thpe3.exe
 *
 *  
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
    usage();
    
    

    @endverbatim
 ************************************************************************/ 
void usage()
{
    cout << "Usage: thpe3.exe -s seedValue quantity" << endl;
    cout << "       seedValue - # is integer for random numbers" << endl;
    cout << "       quantity - # of hands to deal" << endl << endl;
    cout << "       thpe3.exe -f inputfilename outputfilename" << endl;
    cout << "       inputfilename - filename containing the poker hands to classify" << endl;
    cout << "       outputfilename - filename to output the statistics in" << endl;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A void function that outputs the given information to the output file
 * 
 * @param[in] datafile the ofstream to output the data to 
 * @param[in] fullHand the structure holding the hand classifications
 * @param[in] fullHandStats the structure holding the hand classification stats
 * @param[in] handsDealt the int value for the number of total hands dealt
 *
 *  
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 *  ofstream datafile;
 *  handVal fullHand[5], fullHandStats[5];
 *  int handsDealt;
 * 
    fileOutput(datafile, fullHand, fullHandStats, handsDealt);
    //Outputs given data in correct format
    
    

    @endverbatim
 ************************************************************************/ 
void fileOutput( ofstream &datafile, handVal fullHand, handVal fullHandStats, int handsDealt )
{
    datafile << left;
    datafile << setw(20) << "Hand Name";
    datafile << right;
    datafile << setw(10) << "Dealt";
    datafile << setw(15) << "Chance" << endl;

    datafile << left;
    datafile << setw(20) << "Royal Flush";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.royalFlushQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.royalFlushQuant << "%" << endl;

    datafile << left;
    datafile << setw(20) << "Straight Flush";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.straightFlushQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.straightFlushQuant << "%" << endl;

    datafile << left;
    datafile << setw(20) << "Four of a Kind";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.fourKindQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.fourKindQuant << "%" << endl;

    datafile << left;
    datafile << setw(20) << "Full House";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.fullHouseQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.fullHouseQuant << "%" << endl;

    datafile << left;
    datafile << setw(20) << "Flush";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.flushQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.flushQuant << "%" << endl;

    datafile << left;
    datafile << setw(20) << "Straights";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.straightQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.straightQuant << "%" << endl;

    datafile << left;
    datafile << setw(20) << "Three of a Kind";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.thrKindQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.thrKindQuant << "%" << endl;

    datafile << left;
    datafile << setw(20) << "Two Pair";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.twoPairQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.twoPairQuant << "%" << endl;

    datafile << left;
    datafile << setw(20) << "Two of a Kind";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.twoKindQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.twoKindQuant << "%" << endl;

    datafile << left;
    datafile << setw(20) << "High Card";
    datafile << right;
    datafile << defaultfloat << setw(10) << fullHand.highCardQuant;
    datafile << fixed << setprecision(6) << setw(15) << fullHandStats.highCardQuant << "%" << endl;

    datafile << endl;
    datafile << left;
    datafile << setw(20) << "Total Hands Dealt";
    datafile << right;
    datafile << defaultfloat << setw(10) << handsDealt << endl;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A void function that outputs the given information to the console
 * @param[in] datafile the ofstream to output the data to 
 * @param[in] fullHand the structure holding the hand classifications
 * @param[in] fullHandStats the structure holding the hand classification stats
 * @param[in] handsDealt the int value for the number of total hands dealt
 *
 *  
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 *  ofstream datafile;
 *  handVal fullHand[5], fullHandStats[5];
 *  int handsDealt;
 * 
    outputMessage( datafile, fullHand, fullHandStats, handsDealt );
    //Outputs given data in correct format
    
    

    @endverbatim
 ************************************************************************/ 
void outputMessage( handVal fullHand, handVal fullHandStats, int handsDealt )
{
    cout << left;
    cout << setw(20) << "Hand Name";
    cout << right;
    cout << setw(10) << "Dealt";
    cout << setw(15) << "Chance" << endl;

    cout << left;
    cout << setw(20) << "Royal Flush";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.royalFlushQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.royalFlushQuant << "%" << endl;

    cout << left;
    cout << setw(20) << "Straight Flush";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.straightFlushQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.straightFlushQuant << "%" << endl;

    cout << left;
    cout << setw(20) << "Four of a Kind";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.fourKindQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.fourKindQuant << "%" << endl;

    cout << left;
    cout << setw(20) << "Full House";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.fullHouseQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.fullHouseQuant << "%" << endl;

    cout << left;
    cout << setw(20) << "Flush";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.flushQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.flushQuant << "%" << endl;

    cout << left;
    cout << setw(20) << "Straights";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.straightQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.straightQuant << "%" << endl;

    cout << left;
    cout << setw(20) << "Three of a Kind";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.thrKindQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.thrKindQuant << "%" << endl;

    cout << left;
    cout << setw(20) << "Two Pair";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.twoPairQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.twoPairQuant << "%" << endl;

    cout << left;
    cout << setw(20) << "Two of a Kind";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.twoKindQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.twoKindQuant << "%" << endl;

    cout << left;
    cout << setw(20) << "High Card";
    cout << right;
    cout << defaultfloat << setw(10) << fullHand.highCardQuant;
    cout << fixed << setprecision(6) << setw(15) << fullHandStats.highCardQuant << "%" << endl;

    cout << endl;
    cout << left;
    cout << setw(20) << "Total Hands Dealt";
    cout << right;
    cout << defaultfloat << setw(10) << handsDealt << endl;
}

 /** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that opens the input file
 *
 *  @param[in] datafile The input file to be opened 
 *  @param[in] input the string holding the input file name
 *  
 *  @returns True if the input file opens and False if the input file fails to open
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * ifstream inputFile;
 * string fileName = file1.txt;
 * bool tf;
 * 
    tf = openInput( inputFile, fileName );
    //True if the file opens
    //False if the file fails to open
    
    
    
    

    @endverbatim
 ************************************************************************/ 
bool openInput( ifstream &datafile, string input )
{
    datafile.open( input );
    if( !datafile.is_open() )
    {
        return false;
    }
    return true;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that opens the output file
 *
 *  @param[in] datafile The output file to be opened 
 *  @param[in] output the string holding the output file name
 *  
 *  @returns True if the output file opens and False if the output file fails to open
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * ifstream outputFile;
 * string fileName = fileOut1.txt;
 * bool tf;
 * 
    tf = openOutput( outputFile, fileName );
    //True if the file opens
    //False if the file fails to open
    
    
    
    

    @endverbatim
 ************************************************************************/ 
bool openOutput( ofstream &datafile, string output )
{
    datafile.open( output );
    if( !datafile.is_open() )
     {
        return false;
    }
    return true;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A void function that takes the integer hand values and converts them to their
 * suit and face values
 *
 *  @param[in] hand The integer array holding the card values 
 *  @param[in] fullHand the face and suit values for the hand
 *  
 *  
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * int hand[5] = { 0, 1, 2, 3, 4};
 * cardtype fullHand[5];
 * 
    assignHand( hand, fullHand );
    //fullHand[0].face == 0;
    //fullHand[0].suit == 0;
    
    
    
    

    @endverbatim
 ************************************************************************/ 
void assignHand( int hand[], cardType fullHand[] )
{
    int i;
    for(i=0; i<5; i++)
    {
        fullHand[i].face = ( hand[i] % 13 );
        fullHand[i].suit = ( hand[i] / 13 );
    }
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A void function that takes the integer hand values and sorts them
 *
 *  @param[in] hand The integer array holding the card values 
 *  @param[in] size The size of the array
 *  
 *  
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * int hand[5] = { 4, 1, 3. 2. 0};
 * int size = 5;
 * 
   sortHand( hand, size );
    // hand[5] == { 0, 1, 2, 3, 4 }
    
    
    

    @endverbatim
 ************************************************************************/ 
void sortHand( int hand[], int size )
{
    int i, j, minIndex;
    for(i=0; i<size-1; i++)
    {
        minIndex = i;
        for(j=i+1; j<size; j++)
        {
            if( hand[j] < hand[minIndex] )
            {
                minIndex = j;
            }
        }
        swap( hand[i], hand[minIndex] );
    }
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that checks if the hand is a royal flush
 *
 *  @param[in] fullHand The array holding the hands suits and face values
 *  
 *  @returns True if the hand is a royal flush and False if the hand isnt
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * cardType fullHand[];
 * bool tf;
 * 
 * tf = isRoyalFlush( fullHand );
 * // tf == true if the hand is a royal flush
 * // tf == false if the hand is not a royal flush
    
    
    

    @endverbatim
 ************************************************************************/ 
bool isRoyalFlush( cardType fullHand[] )
{
    int i;
    //Im using bottom to match if theres 10-king
    int bottom = 9;

    //Looping to check if they are all the same suit
    for(i=0; i<5; i++)
    {
        if( fullHand[i].suit != fullHand[0].suit )
        {
            return false;
        }
    }

    //Checking if the first value is an ace
    if( fullHand[0].face != 0 )
    {
        return false;
    }

    //Loop to check if the rest of the 10-King values are there
    for(i=1; i<5; i++)
    {
        if( bottom != fullHand[i].face )
        {
            return false;
        }
        bottom++;
    }

    return true;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that checks if the hand is a straight flush
 *
 *  @param[in] fullHand The array holding the hands suits and face values
 *  
 *  @returns True if the hand is a straight flush and False if the hand isnt
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * cardType fullHand[];
 * bool tf;
 * 
 * tf = isStraightFlush( fullHand );
 * // tf == true if the hand is a straight flush
 * // tf == false if the hand is not a straight flush
    
    
    

    @endverbatim
 ************************************************************************/ 
bool isStraightFlush( cardType fullHand[] )
{
    int i;
    int holdValue = fullHand[0].face;

    //Checking if theyre all the same suit
    for(i=0; i<5; i++)
    {
        if( fullHand[0].suit != fullHand[i].suit )
        {
            return false;
        }
    }
    //Checking if they increment by 1 and returning false if they dont
    for(i=0; i<5; i++)
    {
        if( holdValue != fullHand[i].face )
        {
            return false;
        }
        holdValue++;
    }

    return true;
} 

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that checks if the hand is a Four of a Kind
 * 
 *  @param[in] fullHand The array holding the hands suits and face values
 *  
 *  @returns True if the hand is a four of a kind and False if the hand isnt
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * cardType fullHand[];
 * bool tf;
 * 
 * tf = isFourKind( fullHand );
 * // tf == true if the hand is a four of a kind
 * // tf == false if the hand is not a four of a kind
    
    
    

    @endverbatim
 ************************************************************************/ 
bool isFourKind( cardType fullHand[] )
{
    int sameNumOne = 0; //Hold value to increment how many same face values are in the hand
    int sameNumTwo = 0; //Hold value to increment how many same face values are in the hand
    int holdOne = fullHand[0].face;
    int holdTwo = fullHand[1].face;
    int i;

    //Loop to check each card
    for(i=0; i<5; i++)
    {
        //Checking if the cards face value equals the first cards face value
        if( holdOne == fullHand[i].face )
        {
            sameNumOne = sameNumOne + 1;
        }
        //Checking if the cards face value equalse the second cards face value
        if( holdTwo == fullHand[i].face )
        {
            sameNumTwo = sameNumTwo + 1;
        }
    }

    //If either of the two first cards has 4 or more matches it will return true
    if( 4 < sameNumOne || 4 == sameNumOne )
    {
        return true;
    }
    if( 4 < sameNumTwo || 4 == sameNumTwo )
    {
        return true;
    }
    //If neither of the first two cards has 4 or more it will return false
    return false;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that checks if the hand is a three of a Kind
 * 
 *  @param[in] fullHand The array holding the hands suits and face values
 *  
 *  @returns True if the hand is a three of a kind and False if the hand isnt
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * cardType fullHand[];
 * bool tf;
 * 
 * tf = isThrkind( fullHand );
 * // tf == true if the hand is a three of a kind
 * // tf == false if the hand is not a three of a kind
    
    
    

    @endverbatim
 ************************************************************************/ 
bool isThrKind( cardType fullHand[] )
{
    int i, j;
    int count; //Value counting number of matches


    //Sorts through the array checking each card faces number of matches
    for(i=0; i<5; i++)
    {
        count = 1;
        for(j=i+1; j<5; j++)
        {
            if( fullHand[i].face == fullHand[j].face )
            {
                count = count + 1;
            }
        }
        //If the number of matches is equal or greater than 3 is returns true
        if( count == 3 || 3 < count )
        {
            return true;
        }
    }
    return false;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that checks if the hand is a two of a Kind
 * 
 *  @param[in] fullHand The array holding the hands suits and face values
 *  
 *  @returns True if the hand is a two of a kind and False if the hand isnt
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * cardType fullHand[];
 * bool tf;
 * 
 * tf = isTwoKind( fullHand );
 * // tf == true if the hand is a two of a kind
 * // tf == false if the hand is not a two of a kind
    
    
    

    @endverbatim
 ************************************************************************/ 
bool isTwoKind( cardType fullHand[] )
{
    int i, j;
    int count; //Value counting number of matches
    int fullHandI;
    int fullHandJ;
   
    //Sorts through the array checking each card faces number of matches
    for(i=0; i<5; i++)
    {
        fullHandI = fullHand[i].face;
        count = 1;
        for(j=i+1; j<5; j++)
        {
            fullHandJ = fullHand[j].face;
            if( fullHandI == fullHandJ )
            {
                count = count + 1;
            }
        }
        //If the number of matches is equal or greater than 2 is returns true
        if( count == 2 )
        {
            return true;
        }
    }
    return false;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that checks if the hand is a full house
 * 
 *  @param[in] fullHand The array holding the hands suits and face values
 *  
 *  @returns True if the hand is a full house and False if the hand isnt
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * cardType fullHand[];
 * bool tf;
 * 
 * tf = isFullHouse( fullHand );
 * // tf == true if the hand is a full house
 * // tf == false if the hand is not a full house
    
    
    

    @endverbatim
 ************************************************************************/ 
bool isFullHouse( cardType fullHand[] )
{
    int i, j;
    int count;
    bool condOne = false;
    bool condTwo = false;
    int faceValueI;
    int faceValueJ;
    bool isThrSw = false;
    int jHold[5] = { 0, 0, 0, 0, 0};

    
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            jHold[j] = 0;
        }
        faceValueI = fullHand[i].face;
        if( faceValueI != -1 && !isThrSw )
        {
            count = 1;
            for(j=i+1; j<5; j++)
            {   
                
                faceValueJ = fullHand[j].face;
                if( faceValueI == faceValueJ )
                {
                    count = count + 1;
                    jHold[j] = -1;
                }
                
            }

            if( count == 3 || 3 < count )
            {
                condOne = true;
                fullHand[i].face = -1;
                isThrSw = true;
                for(i=0; i<5; i++)
                {
                    if( jHold[i] == -1 )
                    {
                        fullHand[i].face = -1;
                    }
                }
            }
        }
    }
    for(i=0; i<5; i++)
    {
        jHold[i] = fullHand[i].face;
    }

    for(i=0; i<5; i++)
    {
        faceValueI = fullHand[i].face;
        if( faceValueI != -1 && isThrSw )
        {
            count = 1;
            for(j=i+1; j<5; j++)
            {   
                
                faceValueJ = fullHand[j].face;
                if( faceValueI == faceValueJ )
                {
                    count = count + 1;
                }
                
            }

            if( count == 2 || 2 < count )
            {
                condTwo = true;
            }
        }
    }

    if( condOne && condTwo )
    {
        return true;
    }

    return false;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that checks if the hand is a flush
 * 
 *  @param[in] fullHand The array holding the hands suits and face values
 *  
 *  @returns True if the hand is a flush and False if the hand isnt
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * cardType fullHand[];
 * bool tf;
 * 
 * tf = isFlush( fullHand );
 * // tf == true if the hand is a flush
 * // tf == false if the hand is not a flush
    
    
    

    @endverbatim
 ************************************************************************/ 
bool isFlush( cardType fullHand[] )
{
    int i;

    for(i=0; i<5; i++)
    {
        if( fullHand[0].suit != fullHand[i].suit )
        {
            return false;
        }
    }
    return true;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that checks if the hand is a straight
 * 
 *  @param[in] fullHand The array holding the hands suits and face values
 *  
 *  @returns True if the hand is a straight and False if the hand isnt
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * cardType fullHand[];
 * bool tf;
 * 
 * tf = isStraight( fullHand );
 * // tf == true if the hand is a straight
 * // tf == false if the hand is not a staight
    
    

    @endverbatim
 ************************************************************************/ 
bool isStraight( cardType fullHand[] )
{
    int i, j;
    int count;
    int minFace = 0;
    bool isAce = false;
    bool isCount = true;
    bool foundCount = false;

    for(i=0; i<5; i++)
    {
        if( fullHand[i].face < fullHand[minFace].face )
        {
            minFace = i;
        }
    }

    if( fullHand[minFace].face == 0 )
    {
        isAce = true;
    }
    
    count = fullHand[minFace].face;
    for(j=0; j<5; j++)
    {
        foundCount = false;
        for(i=0; i<5; i++)
        {
            if( fullHand[i].face == count )
            {
                foundCount = true;
            }
        }
        if( foundCount == false)
        {
            j = 5;
        }
        count++;
    }

    if( isAce == true && foundCount == false )
    {
        fullHand[minFace].face = 13;
        for(i=0; i<5; i++)
        {
            if( fullHand[i].face < fullHand[minFace].face )
            {
                minFace = i;
            }
        }
        count = fullHand[minFace].face;
        for(j=0; j<5; j++)
        {
            foundCount = false;
            for(i=0; i<5; i++)
            {
                if( fullHand[i].face == count )
                {
                    foundCount = true;
                }
            }
            if( foundCount == false)
            {
                return false;
            }
            count++;
        }
    }

    if( isAce == false && foundCount == false)
    {
        return false;
    }

    return true;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * A boolian function that checks if the hand is a two pair
 * 
 *  @param[in] fullHand The array holding the hands suits and face values
 *  
 *  @returns True if the hand is a two pair and False if the hand isnt
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * cardType fullHand[];
 * bool tf;
 * 
 * tf = isTwoPair( fullHand );
 * // tf == true if the hand is a two pair
 * // tf == false if the hand is not a two pair
    
    
    

    @endverbatim
 ************************************************************************/ 
bool isTwoPair( cardType fullHand[] )
{
    int i, j;
    int count;
    bool condOne = false;
    bool condTwo = false;
    int faceValueI;
    int faceValueJ;
    int jHold[5] = { 0, 0, 0, 0, 0};


    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            jHold[j] = 0;
        }
        faceValueI = fullHand[i].face;
        if( faceValueI != -1 )
        {
            count = 1;
            for(j=i+1; j<5; j++)
            {   
                
                faceValueJ = fullHand[j].face;
                if( faceValueI == faceValueJ )
                {
                    count = count + 1;
                    jHold[j] = -1;
                }
                
            }
            if( count == 2 )
            {
                condOne = true;
                jHold[i] = -1;
                for(j=0; j<5; j++)
                {
                    if( jHold[j] == -1 )
                    {
                        fullHand[j].face = -1;
                    }
                }
                i = 5;
            }
            if( 2 < count && condOne == false )
            {
                return false;
            }
            if( i == 1 && condOne == false )
            {
                return false;
            }
        }
    }
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            jHold[j] = 0;
        }
        faceValueI = fullHand[i].face;
        if( faceValueI != -1 )
        {
            count = 1;
            for(j=i+1; j<5; j++)
            {   
                
                faceValueJ = fullHand[j].face;
                if( faceValueI == faceValueJ )
                {
                    count = count + 1;
                    jHold[j] = -1;
                }
                
            }

            if( count == 2 )
            {
                condTwo = true;
                fullHand[i].face = -1;
                for(j=0; j<5; j++)
                {
                    if( jHold[j] == -1 )
                    {
                        fullHand[j].face = -1;
                    }
                }
                i = 5;
            }
            if( 1 < count && count != 2 )
            {
                return false;
            }
        }
    }

    if( condOne == true && condTwo == true )
    {
        return true;
    }
    
    return false;
}

/** **********************************************************************
 *  @author Sarahlee Grace Maxwell
 *
 *  @par Description
 * An integer function that returns a predefined constant value assigned
 * to one of 10 hand types 0-9
 * 
 * @param[in] hand The array holding the hands card values
 * @param[in] size the size of the array
  
 *  @returns A value assigned to the type of hand
 *       Royal Flush – 9 
 *       Straight Flush – 8 
 *       4 of a Kind – 7 
 *       Full House – 6 
 *       Flush – 5 
 *       Straight – 4 
 *       3 of a kind – 3 
 *       Two pair – 2 
 *       2 of a kind – 1 
 *       High Card – 0 
 * 
 *  
 *           
 *
 *  @par Example
 *  @verbatim
 * int hand[5] = { 1, 1, 2, 3, 4 };
 * int size = 5;
 * int ans;
 * 
 * ans = classifyHand( hand, size );
 * //ans == 1
    
    
    

    @endverbatim
 ************************************************************************/ 
int classifyHand( int hand[], int size )
{
    int l;
    bool tf = false;
    cardType fullHand[5];
    cardType hold[5];
    sortHand( hand, size );
    assignHand( hand, fullHand );

    for(l=0; l<5; l++)
    {
        hold[l].face = fullHand[l].face;
    }
    for(l=0; l<5; l++)
    {
        hold[l].suit = fullHand[l].suit;
    }
    

    tf = isRoyalFlush( fullHand );
    if( tf == true )
    {
        return royalFlush;
    }
    tf = isStraightFlush( fullHand );
    if( tf == true )
    {
        return straightFlush;
    }
    tf = isFourKind( fullHand );
    if( tf == true )
    {
        return fourKind;
    }
    tf = isFullHouse( fullHand );
    if( tf == true )
    {
        return fullHouse;
    }
    tf = isFlush( fullHand );
    if( tf == true )
    {
        return flushVal;
    }
    tf = isStraight( fullHand );
    if( tf == true )
    {
        return straightVal;
    }
    for(l=0; l<5; l++)
    {
        fullHand[l].face = hold[l].face;
    }
    for(l=0; l<5; l++)
    {
        fullHand[l].suit = hold[l].suit;
    }

    tf = isThrKind( fullHand );
    if( tf == true )
    {
        return threeKind;
    }
    for(l=0; l<5; l++)
    {
        fullHand[l].face = hold[l].face;
    }
    for(l=0; l<5; l++)
    {
        fullHand[l].suit = hold[l].suit;
    }
    
    tf = isTwoPair( fullHand );
    if( tf == true )
    {
        return twoPair;
    }
    for(l=0; l<5; l++)
    {
        fullHand[l].face = hold[l].face;
    }
    for(l=0; l<5; l++)
    {
        fullHand[l].suit = hold[l].suit;
    }
    
    tf = isTwoKind( fullHand );
    if( tf == true )
    {
        return twoKind;
    }
    else
    {
        return highCard;
    }
}