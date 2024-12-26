#!/usr/bin/python3
"""
Prime Game is a game to eliminate prime number in a list
with x rounds of game between two players.
"""

def isWinner(x, nums):
    """
    Determines the winner of a game
    where players take turns removing primes and their multiples.

    Args:
        x: The number of rounds played.
        nums: An array of integers representing
        the upper limit of the set for each round.

    Returns:
        The name of the player who wins the most rounds ("Maria" or "Ben").
        Returns "None" if the winner cannot be determined.
    """

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        primes = sieve_of_erathosthenes(n)
        winner = determine_winner(primes)
        if winner == "Maria":
            maria_wins += 1
        elif winner == "Ben":
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None


def sieve_of_erathosthenes(n):
    """
    Generates a list of prime numbers up to n using the Sieve of Eratosthenes.

    Args:
        n: The upper limit for prime number generation.

    Returns:
        A list of prime numbers up to n.
    """

    primes = [True] * (n+1)
    primes[0] = primes[1] = False
    for i in range(2, int(n**0.5) + 1):
        if primes[i]:
            for j in range(i*i, n+1, i):
                primes[j] = False
    return [i for i, is_prime in enumerate(primes) if is_prime]


def determine_winner(primes):
    """
    Determines the winner of a single round based on the list of primes.

    Args:
        primes: A list of prime numbers.

    Returns:
        "Maria" if Maria wins the round, "Ben" if Ben wins,
        or "None" if the game is a draw.
    """

    if len(primes) %2 == 0:
        return "Ben"
    else:
        return "Maria"
