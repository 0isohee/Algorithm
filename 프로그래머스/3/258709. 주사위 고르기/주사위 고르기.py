from itertools import combinations, product
from collections import Counter

def solution(dice):
    n = len(dice)
    max_win = -1
    answer = []

    def get_score_distribution(selected_dice):
        result = [0]
        for die in selected_dice:
            result = [x + y for x in result for y in dice[die]]
        return Counter(result)

    def count_wins(A_counter, B_counter):
        A_scores = sorted(A_counter.items())
        B_scores = sorted(B_counter.items())

        B_total = 0
        B_index = 0
        total_wins = 0
        for A_score, A_count in A_scores:
            while B_index < len(B_scores) and B_scores[B_index][0] < A_score:
                B_total += B_scores[B_index][1]
                B_index += 1
            total_wins += A_count * B_total
        return total_wins

    for A in combinations(range(n), n // 2):
        B = [i for i in range(n) if i not in A]
        A_counter = get_score_distribution(A)
        B_counter = get_score_distribution(B)
        win_count = count_wins(A_counter, B_counter)

        if win_count > max_win:
            max_win = win_count
            answer = list(A)

    return [i + 1 for i in answer]