#define _CRT_SECURE_NO_DEPRECATE
// C program to implement
// the above approach
#include <stdio.h>
#include <string.h>
//#include <gtk.h> 




#define TEAM_SIZE 50
#define TEAM_AMT 14
#define FILE_NAME_LENGTH 30
#define CURRENT_YEAR 2022


/**
* Batter struct
* year the stats are from
* position
* name
* age
* and all other baseball batter stats
*/
typedef struct {
	int year;
	char position[5];
	char name[50];
	int age;
	int games;
	int plateAppearances;
	int atBats;
	int runs;
	int hits;
	int doubles;
	int triples;
	int homeRuns;
	int runsBattedIn;
	int stolenBases;
	int caughtStealing;
	int baseOnBalls;
	int strikeouts;
	double battingAverage;
	double onBase;
	double slugging;
	double onBasePlusSlugging;
	int onBasePlusSluggingPlus;
	int totalBases;
	int doublePlaysGroundedInto;
	int hitByPitch;
	int sacrificeBunts;
	int sacrificeFlies;
	int intentionalBaseOnBalls;

} Batter;


/**
* @Params
* Batter the batter to check
*
* @return boolean if the player struct is a valid batter
*
* Checks if the player is a valid batter
*/
_Bool isBatter(Batter batter) {
	return (batter.year >= CURRENT_YEAR - TEAM_AMT && batter.year <= CURRENT_YEAR);
}


/**
* @Params
* Batter The batter to check if the same as batter2
* Batter The batter to check if the same as batter1
* 
* @return boolean if players are the same
* 
* Checks if the two players are the same
*/
_Bool isSame(Batter batter1, Batter batter2) {
	//printf("Compaing: %s::%i==%s::%i\n", (batter1).name, (batter1).year, (batter2).name, (batter2).year);
	return (batter1.year == batter2.year) && strcmp(batter1.name, batter2.name) == 0;
}


/**
* @Params
* Batter The batter to see if it already exists in the selection
* Batter[] the selection to check against
* Int the size of the array
* 
* @return boolean if player is already in selection
* 
* Checks if the given player already exists in the current selection
*/
_Bool alreadyInSelection(Batter batter, Batter selection[], int size) {
	for (int count = 0; count < size; count++) {
		if (isSame(batter, selection[count]))
		{
			//printf("\nIs same\n");
			return 1 == 1;
		}
	}
	return 1 == 0;
}


/**
* @Params
* Batter the batter to print
* int The rank of the batter
*
* Prints the batter with formating
*/
void print(Batter batter, int rank) {
	if (!isBatter(batter)) {
		printf("Skipping Dead Row\n");
		return;
	}
	printf("%4d | ", rank);
	printf(
		"%d | %-2s | %-20s | %-4d | %-4d | %-4d | %-4d | %-4d | %-4d | %-4d | %-4d | %-4d | %-4d | %-4d | %-4d | %-4d | %-4d | %-.3f | %-.3f | %-.3f | %-.3f | %-5d | %-4d | %-3d | %-3d | %-4d | %-4d | %-4d\n",
		batter.year,
		batter.position,
		batter.name,
		batter.age,
		batter.games,
		batter.plateAppearances,
		batter.atBats,
		batter.runs,
		batter.hits,
		batter.doubles,
		batter.triples,
		batter.homeRuns,
		batter.runsBattedIn,
		batter.stolenBases,
		batter.caughtStealing,
		batter.baseOnBalls,
		batter.strikeouts,
		batter.battingAverage,
		batter.onBase,
		batter.slugging,
		batter.onBasePlusSlugging,
		batter.onBasePlusSluggingPlus,
		batter.totalBases,
		batter.doublePlaysGroundedInto,
		batter.hitByPitch,
		batter.sacrificeBunts,
		batter.sacrificeFlies,
		batter.intentionalBaseOnBalls
	);
}


/**
* @Params
* Batter[] the array of batters to be printed
* int size of the array
*
* Optional, Returns the actual size of array
*
* Prints the Batter[] with the header title
*/
int printTeam(Batter batters[], unsigned long long size) {
	int count = 0;
	printf("rank | year | ps | name\t\t\t| age  | game | PA   | AB   | runs | hts  | DBLS | TPLS | HR   | RBIs | SB   | CS   | ");
	printf("Wlks | SO   | BA    | OBP   | Slug  | OBPS  | OBPS+ | TB   | DPG | HBP | SacB | SacF | IBB\n");
	for (int i = 0; i < size; i++) {
		if (isBatter(batters[i]))
		{
			print(batters[i], i + 1);
			count++;
		}
	}
	printf("* - bats left-handed, # - bats both, else - bats right, ? - unknown; OPS_lg for OPS+ does not include pitchers.\n");
	return count;
}


/**
* @Params
* Batter* player to swap
* Batter* player to swap
*
* Swaps 2 variables, used in the selection sort for finding the best
* players for stats
*/
void swap(Batter* xp, Batter* yp)
{
	Batter temp = *xp;
	*xp = *yp;
	*yp = temp;
}


/**
* @Params
* Batter* batter to add to stack
* Batter* array, the selection to add the batter to
* 
* 
* 
* adds player to array after making sure that player is not already in the array
*/
void addBatter(Batter *batter, Batter* batters[], int index) {
	//*batters[index] = batter;
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the batting average
*/
void bestBattingAverage(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the best batting average\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].battingAverage > batters[min_idx].battingAverage)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most games played
*/
void mostGamesPlayed(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most games played\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].games > batters[min_idx].games)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the oldest player
*/
void oldestPlayer(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the oldest player\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].age > batters[min_idx].age)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most plate apperances
*/
void mostPlateApperances(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most plate apperances\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].plateAppearances > batters[min_idx].plateAppearances)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most at bats
*/
void mostAtBats(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most at bats\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].atBats > batters[min_idx].atBats)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most runs
*/
void mostRuns(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most runs\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].runs > batters[min_idx].runs)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most hits
*/
void mostHits(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most hits\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].hits > batters[min_idx].hits)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most doubles
*/
void mostDoubles(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most doubles\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].doubles > batters[min_idx].doubles)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most triples
*/
void mostTriples(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most triples\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].triples > batters[min_idx].triples)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most home runs
*/
void mostHomeRuns(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most home runs\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].homeRuns > batters[min_idx].homeRuns)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most RBIs
*/
void mostRBIs(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most RBIs\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].runsBattedIn > batters[min_idx].runsBattedIn)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most stolen bases
*/
void mostStolenBases(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most stolen bases\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].stolenBases > batters[min_idx].stolenBases)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most caught stealing
*/
void mostCaughtStealing(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most times caught stealing\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].caughtStealing > batters[min_idx].caughtStealing)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most walks
*/
void mostWalks(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most walks\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].baseOnBalls > batters[min_idx].baseOnBalls)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most strikeouts
*/
void mostStrikeouts(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most strikeouts\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].strikeouts > batters[min_idx].strikeouts)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the best OnBasePercentage
*/
void bestOnBasePercentage(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the best OBP\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].onBase > batters[min_idx].onBase)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the best Slugging
*/
void bestSlugging(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the best slugging percentage\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].slugging > batters[min_idx].slugging)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the best OnBasePlusSlugging
*/
void bestOnBasePlusSlugging(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the best OBPS\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].onBasePlusSlugging > batters[min_idx].onBasePlusSlugging)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the best OBPS+
*/
void bestOnBasePlusSluggingPlus(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the Best OBPS+ \n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].onBasePlusSluggingPlus > batters[min_idx].onBasePlusSluggingPlus)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most total bases
*/
void mostTotalBases(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most total bases\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].totalBases > batters[min_idx].totalBases)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most DoublePlaysGroundedInto
*/
void mostDoublePlaysGroundedInto(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most double plays grounded into\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].doublePlaysGroundedInto > batters[min_idx].doublePlaysGroundedInto)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most hit by pitch
*/
void mostHitByPitch(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most hit by pitches\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].hitByPitch > batters[min_idx].hitByPitch)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most sac bunts
*/
void mostSacBunts(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most sac bunts\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].sacrificeBunts > batters[min_idx].sacrificeBunts)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most sac flies
*/
void mostSacFlies(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most sac flys\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].sacrificeFlies > batters[min_idx].sacrificeFlies)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}


/**
* @Params
* Batter* batter array to sort
* int size of the array
*
* Sort the Batter[] by the most Intentional Walks
*/
void mostIntentionalWalks(Batter* batters, int size) {
	printf("\n\n\n\n\nSorting by the most intentional walks\n");
	//printf("Input:\n");
	//printTeam(batters, size);

	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (batters[j].intentionalBaseOnBalls > batters[min_idx].intentionalBaseOnBalls)
				min_idx = j;

		if (min_idx != i)
			swap(&batters[min_idx], &batters[i]); // Swap the found minimum element with the first element
	}
	//printf("Output:\n");
	printTeam(batters, size);
}



/**
* Driver
*/
int main()
{
	printf("Ricky's Yankees Batter analysis program\n\n\n");

	FILE* fp;

	Batter batters[TEAM_AMT][TEAM_SIZE];
	char fileNames[TEAM_AMT][FILE_NAME_LENGTH] = {
		{"2022-Yankees-Batting.txt"},
		{"2021-Yankees-Batting.txt"},
		{"2020-Yankees-Batting.txt"},
		{"2019-Yankees-Batting.txt"},
		{"2018-Yankees-Batting.txt"},
		{"2017-Yankees-Batting.txt"},
		{"2016-Yankees-Batting.txt"},
		{"2015-Yankees-Batting.txt"},
		{"2014-Yankees-Batting.txt"},
		{"2013-Yankees-Batting.txt"},
		{"2012-Yankees-Batting.txt"},
		{"2011-Yankees-Batting.txt"},
		{"2010-Yankees-Batting.txt"},
		{"2009-Yankees-Batting.txt"}
	};
	char buffer[50];
	int rank;

	for (int i = 0; i < TEAM_AMT; i++) {

		fp = fopen(fileNames[i], "r");

		for (int j = 0; j < TEAM_SIZE; j++) {
			if (feof(fp)) // reached end of file
				break;

			batters[i][j].year = CURRENT_YEAR - i;

			fscanf(fp, "%d,%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%d,%d,%d,%d,%d,%d,%d,%s",
				&rank, batters[i][j].position, batters[i][j].name, &batters[i][j].age, &batters[i][j].games, &batters[i][j].plateAppearances,
				&batters[i][j].atBats, &batters[i][j].runs, &batters[i][j].hits, &batters[i][j].doubles, &batters[i][j].triples, &batters[i][j].homeRuns, &batters[i][j].runsBattedIn,
				&batters[i][j].stolenBases, &batters[i][j].caughtStealing, &batters[i][j].baseOnBalls,
				&batters[i][j].strikeouts, &batters[i][j].battingAverage, &batters[i][j].onBase, &batters[i][j].slugging,
				&batters[i][j].onBasePlusSlugging, &batters[i][j].onBasePlusSluggingPlus, &batters[i][j].totalBases, &batters[i][j].doublePlaysGroundedInto,
				&batters[i][j].hitByPitch, &batters[i][j].sacrificeBunts, &batters[i][j].sacrificeFlies, &batters[i][j].intentionalBaseOnBalls, buffer);

			//printf("batters[%d][%d]  <--  %d %s\n", i, j, batters[i][j].year, batters[i][j].name);
		}
		fclose(fp);
	}

	//printf("\n\nStoring Done\n\n");

	Batter allBatters[TEAM_AMT * TEAM_SIZE];
	Batter allBattersCopy[TEAM_AMT * TEAM_SIZE];

	int count = 0;
	for (int i = 0; i < TEAM_AMT; i++) {
		for (int j = 0; j < TEAM_SIZE; j++) {
			if (isBatter(batters[i][j]))
			{
				allBatters[count] = batters[i][j];
				allBattersCopy[count] = batters[i][j];
				count++;
			}
		}
	}

	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	int yearSelectionToView = -10;
	int newSelectionChoice = 1;


	while (yearSelectionToView != -2) { // exit program when user wants to exit
		Batter selectedBatters[TEAM_AMT * TEAM_SIZE];
		count = 0;

		newSelectionChoice = 1;

		while (newSelectionChoice == 1 || newSelectionChoice == 2) { // user wants to continue to add to the slection after compairing batters
			// 1 = add players, 2 = remove players

			while(newSelectionChoice == 2) { // user wants to keep removing players from the selection
					int indexToRemove = -10;

					while (indexToRemove < -1 || indexToRemove > count) { // ask which player to remove from the selection
						printf("Players in your selection\n");
						printTeam(selectedBatters, count);
						printf("Which player would you like to remove?\n0 - Stop Removing Players\nEnter: ");
						scanf("%i", &indexToRemove);
						indexToRemove -= 1;
					}
					if (indexToRemove > -1) { // removing a player from the selection
						selectedBatters[indexToRemove] = (Batter){ 0, "","",13, };
						swap(&selectedBatters[indexToRemove], &selectedBatters[count-1]);
						count -= 1;
					}
					else {
						// user wants to stop removing players
						newSelectionChoice = 1;
					}
				
			}

			int choiceForSorting = 0;
			while (yearSelectionToView != -1 && yearSelectionToView != -2) { // Repeat while user wants to select more players to add to selection


				do { // what year would you like to view
					printf("\n\nWhat year would you like add players from?\n");
					for (int j = 0; j < TEAM_AMT; j++) {
						printf("%i\n", CURRENT_YEAR - j);
					}
					printf("0 - All\n-1 - Done\n-2 - Exit\nEnter: ");
					scanf("%i", &yearSelectionToView);
				} while ((yearSelectionToView <= CURRENT_YEAR - TEAM_AMT && yearSelectionToView != 0 && yearSelectionToView != -1 && yearSelectionToView != -2) || yearSelectionToView > CURRENT_YEAR);
				if (yearSelectionToView == -2) { // wants to exit
					return 0;
				}

				int indexPlayerSelection = -1;

				if (yearSelectionToView == 0) { // View all players

					int size = printTeam(allBatters, TEAM_AMT * TEAM_SIZE);
					do {
						printf("\n0 - All\nEnter: ");
						scanf("%d", &indexPlayerSelection);
					} while (indexPlayerSelection < 0 || indexPlayerSelection >= size); // Data validation

					if (indexPlayerSelection == 0) { // selects all players across all years
						for (int i = 0; i < size; i++) { // copy players from array and paste into other array

							// if the list started as empty is will run, if not empty it will check to see if the batter already exists
							if (i == count || ! alreadyInSelection(allBatters[i], selectedBatters, count)) {
								selectedBatters[count] = allBatters[i];
								count++;
							}
						}
					}
					else { // wants specific player from the all selection

						// if the list started as empty is will run, if not empty it will check to see if the batter already exists
						if (count == 0 || !alreadyInSelection(allBatters[indexPlayerSelection-1], selectedBatters, count)) {
							selectedBatters[count] = allBatters[indexPlayerSelection - 1];
							count++;
						}
					}
				}
				else if (yearSelectionToView != -1) { // View specific year
					int indexYearSelection = CURRENT_YEAR - yearSelectionToView;
					int size = printTeam(batters[indexYearSelection], TEAM_SIZE);

					do {
						printf("\n0 - All\nEnter: ");
						scanf("%d", &indexPlayerSelection);
					} while (indexPlayerSelection < 0 || indexPlayerSelection >= size); // Data validation for 

					if (indexPlayerSelection == 0) { // wants all players from a year
						for (int i = 0; i < size; i++) { // copy players from array and paste into other array

							// if the list started as empty is will run, if not empty it will check to see if the batter already exists
							if (i == count || !alreadyInSelection(batters[indexYearSelection][i], selectedBatters, count)) {
								selectedBatters[count] = batters[indexYearSelection][i];
								count++;
							}
						}
					}
					else { // wants specific player from the year

						// if the list started as empty is will run, if not empty it will check to see if the batter already exists
						if (count == 0 || !alreadyInSelection(batters[indexYearSelection][indexPlayerSelection - 1], selectedBatters, count)) {
							selectedBatters[count] = batters[indexYearSelection][indexPlayerSelection - 1];
							count++;
						}
					}
				}
				else {
					// done adding players
				}

				//printf("Selection: %d\tCount: %i\n", indexPlayerSelection, count);
			}

			printf("\n\n\n\nPlayers in your selection:\n");
			printTeam(selectedBatters, count);

			choiceForSorting = 0;
			while (choiceForSorting > -1)
			{
				choiceForSorting = -2;

				while (choiceForSorting < -1 || choiceForSorting > 24)
				{
					printf("How would you like to sort this selection? \n");
					printf("0 - Modify Selection/Exit\n1 - age\t\t\t\t2 - games\t\t\t3 - PlateAppearances\t\t4 - At Bats\t\t\t");
					printf("5 - runs\n6 - hits\t\t\t7 - doubles\t\t\t8 - triples\t\t\t");
					printf("9 - homeruns\t\t\t10 - RBIs\n11 - stolen bases\t\t12 - caught stealing\t\t");
					printf("13 - walks\t\t\t14 - strikeouts\t\t\t15 - batting average\n16 - OBP\t\t\t");
					printf("17 - Slugging\t\t\t18 - OBPS\t\t\t19 - OBPS+\t\t\t20 - Total Bases\n");
					printf("21 - DoublePlaysGroundedInto\t22 - HBP\t\t\t23 - Sac Bunts\t\t\t24 - Sac Flys\t\t\t");
					printf("25 - Intentional Walk\n\nEnter: ");
					scanf("%i", &choiceForSorting);
					choiceForSorting -= 1;
				}

				printf("\n\nOutput from your selection of %i\n", choiceForSorting + 1);
				switch (choiceForSorting) {
				case -1:
					newSelectionChoice = -10;
					yearSelectionToView = -10;
					break;
				case 0:
					oldestPlayer(selectedBatters, count);
					break;
				case 1:
					mostGamesPlayed(selectedBatters, count);
					break;
				case 2:
					mostPlateApperances(selectedBatters, count);
					break;
				case 3:
					mostAtBats(selectedBatters, count);
					break;
				case 4:
					mostRuns(selectedBatters, count);
					break;
				case 5:
					mostHits(selectedBatters, count);
					break;
				case 6:
					mostDoubles(selectedBatters, count);
					break;
				case 7:
					mostTriples(selectedBatters, count);
					break;
				case 8:
					mostHomeRuns(selectedBatters, count);
					break;
				case 9:
					mostRBIs(selectedBatters, count);
					break;
				case 10:
					mostStolenBases(selectedBatters, count);
					break;
				case 11:
					mostCaughtStealing(selectedBatters, count);
					break;
				case 12:
					mostWalks(selectedBatters, count);
					break;
				case 13:
					mostStrikeouts(selectedBatters, count);
					break;
				case 14:
					bestBattingAverage(selectedBatters, count);
					break;
				case 15:
					bestOnBasePercentage(selectedBatters, count);
					break;
				case 16:
					bestSlugging(selectedBatters, count);
					break;
				case 17:
					bestOnBasePlusSlugging(selectedBatters, count);
					break;
				case 18:
					bestOnBasePlusSluggingPlus(selectedBatters, count);
					break;
				case 19:
					mostTotalBases(selectedBatters, count);
					break;
				case 20:
					mostDoublePlaysGroundedInto(selectedBatters, count);
					break;
				case 21:
					mostHitByPitch(selectedBatters, count);
					break;
				case 22:
					mostSacBunts(selectedBatters, count);
					break;
				case 23:
					mostSacFlies(selectedBatters, count);
					break;
				case 24:
					mostIntentionalWalks(selectedBatters, count);
					break;
				default:
					printf("Switch statement default error #50101");
				}
			}
			newSelectionChoice = -10;
			while (newSelectionChoice < -1 || newSelectionChoice > 2) {
				printf("What would you like to do to you selection?\n-1 - Exit\n0 - New Selection\n1 - Add To Selection\n2 - Remove From Selection\nEnter: ");
				scanf("%i", &newSelectionChoice);
			}
			if (newSelectionChoice == -1) { // User wants to exit
				return 0; 
			}
		}
	}
	return(0);

}
