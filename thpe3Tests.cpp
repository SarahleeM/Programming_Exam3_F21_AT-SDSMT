#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpe3.h"



const bool RUNCATCH = true;

//write function main here
int main( int argc, char **argv )
{
    Catch::Session session;
    int result;

    //Test case running
    if( RUNCATCH == true )
    {
        result = session.run();
        if( result != 0 )
        {
            cout << "Test cases didnt pass." << endl;
            return result;
        } 
    }

    //Making sure there's the correct number of arguments
    if( argc != 4 )
    {
        usage();
        return 0;
    }

    bool tf; //tf == true/false
    bool isSameNum = false;
    int i, j, l; //Counter value
    int hold;
    int numberHands;
    int hand[5]; //Array holding card values
    int handType;
    int seedValue;
    handVal fullHand;
    handVal fullHandStats;
    ifstream inFile; //Input file ifstream
    ofstream outFile; //Output file ofstream
    string argumentOne = argv[1]; //String tied to argument 1
    string argumentTwo = argv[2]; //String tied to argument 2
    string argumentThr = argv[3]; //String tied to argument 3
   


    //Program Here

    //Checking if the first argv is -f
    if( argumentOne == "-f" )
    {
        //Opening Input file
        tf = openInput( inFile, argumentTwo );
        if( tf == false )
        {
            cout << "Unable to open the file: " << argumentTwo << endl;
            return 0;
        }
        //Opening output file
        tf = openOutput( outFile, argumentThr );
        if( tf == false )
        {
            cout << "Unable to open the file: " << argumentThr << endl;
            return 0;
        }

        i = 0;
        j = 0;
        while( inFile >> hand[i] )
        {
            if( i == 4 )
            {
                j++;
                handType = classifyHand( hand, 5 );

                if( handType == royalFlush )
                {
                    fullHand.royalFlushQuant++;
                }
                if( handType == straightFlush )
                {
                    fullHand.straightFlushQuant++;
                }
                if( handType == fourKind )
                {
                    fullHand.fourKindQuant++;
                }
                if( handType == fullHouse )
                {
                    fullHand.fullHouseQuant++;
                }
                if( handType == flushVal )
                {
                    fullHand.flushQuant++;
                }
                if( handType == straightVal )
                {
                    fullHand.straightQuant++;
                }
                if( handType == threeKind )
                {
                    fullHand.thrKindQuant++;
                }
                if( handType == twoPair )
                {
                    fullHand.twoPairQuant++;
                }
                if( handType == twoKind )
                {
                    fullHand.twoKindQuant++;
                }
                if( handType == highCard )
                {
                    fullHand.highCardQuant++;
                }

                i = -1;
            }
            
            i++;
        }

        fullHandStats.royalFlushQuant = (fullHand.royalFlushQuant / j) * 100;
        fullHandStats.straightFlushQuant = (fullHand.straightFlushQuant / j) * 100;
        fullHandStats.fourKindQuant = (fullHand.fourKindQuant / j) * 100;
        fullHandStats.fullHouseQuant = (fullHand.fullHouseQuant / j) * 100;
        fullHandStats.flushQuant = (fullHand.flushQuant / j) * 100;
        fullHandStats.straightQuant = (fullHand.straightQuant / j) * 100;
        fullHandStats.thrKindQuant = (fullHand.thrKindQuant / j) * 100;
        fullHandStats.twoPairQuant = (fullHand.twoPairQuant / j) * 100;
        fullHandStats.twoKindQuant = (fullHand.twoKindQuant / j) * 100;
        fullHandStats.highCardQuant = (fullHand.highCardQuant / j) * 100;

        fileOutput( outFile, fullHand, fullHandStats, j );
         

        inFile.close();
        outFile.close();

        return 0;
    }

    //Checking if the first argv is -s
    else if( argumentOne == "-s" )
    {
        seedValue = stoi( argv[2] );
        numberHands = stoi( argv[3] );
        static default_random_engine engine( seedValue );
        uniform_int_distribution<int> deck(0, 51);


        for(i=0; i<numberHands; i++)
        {
            for(j=0; j<5; j++)
            {
                hand[j] = -1;
            }
            //Getting a random hand
            for(j=0; j<5; j++)
            {
                hold = deck( engine );
                for(l=0; l<5; l++)
                {
                    if( hold == hand[l] )
                    {
                        isSameNum = true;
                    }
                }
                if( isSameNum == false )
                {
                    hand[j] = hold;
                }
                if( isSameNum == true )
                {
                    isSameNum = false;
                    j = j-1;
                }
            }

            //Classifying the hand
            handType = classifyHand( hand, 5 );

            if( handType == royalFlush )
            {
                fullHand.royalFlushQuant++;
            }
            if( handType == straightFlush )
            {
                fullHand.straightFlushQuant++;
            }
            if( handType == fourKind )
            {
                fullHand.fourKindQuant++;
            }
            if( handType == fullHouse )
            {
                fullHand.fullHouseQuant++;
            }
            if( handType == flushVal )
            {
                fullHand.flushQuant++;
            }
            if( handType == straightVal )
            {
                fullHand.straightQuant++;
            }
            if( handType == threeKind )
            {
                fullHand.thrKindQuant++;
            }
            if( handType == twoPair )
            {
                fullHand.twoPairQuant++;
            }
            if( handType == twoKind )
            {
                fullHand.twoKindQuant++;
            }
            if( handType == highCard )
            {
                fullHand.highCardQuant++;
            }
        }

        fullHandStats.royalFlushQuant = (fullHand.royalFlushQuant / numberHands) * 100;
        fullHandStats.straightFlushQuant = (fullHand.straightFlushQuant / numberHands) * 100;
        fullHandStats.fourKindQuant = (fullHand.fourKindQuant / numberHands) * 100;
        fullHandStats.fullHouseQuant = (fullHand.fullHouseQuant / numberHands) * 100;
        fullHandStats.flushQuant = (fullHand.flushQuant / numberHands) * 100;
        fullHandStats.straightQuant = (fullHand.straightQuant / numberHands) * 100;
        fullHandStats.thrKindQuant = (fullHand.thrKindQuant / numberHands) * 100;
        fullHandStats.twoPairQuant = (fullHand.twoPairQuant / numberHands) * 100;
        fullHandStats.twoKindQuant = (fullHand.twoKindQuant / numberHands) * 100;
        fullHandStats.highCardQuant = (fullHand.highCardQuant / numberHands) * 100;

        outputMessage( fullHand, fullHandStats, numberHands );

       return 0; 
        
    }

    //If argv[1] isnt -f or -s it sends a usage statement and stops
    else
    {
        cout << "Invalid Option" << endl;
        return 0;
    } 

    
    return 0;
}

TEST_CASE( "openInput - testing if the input file opens" )
{
    string data = "dataTest.txt";
    ifstream datafile;
    bool ans;

    ans = openInput( datafile, data );
    CHECK( ans == true );

    datafile.close();
}

TEST_CASE( "openInput - testing if the input file fails to open" )
{
    string data = "dataTests.txt";
    ifstream datafile;
    bool ans;

    ans = openInput( datafile, data );
    CHECK( ans == false );

}

TEST_CASE( "openOutput - testing if it opens the output files" )
{
    string output = "primeTest.txt";
    ofstream outfile; 
    bool ans;

    ans = openOutput( outfile, output );
    CHECK( ans == true );

    outfile.close();
}

TEST_CASE( "openOutput - testing if it fails to open output" )
{
    string output = "z:\\primeTests.txt";
    ofstream outfile; 
    bool ans;

    ans = openOutput( outfile, output );
    CHECK( ans == false );
}

TEST_CASE( "assignHand - testing an ace of clubs" )
{
    cardType hand[5];
    int card[5] = {0, 0, 0, 0, 0};

    assignHand( card, hand );
    CHECK( hand[0].face == 0 ); //1
    CHECK( hand[0].suit == 0 ); //Clubs
}

TEST_CASE( "assignHand - testing a couple different" )
{
    cardType hand[5];
    int card[5] = { 30, 40, 30, 30, 30 };

    assignHand( card, hand );
    CHECK( hand[0].face == 4 ); //5
    CHECK( hand[0].suit == 2 ); //Hearts
    CHECK( hand[1].face == 1 ); //2
    CHECK( hand[1].suit == 3 ); //Spades
}

TEST_CASE( "assignHand - testing king of spades" )
{
    cardType hand[5];
    int card[5] = { 51, 51, 51, 51, 51 };

    assignHand( card, hand );
    CHECK( hand[0].face == 12 ); //King
    CHECK( hand[0].suit == 3 ); //Spades
}

TEST_CASE( "sortHand - testing a simple switch" )
{
    int i;
    int size = 5;
    int hand[5] = { 0, 3, 2, 1, 4 };
    sortHand( hand, size );

    for(i=0; i<size; i++)
    {
       CHECK( hand[i] == i ); 
    }
}

TEST_CASE( "sortHand - testing a harder switch" )
{
    int i;
    int size = 5;
    int hand[5] = { 22, 51, 10, 11, 45  };
    sortHand( hand, size );

    CHECK( hand[0] == 10 );
    CHECK( hand[1] == 11 );
    CHECK( hand[2] == 22 );
    CHECK( hand[3] == 45 );
    CHECK( hand[4] == 51 );
}

TEST_CASE( "isRoyalFlush - testing a royalFlush" )
{
    int hand[5] = { 13, 22, 23, 24, 25 };
    bool tf;
    cardType fullHand[5];
    
    assignHand( hand, fullHand );
    tf = isRoyalFlush( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isRoyalFlush - testing a false read" )
{
    int hand[5] = { 13, 22, 23, 24, 30 };
    bool tf;
    cardType fullHand[5];
    
    assignHand( hand, fullHand );
    tf = isRoyalFlush( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isRoyalFlush - testing another true" )
{
    int hand[5] = { 26, 35, 36, 37, 38 };
    bool tf;
    cardType fullHand[5];
    
    assignHand( hand, fullHand );
    tf = isRoyalFlush( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isRoyalFlush - testing a false because no ace" )
{
    int hand[5] = { 27, 35, 36, 37, 38 };
    bool tf;
    cardType fullHand[5];
    
    assignHand( hand, fullHand );
    tf = isRoyalFlush( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isRoyalFlush - testing a false because wrong suit" )
{
    int hand[5] = { 0, 35, 36, 37, 38 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );
    tf = isRoyalFlush( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isStraightFlush - testign a true" )
{
    int hand[5] = { 34, 35, 36, 37, 38 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );
    
    tf = isStraightFlush( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isStraightFlush - ace-5 in clubs" )
{
    int hand[5] = { 0, 1, 2, 3, 4 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );
    
    tf = isStraightFlush( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isStraightFlush - testing a false because of non same suit" )
{
    int hand[5] = { 24, 25, 26, 27, 28 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );
    
    tf = isStraightFlush( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isFourKind - testing 4 aces")
{
    int hand[5] = { 0, 13, 26, 39, 51 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFourKind( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isFourKind - testing no matches")
{
    int hand[5] = { 0, 1, 2, 3, 4 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFourKind( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isFourKind - testing the no match in the second spot")
{
    int hand[5] = { 1, 10, 14, 27, 40 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFourKind( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isFourKind - testing the no match in the first spot")
{
    int hand[5] = { 10, 1, 14, 27, 40 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFourKind( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isFourKind - testing 3 mathces w/ missing in 1, 2")
{
    int hand[5] = { 1, 10, 11, 27, 40 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFourKind( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isFourKind - testing 3 mathces w/ missing in 0, 1")
{
    int hand[5] = { 10, 11, 1, 27, 40 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFourKind( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isThrKind - testing 3 values of equal face")
{
    int hand[5] = { 0, 13, 26, 27, 28};
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isThrKind( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isThrKind - testing 3 values of equal face at the end")
{
    int hand[5] = { 0, 1, 3, 16, 29};
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isThrKind( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isThrKind - testing only 2 same values")
{
    int hand[5] = { 0, 1, 2, 16, 29};
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isThrKind( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isThrKind - testing only 3 same values mixed")
{
    int hand[5] = { 16, 1, 3, 5, 29};
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isThrKind( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isTwoKind - testing a true with matches at begining" )
{
    int hand[5] = { 0, 13, 14, 15, 16 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoKind( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isTwoKind - testing a true with matches at begining and end" )
{
    int hand[5] = { 0, 1, 14, 15, 13 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoKind( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isTwoKind - testing a true with matches mixed" )
{
    int hand[5] = { 12, 1, 51, 15, 13 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoKind( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isTwoKind - testing no matches" )
{
    int hand[5] = { 1, 2, 3, 4, 5 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoKind( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isTwoKind - testing a file false" )
{
    int hand[5] = { 8, 26, 38, 45, 46 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoKind( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isTwoKind - testing file high card" )
{
    int hand[5] = { 0, 1, 16, 17, 34 };
   cardType fullHand[5];
    bool ans;

    assignHand( hand, fullHand );
    ans = isTwoKind( fullHand );
    CHECK( ans == false );
}

TEST_CASE( "isFullHouse - testing a simple true" )
{
    int hand[5] = { 0, 13, 26, 1, 14 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFullHouse( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isFullHouse - testing a mixed true" )
{
    int hand[5] = { 0, 1, 26, 13, 14 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFullHouse( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isFullHouse - testing a true with 2 match in front" )
{
    int hand[5] = { 1, 14, 0, 13, 26 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFullHouse( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isFullHouse - testing no matches" )
{
    int hand[5] = { 1, 2, 3, 4, 5 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFullHouse( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isFullHouse - testing only the three matches but no two's match" )
{
    int hand[5] = { 0, 13, 26, 4, 5 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFullHouse( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isFullHouse - testing only the three matches but no two's match at end" )
{
    int hand[5] = { 0, 14, 15, 28, 41 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFullHouse( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isFullHouse - testing only the two's match" )
{
    int hand[5] = { 0, 13, 3, 4, 5 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFullHouse( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isFullHouse - testing two sets of two" )
{
    int hand[5] = { 0, 13, 14, 27, 41 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFullHouse( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isFlush - testing all same suit" )
{
    int hand[5] = { 0, 1, 2, 3, 4 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFlush( fullHand );
    CHECK( tf == true );
} 

TEST_CASE( "isFlush - testing not all same suit" )
{
    int hand[5] = { 0, 1, 2, 3, 14 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isFlush( fullHand );
    CHECK( tf == false );
} 

TEST_CASE( "isStraight - testing true without ace" )
{
    int hand[5] = { 1, 15, 29, 31, 43 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isStraight( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isStraight - testing true with ace being 13" )
{
    int hand[5] = { 0, 9, 10, 11, 12 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isStraight( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isStraight - testing false" )
{
    int hand[5] = { 0, 5, 6, 7, 20 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isStraight( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isStraight - testing false almost true" )
{
    int hand[5] = { 0, 1, 2, 3, 5 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isStraight( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isStraight - testing false missing last" )
{
    int hand[5] = { 0, 6, 7, 8, 11 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isStraight( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isTwoPair - testing a true in order")
{
    int hand[5] = { 0, 13, 27, 40, 41 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoPair( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isTwoPair - testing a false because 3")
{
    int hand[5] = { 0, 13, 26, 27, 40 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoPair( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isTwoPair - testing a true with first being mismatch")
{
    int hand[5] = { 0, 14, 27, 28, 41 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoPair( fullHand );
    CHECK( tf == true );
}

TEST_CASE( "isTwoPair - testing a false with one match")
{
    int hand[5] = { 0, 13, 14, 15, 16 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoPair( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isTwoPair - testing a false because 3 at end")
{
    int hand[5] = { 0, 13, 15, 28, 41 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoPair( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "isTwoPair - testing a false because no second match" )
{
    int hand[5] = { 0, 13, 15, 16, 17 };
    bool tf;
    cardType fullHand[5];

    assignHand( hand, fullHand );

    tf = isTwoPair( fullHand );
    CHECK( tf == false );
}

TEST_CASE( "classifyHand - testing royal flush" )
{
    int hand[5] = { 13, 22, 23, 24, 25 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 9 );
}

TEST_CASE( "classifyHand - testing straight flush" )
{
    int hand[5] = { 44, 45, 46, 47, 48 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 8 );
}

TEST_CASE( "classifyHand - testing 4 kind" )
{
    int hand[5] = { 7, 20, 33, 46, 47 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 7 );
}

TEST_CASE( "classifyHand - testing full house" )
{
    int hand[5] = { 3, 42, 9, 35, 22 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 6 );
}

TEST_CASE( "classifyHand - testing flush" )
{
    int hand[5] = { 27, 30, 33, 35, 38 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 5 );
}

TEST_CASE( "classifyHand - testing stright" )
{
    int hand[5] = { 0, 14, 15, 29, 43 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 4 );
}

TEST_CASE( "classifyHand - testing 3 kind" )
{
    int hand[5] = { 0, 13, 26, 7, 35 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 3 );
}

TEST_CASE( "classifyHand - testing two pair" )
{
    int hand[5] = { 15, 41, 7, 20, 51 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 2 );
}

TEST_CASE( "classifyHand - testing 2 Kind" )
{
    int hand[5] = { 9, 49, 32, 41, 15 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 1 );
}

TEST_CASE( "classifyHand - testing high card" )
{
    int hand[5] = { 0, 1, 16, 17, 34 };
    int size = 5;
    int ans;

    ans = classifyHand( hand, size );
    CHECK( ans == 0 );
}
