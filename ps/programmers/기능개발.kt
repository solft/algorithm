// 기능개발
// 분류: 계산
// 문제:
//      일을 끝내는 날짜를 구해서
//      먼저 끝나는 순으로 몇 개가 끝나는지 개수를 나열하는 문제
// 풀이:
//      일 끝내는 날짜를 구하고
//      먼저 들어온 일부터 끝나야 하므로
//      순서대로 끝내지면 카운트 증가 시키고
//      다음에 끝나면 리스트에 새로 추가하여 푼다.
class Solution {
    fun solution(progresses: IntArray, speeds: IntArray): IntArray {
        val answer = mutableListOf<Int>()

        // 걸리는 날 ((100 - progress - 1) / speed) + 1
        val completes = IntArray(progresses.size)

        for(i in progresses.indices) {
            completes[i] = ((100 - progresses[i] - 1) / speeds[i]) + 1
        }

        answer.add(1)
        var completeDay = completes[0]
        for(i in 1 until progresses.size) {
            if (completeDay >= completes[i])
                answer[answer.lastIndex]++
            else {
                completeDay = completes[i]
                answer.add(1)
            }
        }

        return answer.toIntArray()
    }
}

fun main() {
    val sol = Solution()
    val ans = sol.solution(intArrayOf(93, 30, 55), intArrayOf(1, 30, 5))
    for (a in ans)
        println(a)
}
