/* * * * * * * * * * * * *
 * Social Credit Source  *
 *                       *
 * Extremely bad but     *
 *                       *
 * * * * * * * * * * * * */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* --Definition-- */
#define QUESTIONAMT 5
#define BUFVAL 50
#define FNAME SOCIALCREDIT.txt

/* --Question Worth-- */
#define QUESTVALUE1 15
#define QUESTVALUE2 30
#define QUESTVALUE3 50
#define QUESTVALUE4 65

/* --Questions-- */

typedef struct
{
    const char* string;
    int32_t questVal;

    int32_t corrOpt;
} Question;

/* Questions list */
Question questList[] =
{
    { "Is China:\n Communist [1]\n Capatalist [2]\n", QUESTVALUE1, 1 },
    { "Which is better:\n U.S [1]\n China [2]\n", QUESTVALUE2,  2 },
    { "What Happen on June 4th, 1989:\n Tiananmen Square Massacre [1]\n Nothing [2]\n", QUESTVALUE3, 2 },
    { "How many kids should a family have:\n 69,420 [1]\n 4 [2]\n 1 [3]\n", QUESTVALUE3, 3 },
    { "What is Taiwan:\n Random word [1], A country [2]\n", QUESTVALUE4, 1}
};


/* --Strings-- */



/* --Variables-- */
int32_t socialCredit = 0;
int32_t currQuestion = 0;

/* --Functions-- */

int32_t getInput (void)
{
    char buf[BUFVAL];
    fgets ( buf, BUFVAL, stdin );

    return ( int32_t ) atoi ( buf );
}

void tstQuestion (void)
{
    int32_t input;

    while ( currQuestion != QUESTIONAMT )
    {
        printf ( "\nQuestions %d\n\n%s \n", currQuestion, questList[currQuestion].string );

        input = getInput ();

        if ( questList[currQuestion].corrOpt == input )
            socialCredit += questList[currQuestion].questVal;
        else
            socialCredit -= questList[currQuestion].questVal;

        printf ( "Social Credit : %d\n", socialCredit );
        currQuestion++;
    }

    printf ( "\n\n Social credit : %d", socialCredit );
}


/* --[[ MAIN ]]-- */

/* note this is a tempate for now */

int main (void)
{
    tstQuestion ();

    if ( socialCredit <= 0 )
        printf ( "\nExecution\n\n" );
    else if ( socialCredit <= 100 && socialCredit > 0 )
        printf ( "\nMines\n\n" );
    else
        printf ( "Free rice\n\n" );


    return 0;
}
