#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

double calculateProbability(int n, int r)
{
    double result = (double)factorial(n) / (factorial(r) * factorial(n - r));
    return result;
}

int main()
{
    int total_cards = 52;
    int cards_in_hand = 5;

    double total_combinations = calculateProbability(total_cards, cards_in_hand);

    // Calculate and print approximate probabilities for some basic poker hands
    double probability_high_card = (calculateProbability(13, cards_in_hand) * calculateProbability(4, cards_in_hand)) / total_combinations;
    double probability_one_pair = (calculateProbability(13, 1) * calculateProbability(4, 2) * calculateProbability(12, 3) * calculateProbability(4, 1) * calculateProbability(4, 1)) / total_combinations;
    double probability_two_pair = (calculateProbability(13, 2) * calculateProbability(4, 2) * calculateProbability(4, 2) * calculateProbability(11, 1) * calculateProbability(4, 1)) / total_combinations;
    double probability_three_of_a_kind = (calculateProbability(13, 1) * calculateProbability(4, 3) * calculateProbability(12, 2) * calculateProbability(4, 1) * calculateProbability(4, 1)) / total_combinations;
    double probability_straight = (10.0 * calculateProbability(4, 1)) / total_combinations; // Assuming Ace can be high or low
    double probability_flush = (calculateProbability(13, cards_in_hand) * calculateProbability(4, 1)) / total_combinations;
    double probability_full_house = (calculateProbability(13, 1) * calculateProbability(4, 3) * calculateProbability(12, 1) * calculateProbability(4, 2)) / total_combinations;
    double probability_four_of_a_kind = (calculateProbability(13, 1) * calculateProbability(4, 4) * calculateProbability(12, 1) * calculateProbability(4, 1)) / total_combinations;
    double probability_straight_flush = (10.0 * calculateProbability(4, 1)) / total_combinations; // Assuming Ace can be high or low
    double probability_royal_flush = (calculateProbability(4, 1)) / total_combinations;

    printf("Approximate Poker Hand Probabilities:\n");
    printf("High Card: %.5f%%\n", probability_high_card * 100);
    printf("One Pair: %.5f%%\n", probability_one_pair * 100);
    printf("Two Pair: %.5f%%\n", probability_two_pair * 100);
    printf("Three of a Kind: %.5f%%\n", probability_three_of_a_kind * 100);
    printf("Straight: %.5f%%\n", probability_straight * 100);
    printf("Flush: %.5f%%\n", probability_flush * 100);
    printf("Full House: %.5f%%\n", probability_full_house * 100);
    printf("Four of a Kind: %.5f%%\n", probability_four_of_a_kind * 100);
    printf("Straight Flush: %.5f%%\n", probability_straight_flush * 100);
    printf("Royal Flush: %.5f%%\n", probability_royal_flush * 100);

    return 0;
}
