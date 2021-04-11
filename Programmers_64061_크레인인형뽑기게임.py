def solution(board, moves):
    basket = []
    answer = 0
    for move in moves:
        for i in range(len(board)):
            if board[i][move-1] != 0:
                if len(basket) > 0:
                    if board[i][move-1] == basket[-1]:
                        basket.pop()
                        answer += 2
                        board[i][move-1] = 0
                        break
                basket.append(board[i][move-1])
                board[i][move-1] = 0
                break
    return answer