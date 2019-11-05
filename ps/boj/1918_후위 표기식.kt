import java.util.*

// 1918번 후위 표기식
// 분류: 스택
// 문제:
//      중위 표기식으로 표현된 식을 후위 표기식으로 바꾸기
// 풀이:
//      중위 표기식을 순서대로 읽으며
//      1. A~Z일 경우 바로 식에 추가
//      2. ( 일 경우 스택에 추가
//      3. ) 일 경우 스택에 ( 가 나올 때 까지 모든 연산자를 식에 추가
//      4. 연산자일 경우 스택의 최상단 연산자가 현재 연산자의 우선 순위보다
//          낮을 경우 스택에 넣고 끝낸다.
//          높거나 같을 경우 스택의 연산자를 pop해서 식에 추가하고 반복한다.
fun main() {
    val infixNotation = readLine()!!
    val ansBuilder = StringBuilder()
    val operationStack = Stack<Char>()

    for (c in infixNotation) {
        when (c) {
            in 'A' .. 'Z' -> ansBuilder.append(c)
            '(' -> {
                operationStack.push(c)
            }
            ')' -> {
                while(operationStack.isNotEmpty()) {
                    val topOperation = operationStack.pop()
                    if (topOperation == '(')
                        break
                    else
                        ansBuilder.append(topOperation)
                }
            }
            else -> {
                // c가 연산자일 경우 스택이 빌 때 까지 비교
                while (operationStack.isNotEmpty()) {
                    if (c == '*' || c == '/') {
                        if (operationStack.peek() == '+' || operationStack.peek() == '-' || operationStack.peek() == '(') {
                            operationStack.push(c)
                            break
                        } else {
                            ansBuilder.append(operationStack.pop())
                        }
                    } else {
                        if (operationStack.peek() == '(') {
                            operationStack.push(c)
                            break
                        } else {
                            ansBuilder.append(operationStack.pop())
                        }
                    }
                }

                if (operationStack.empty())
                    operationStack.push(c)
            }
        }
    }

    while(operationStack.isNotEmpty()) {
        ansBuilder.append(operationStack.pop())
    }

    val ans = ansBuilder.toString()
    println(ans)
}
