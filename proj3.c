/* Elections come in all shapes and sizes. In the UK, the Prime Minister is officially appointed by the monarch, who generally chooses the leader of the political party that wins the most seats in the House of Commons. The United States uses a multi-step Electoral College process where citizens vote on how each state should allocate Electors who then elect the President.

Perhaps the simplest way to hold an election, though, is via a method commonly known as the “plurality vote” (also known as “first-past-the-post” or “winner take all”). In the plurality vote, every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.
 */
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[] )
{


    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");


    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        
        bool a;
       do {
         string name = get_string("Vote: ");
          a = vote(name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
          }while(a == 0);    
    }
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote

bool vote(string name)
{

   for (int i = 0; i < candidate_count ; i++)
    {
        if(strcmp(name,candidates[i].name) == 0)
        {
                candidates[i].votes++;
                return true;
        }
    }
   return false;
}



// Print the winner (or winners) of the election

void print_winner(void)
{
    int avr = 0;
    int i = 0;

    while(i  < candidate_count)
    {
        if(avr < candidates[i].votes)
        {
            avr = candidates[i].votes;
        }
        i++;
    }

    for (i = 0 ; i  < candidate_count ; i++)
    {
        if( candidates[i].votes == avr && avr !=0)
        {
            printf("%s \n",candidates[i].name);
        }
    }
    return;
}

