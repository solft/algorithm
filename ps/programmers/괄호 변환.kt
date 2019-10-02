import java.util.*
import kotlin.collections.ArrayList

class Solution {
    fun solution(p: String): String {
        var answer = rec(p)

        return answer
    }

    fun rec(p: String): String {

        // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환
        if (p == "") {
            return ""
        }

        // 2. 문자열 p를 두 "균형잡힌 괄호 문자열" u, v로 분리
        var u = ""
        var v = ""
        var leftCounter = 0
        var rightCounter = 0

        for (c in p) {

            if (leftCounter != 0 && leftCounter == rightCounter) {
                v += c
                continue
            }

            if (c == '(')
                leftCounter++
            else if (c == ')')
                rightCounter++

            u += c
        }

        // 3. 문자열 u가 "올바른 괄호 문자열"이라면 문자열 v에 대해 1단계부터 다시 수행
        if (isComplete(u)) {
            return u + rec(v)
        } else { // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면

            // 4-1. 빈 문자열에 첫 문자로 '('를 붙임
            var temp = "("

            // 4-2. 문자열 v에 대해 1단계 부터 재귀적으로 수행한 결과 문자열을 이어 붙임
            temp += rec(v)

            // 4-3. ')'를 붙임
            temp += ")"

            // 4-4. u의 첫, 마지막 문자를 제거하고 나머지 문자열의 괄호 방향을 뒤집어서 붙임
            for (index in 1 until u.length - 1) {
                if (u[index] == '(')
                    temp += ')'
                else if (u[index] == ')')
                    temp += '('
            }

            return temp
        }
    }

    private fun isComplete(u: String): Boolean {
        val stack = ArrayList<Char>()

        for (c in u) {
            if (c == '(') {
                stack.add(c)
            } else if (c == ')'){
                if (stack.isEmpty()) {
                    return false
                } else {
                    if (stack.last() == '(') {
                        stack.removeAt(stack.lastIndex)
                    } else {
                        stack.add(c)
                    }
                }
            }
        }

        return stack.isEmpty()
    }
}

fun main() {
    val sol = Solution()
    println(sol.solution("(()())()"))
    println(sol.solution(")("))
    println(sol.solution("()))((()"))
}